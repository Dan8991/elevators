#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

#define FAILED_EXECUTION 0 
#define CORRECT_EXECUTION 1

typedef struct linked_list{
    node_t *head;
    node_t *tail;
    node_t *iterator;
    int length;
}linked_list_t;

linked_list_t *create_list();

int add(linked_list_t *list, void* value);

int remove_all(linked_list_t *my_list, int eliminate(void* value), void free_val(void*));

void *remove_first(linked_list_t *my_list);

linked_list_t *free_linked_list(linked_list_t *my_list, void remove_val(void*));

void* move_next(linked_list_t *my_list);

int reset_iterator(linked_list_t *my_list);

int iter_has_next(linked_list_t *my_list);

int list_is_empty(linked_list_t *my_list);

void *get_current_iter_value(linked_list_t *my_list);

int linked_list_length(linked_list_t *my_list);

void remove_current_iter_node(linked_list_t *my_list, void free_value(void*));

char *linked_list_to_string(char* list_string, linked_list_t *list,
        char *val_to_string(char* val_string, void* val),int max_val_string_length);
#endif