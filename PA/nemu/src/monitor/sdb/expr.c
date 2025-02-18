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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
/*gx 添加paddr.h*/
#include "memory/paddr.h"
enum {
  TK_NOTYPE = 256, TK_EQ, TK_NE, TK_NUM, TK_ADDR, TK_REG, TK_AND, TK_OR, TK_NEGATIVE, TK_HEX, TK_DEREF

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"==", TK_EQ},        // equal
  {"!=", TK_NE},        // not equal
  {"^(0x)[0-9a-fA-F]+", TK_HEX}, // hex number
  {"[0-9]+", TK_NUM},   // number
  {"\\(", '('},        // left parenthesis
  {"\\)", ')'},        // right parenthesis
  {"&&", TK_AND},         // plus
  {"\\|\\|", TK_OR},         // plus
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // plus
  {"\\*", '*'},       // multiply
  {"\\/", '/'},        // divide
  {"\\%", '%'},        // modulo
  {"!", '!'},          // not
  {"\\$[$a-z0-9]{2,3}", TK_REG}       // register
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[2048] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;
  memset(tokens, 0, sizeof(tokens));
  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_EQ:
          case TK_NE:
          case TK_AND:
            tokens[nr_token].type = rules[i].token_type;
            break;
          case TK_HEX:
            tokens[nr_token].type = rules[i].token_type;
            char hex_str[32] = {};
            strncpy(hex_str, substr_start + 2, substr_len - 2);
            uint32_t decimal = strtoul(hex_str, NULL, 16);
            sprintf(tokens[nr_token].str, "%d", decimal);
            break;
          case TK_NUM:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            break;
          case TK_REG:
            bool get_reg_value = false;
            char str[12];//2^32 - 1最多是4294967295,加上\0最多11个字符
            char reg_name[4];
            strncpy(reg_name, substr_start + 1, substr_len);
            word_t reg_val = isa_reg_str2val(reg_name, &get_reg_value);
            sprintf(str, "%d", reg_val);
            tokens[nr_token].type = rules[i].token_type;
            strcpy(tokens[nr_token].str, str);
            break;
          case '!': 
            tokens[nr_token].type = rules[i].token_type;
          case TK_NOTYPE:
            nr_token --;
            break;
          case '-':
            if(nr_token == 0 || (tokens[nr_token - 1].type != TK_NUM && tokens[nr_token - 1].type != ')')){
              tokens[nr_token].type = TK_NEGATIVE;//negatie
            }else{
              tokens[nr_token].type = rules[i].token_type;
            }
            break;
          case '*':
            if(nr_token == 0 || (tokens[nr_token - 1].type != TK_NUM && tokens[nr_token - 1].type != ')')){
              tokens[nr_token].type = TK_DEREF;//dereference
            }else{
              tokens[nr_token].type = rules[i].token_type;
            }
            break;
          case '+':
          case '(':
          case ')':
          case '/':
          case '%':
            tokens[nr_token].type = rules[i].token_type;
            break;
          default: //todo();
        }
        nr_token ++ ;
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static bool check_parentheses(int p, int q) {
  static int stack[1024];
  int top = -1;
  int len = 0;
  for(int i = p; i <= q; i ++) {
    if(tokens[i].type == '(') {
      top ++;
      stack[top] = i;
    }
    if(tokens[i].type == ')') {
      if(top == -1) return false;
      if(len < i - stack[top]) len = i - stack[top];
      top --;
    }
  }
  if(top == -1 && len == q - p) return true;
  return false;
}
static int get_main_operator(int p, int q) {
  int count = 0;
  int index = 0;
  int pri = 0;
  for(int i = p; i <= q; i ++) {
    if(tokens[i].type == '('){
      count ++;
    }
    if(tokens[i].type == ')'){
      count --;
    }
    if(count == 0){
      if(tokens[i].type == TK_OR){
        if(pri <= 10){
          index = i;
          pri = 10;
        }
      }
      if(tokens[i].type == TK_AND){
        if(pri <= 9){
          index = i;
          pri = 9;
        }
      }
      if(tokens[i].type == '+' || tokens[i].type == '-') {
        if(pri <= 8){
          index = i;
          pri = 8;
        }
      }
      if(tokens[i].type == '*' || tokens[i].type == '/') {
        if(pri <= 7){
          index = i;
          pri = 7;
        }
      }
      if(tokens[i].type == '!'){
        if(pri <= 6){
          index = i;
          pri = 6;
        }
      }
      if(tokens[i].type == TK_NEGATIVE || tokens[i].type == TK_DEREF){
        if(pri <= 5){
          index = i;
          pri = 5;
        }
      }
      if(tokens[i].type == TK_EQ || tokens[i].type == TK_NE){
        if(pri <= 4){
          index = i;
          pri = 4;
        }
      }
    }
  }
  if(count != 0) return -2;
  else return index;
}

/*进入这个计算函数之前，寄存器和地址中的值都已经被计算出来了, 因此这里只有十进制的数字*/
static word_t eval(int p, int q, bool * success) {
  int result = 0;
  if (p > q) {
    /* Bad expression */
    Log("debug----expr->eval: Bad expression");
    return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    sscanf(tokens[p].str, "%d", &result);
    return result;
  }
  else if(check_parentheses(p, q)) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
      return eval(p + 1, q - 1, success);
    }else {
      word_t val1, val2;
      int op = get_main_operator(p, q);
      int op_type = tokens[op].type;
      if(op_type == '!'){
        return !eval(op + 1, q, success);
      }
      if(op_type == TK_NEGATIVE){
        val1 = -1;
        val2 = eval(op + 1, q, success);
        op_type = '*';

      }else if(op_type == TK_DEREF){
        val1 = 1;
        paddr_t address_hex = eval(op + 1, q, success);
        val2 = paddr_read(address_hex, 4);
        op_type = '*';
      }
      else{
        val1 = eval(p, op - 1, success);
        val2 = eval(op + 1, q, success);
      }
      if(op == -2) {
        *success = false;
        Log("debug----expr->eval: parentheses didnt == 2x");
        assert(0);
      }
      printf("val1 = %d, val2 = %d\n", val1, val2);
      
      switch (op_type) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': 
          if (val2 == 0) {
            *success = false;
            Log("debug----expr->eval: divide by zero");
            assert(0);
          }
          return val1 / val2;
        case TK_AND: return val1 && val2;
        case TK_OR: return val1 || val2;
        case TK_EQ: 
          Log("debug----expr->eval: TK_EQ");
          return val1 == val2 ? 1 : 0;
        case TK_NE:
          Log("debug----expr->eval: TK_NE");
          return val1 != val2 ? 1 : 0;
        default:  *success = false; Log("debug----expr->eval: switch tokens[op].type error"); assert(0);
      }
    }
}
word_t expr(char *e, bool* success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  /* TODO: Insert codes to evaluate the expression. */
  //TODO();
  word_t expr_ans = eval(0, nr_token - 1, success);
  if(*success == false) {
    assert(0);
  }
  // free(success);
  return expr_ans;
}
