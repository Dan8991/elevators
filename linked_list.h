#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

#define FAILED_EXECUTION 0 
#define CORRECT_EXECUTION 1

typedef struct linked_list{
    node_t *head;
    node_t *tail;
    node_t *iterator;
}linked_list_t;

linked_list_t *create_list();

int add(linked_list_t *list, void* value);

int remove_all(linked_list_t *my_list, int eliminate(void* value), void free_val(void*));

node_t *remove_first(linked_list_t *my_list);

linked_list_t *free_linked_list(linked_list_t *my_list, void remove_val(void*));

void* move_next(linked_list_t *my_list);

int reset_iterator(linked_list_t *my_list);

int iter_has_next(linked_list_t *my_list);



#endif