/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state=NEMU_QUIT;
  return -1;
}

static int cmd_si(char *args){
  if (args == NULL) args = "1";
  int step = atoi(args);
  Log("debug ---------- '%s'\n", args);
  cpu_exec(step);
  return 0;
}
static int cmd_info(char *args){
  char *subcmd = args;
  Log("debug ---------- '%s'\n", subcmd);
  if (strcmp(subcmd,"r")==0){
    isa_reg_display();
  }else if (strcmp(subcmd,"w")==0){
    // isa_wp_display();
  }
  return 0;
}
static int cmd_x(char *args){
  char *n = strtok(args, " ");
  char *expr = n + strlen(n) + 1;
  uint32_t addr = 0;
  sscanf(expr+2,"%x",&addr);
  Log("debug ---------- n: '%s'\n", n);
  Log("debug ---------- expr: '%s'\n", expr);
  Log("debug ---------- addr: '0x%x'\n", addr);
  int num_n = atoi(n);
  printf("0x%x:", addr);
  int addr_to_read = 0;
  for(int i = 0; i < num_n; i ++){
    addr_to_read = addr + i * 4;
    printf("0x%-10x", paddr_read(addr_to_read, 4));
  }
  printf("\n");
  return 0;
}
static int cmd_p(char *args){
  char *expr_str = args;
  Log("debug ---------- '%s'\n", expr_str);
  bool success = true;
  word_t result = expr(expr_str, &success);
  if(success == false) {
    Log("debug ---------- '%s' is not a valid expression\n", expr_str);
    return 0;
  }
  printf("%s\t=\t%d\n", expr_str, result);
  // for(int i = 0; i < nr_token; i ++) {
  //   printf("number %d token\ttoken_type%d\ttoken_str:%s\n", i, tokens[i].type, tokens[i].str);
  // }
  return 0;
}
static int cmd_w(char *args){
  char *expr = args;
  Log("debug ---------- '%s'\n", expr);
  return 0;
}
static int cmd_d(char *args){
  char *n = args;
  Log("debug ---------- '%s'\n", n);
  return 0;
}
static int cmd_set_reg(char *args){
  word_t val = 0;
  char *n = strtok(args, " ");
  char *val_str = n + strlen(n) + 1;
  sscanf(val_str, "%d", &val);
  Log("debug ---------- '%s'\n", n);
  bool success = false;
  isa_reg_str2val(n, &success);
  if(success) {
    set_reg_value(n, val);
  }
  return 0;
}
static int cmd_help(char *args);


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si","Step any instruction",cmd_si},
  {"info","Display register or watchpoint",cmd_info},
  {"x","Display N bytes of memory beginning at address $expr",cmd_x},
  {"p","Print the value of $expr",cmd_p},
  {"w","Stop program when $expr is changed",cmd_w},
  {"d","Delete watchpoint $N",cmd_d},
  {"sr","Set the value of $reg",cmd_set_reg}
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }
    Log("debug ---------- '%s'\n", cmd);

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { 
            return; 
        }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
