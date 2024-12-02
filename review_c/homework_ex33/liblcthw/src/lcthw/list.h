#ifndef _lcthw_List_h
#define _lcthw_List_h
#include <stdlib.h>
typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;
typedef struct List
{
    int count;
    ListNode *first;
    ListNode *last; 
} List;

#define List_count(A) (A->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) (A->last != NULL ? A->last->value : NULL)

List *List_create();
void List_clear_val(List *list);    // Clear ListNode 's val
void List_clear_node(List *list);  // Clear ListNode in List
void List_clear_destroy (List *list);    //Clear all of ListNode


//add
void *List_push_head(List *list, void *val);
void *List_push(List *list, void *val);

//delete
void *List_pop_head(List *list);
void *List_pop(List *list);
void *List_remove(List *list, ListNode *node);

//TODO: modify
//TODO: find

//正向遍历
#define LIST_FOREACH(LIST, START, V, next) for (ListNode *V = START; V != NULL; V = V->next)
#endif