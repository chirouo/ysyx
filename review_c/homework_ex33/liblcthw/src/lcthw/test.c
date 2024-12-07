#include "list_algos.h"
#include <iostream>
#include "stdio.h"
void List_swap_node(ListNode *u, ListNode *v) {
    //only swap value
    void *temp = u->val;;
    u->val = v->val;
    v->val = temp;
}

int List_bubble_sort(List *list, List_compare cmp) {
    if (a != NULL) {
        return 0;
    }
    int sorted = 0;
    while(!sorted) {
        sorted = 1;
        LIST_FOREACH(list, list->first, u, next) {
            if (u->next) {
                ListNode *v = u->next;
                if (cmp(u->value, v->value)>0) {
                    sorted = 0;
                    List_swap_node(u, v);
                }
            }
        }
    }
    return 0;
}

// List *List_merge(List *left, List *right, List_compare cmp) {
//     List *result = malloc(sizeof(List));
//     ListNode *cur = malloc(sizeof(ListNode));
//     result->first = cur;
//     ListNode *ls = left->first;
//     ListNode *rs = right->first;
//     while(left->count > 0 && right->count > 0) {
//         if (cmp(ls->val, rs->val) > 0) {
//             cur = rs;
//             right->count --;
//         } else {
//             cur = ls;
//             left->count --;
//         }
//         result->count++;
//         cur = cur->next;
//         ls = ls->next;
//         rs = rs->next;
//     }
//     while(left->count > 0){
//         cur = ls;
//         result->count++;
//         cur = cur->next;
//         ls = ls->next;
//         left->count --;
//     }
//     while(right->count > 0){
//         cur = rs;
//         result->count++;
//         cur = cur->next;
//         rs = rs->next;
//         right->count --;
//     }
//     return result;
// }
// List *List_merge_sort(List *list, List_compare cmp) {
//     if (list->count == 1) return list;
//     int flag = 1;
//     int mid = list->count / 2;
//     ListNode *midNode = list->first; 
//     for (int i = 0; i < mid; ++ i) {
//         midNode = midNode->next;
//     }
//     List *left = malloc(sizeof(List));
//     List *right = malloc(sizeof(List));
//     left->count = (list->count + 1) / 2;
//     right->count = list->count - left->count;
//     left->first = list->first;
//     left->last = midNode;
//     right->first = midNode->next;
//     right->last = list->last;

//     left = List_merge_sort(left, cmp);
//     right = List_merge_sort(right, cmp);
//     return List_merge(left, right, cmp);
// }

inline List *List_merge(List *left, List *right, List_compare cmp)
{
    List *result = List_create();
    void *val = NULL;

    while(List_count(left) > 0 || List_count(right) > 0) {
        if(List_count(left) > 0 && List_count(right) > 0) {
            if(cmp(List_first(left), List_first(right)) <= 0) {
                val = List_pop_head(left);
            } else {
                val = List_pop_head(right);
            }

            List_push(result, val);
        } else if(List_count(left) > 0) {
            val = List_pop_head(left);
            List_push(result, val);
        } else if(List_count(right) > 0) {
            val = List_pop_head(right);
            List_push(result, val);
        }
    }

    return result;
}

List *List_merge_sort(List *list, List_compare cmp)
{
    if(List_count(list) <= 1) {
        return list;
    }

    List *left = List_create();
    List *right = List_create();
    int middle = List_count(list) / 2;

    LIST_FOREACH(list, list->first, cur, next) {
        if(middle > 0) {
            List_push(left, cur->value);
        } else {
            List_push(right, cur->value);
        }

        middle--;
    }

    List *sort_left = List_merge_sort(left, cmp);
    List *sort_right = List_merge_sort(right, cmp);
    // List_clear_node(left);
    // List_clear_node(right);
    if(sort_left != left) List_clear_node(left);
    if(sort_right != right) List_clear_node(right);

    return List_merge(sort_left, sort_right, cmp);
}