#include "list.h"
#include "dbg.h"
List *List_create() {
    List *list = malloc(sizeof(List));
    list->count = 0;
    check_mem(list);
error:
    return list;
}

void List_clear_val(List *list) {
    // Clear ListNode 's val
    LIST_FOREACH(list, list->first, cur, next) {
        free(cur->value);
    }
}
void List_clear_node(List *list) {
    // Clear ListNode in List
    LIST_FOREACH(list, list->first, cur, next) {
        if(cur->prev) {
            free(cur->prev);
        }
    }
    if(List_count(list) >= 1) free(list->last);
    free(list);
}
void List_clear_destroy(List *list) {
    //Clear all of ListNode
    List_clear_val(list);
    List_clear_node(list);
}
void *List_push_head(List *list, void *val) {
    ListNode *node = malloc(sizeof(ListNode));
    check_mem(node);
    node->value = val;
    node->prev = NULL;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }
    list->count++;
error:
    return;
}

void *List_push(List *list, void *val) {
    ListNode *node = malloc(sizeof(ListNode));
    check_mem(node);
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    if(list->last == NULL) {
        list->last = node;
        list->first = node;
    } else {
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
    }
    list->count++;
error:
    return;
}

void *List_pop_head(List *list) {
    return  list->first != NULL ? List_remove(list, list->first) : NULL;
}
void *List_pop(List *list) {
    return  list->last != NULL ? List_remove(list, list->last) : NULL;
}
void *List_remove(List *list, ListNode *node) {
    void *result = NULL;
    if(node == list->first && node == list->last) {
        list->last = NULL;
        list->first = NULL;
    } else if(node == list->first) {
        list->first = list->first->next;
        check(list->first,"Invalid list->first, is NULL");
        list->first->prev = NULL;
    }else if (node == list->last) {
        list->last = list->last->prev;
        check(list->last, "Invalid list->last, is NULL");
        list->last->next = NULL;
    }else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    list->count--;
    result = node->value;
    free(node);
error:
    return result;
}