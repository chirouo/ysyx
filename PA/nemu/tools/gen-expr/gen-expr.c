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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};

static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
static char* buf_start = NULL;
static char* buf_end = buf+(sizeof(buf)/sizeof(buf[0]));
static int choose(int n) {
  return rand() % n;
}
// static void gen_space() {
//   int size = choose(4);
//   if (buf_start < buf_end) {
//     int used = snprintf(buf_start, buf_end-buf_start, "%*s", size, "");
//     if (used > 0) {
//       buf_start += used;
//     }
//   }
// }
static void gen_char(char c) {
  int used = snprintf(buf_start, buf_end - buf_start, "%c", c);
  if(buf_start < buf_end){
    if(used > 0){
      buf_start += used;
    }
  }
}
static void gen_num() {
  int num = choose(INT8_MAX);
  if(buf_start < buf_end){
    int used = snprintf(buf_start, buf_end - buf_start, "%d", num);
    if(used > 0){
      buf_start += used;
      // printf("used = %d\tnum = %d\n", used, num);
    }else {
      // printf("error --- num = %d, used = %d\n", num, used);
    }
  }
}
static char ops[] = {'+', '-', '*', '/'};
static void gen_rand_op() {
  int op_index = choose(sizeof(ops));
  char op = ops[op_index];
  gen_char(op);
}
static void gen_rand_expr() {
  switch (choose(3)) {
    case 0: gen_num(); break;
    case 1: gen_char('('); gen_rand_expr(); gen_char(')'); break;
    default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
      buf_start = buf;
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Wall -Werror -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    uint64_t result;
    ret = fscanf(fp, "%lu", &result);
    pclose(fp);

    printf("%lu %s\n", result, buf);
  }
  return 0;
}
