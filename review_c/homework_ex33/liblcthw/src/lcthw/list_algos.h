#ifndef _list_algos_
#define _list_algos_
#include "list.h"
typedef int (*List_compare)(void *a, void *b);
List *List_merge_sort(List *list, List_compare cmp);
int List_bubble_sort(List *list, List_compare cmp);
#endif