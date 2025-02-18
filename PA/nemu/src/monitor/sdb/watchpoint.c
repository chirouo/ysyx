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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  char expr[128];//不能直接用char* expr
  uint32_t new;
  uint32_t old;
  struct watchpoint *next;
  /* TODO: Add more members if necessary */
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}
/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  if(free_ == NULL) {
    Log("watchpoints if full ! there is no free watchpoints");
    assert(0);
  }
  WP* free_node = free_;
  free_ = free_->next;
  
  free_node->next = head;
  head = free_node;
  return free_node;
}
void wp_free(WP *wp){
  wp->next = free_;
  free_ = wp;
  return;
}
void wp_diff_test(){
  Log("enter wp_diff_test");
  if(head == NULL) {
    Log("wp head == NULL");
    return;
  }
  WP* cur = head;
  bool success;
  while(cur != NULL){
    success = true;
    word_t res = expr(cur->expr, &success);
    if(!success){
      Log("Invalid expression!");
      assert(0);
    }
    cur->new = res;
    if(cur->old != cur->new) {
      Log("Watch_Point_%d is Changed! Old_Value = %u, New_Value = %u", cur->NO, cur->old, cur->new);
      cur->old = cur->new;
      nemu_state.state = NEMU_STOP;
    }
    cur = cur->next;
  }
}
void wp_watch(char* expression){
  bool success = true;
  word_t res = expr(expression, &success);
  if(!success){
    Log("Invalid expression");
    return;
  }
  WP* wp = new_wp();
  // wp->expr = expression;
  strcpy(wp->expr, expression);
  wp->new = res;
  wp->old = wp->new;
  Log("Watch_Point NO%d new successfully, value = %u, expr = %s", wp->NO, wp->new, wp->expr);
}

void wp_display(){
  if(head == NULL){
    Log("display error: all watchpoint is free, head = NULL");
    return;
  }
  WP* cur = head;
  printf("Num\tType\t\tWhat\t\tOldValue\tNewValue\n");
  while(cur != NULL && cur->expr != NULL)
  {
    printf("%d\twatchpoint\t%s\t\t%u\t\t%u\n", cur->NO, cur->expr, cur->old, cur->new);
    cur = cur->next;
  }
  // wp_diff_test();
}

void wp_delete(int no){
  if(head == NULL){
    Log("The list of watchpoints is empty");
    return;
  }
  WP* cur = head;
  WP* pre = head;
  while(cur != NULL){
    if(cur->NO == no){
      if(pre == cur){
        head = NULL;
      }else{
        pre->next = cur->next;
      }
      return wp_free(cur);
    }else {
      pre = cur;
      cur = cur->next;
    }
  }
  Log("No%d watchpoint did not exist!", no);
}

