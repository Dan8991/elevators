#include "linked_list.h"
#include "node.h"
#include <stdlib.h>

linked_list_t *create_list(){

    linked_list_t *ret = malloc(sizeof(linked_list_t));
    ret->head = create_node(NULL);
    ret->tail = ret->head;
    ret->iterator = ret->head;
    return ret;
}

int add(linked_list_t *my_list, void* value){
    if(my_list && my_list->tail){
        my_list->tail->next = create_node(value);
        my_list->tail = my_list->tail->next;
    } else if(my_list){
        my_list->head = create_node(value);
        my_list->tail = my_list->head;
    } else {
        return FAILED_EXECUTION;
    }
    return CORRECT_EXECUTION;
}

int remove_all(linked_list_t *my_list, int eliminate(void* value), void free_val(void*)){
    if(my_list && my_list->head->next){
        node_t *curr_node = my_list->head->next;
        node_t *prev_node = my_list->head;
        int removed = 0;
        while(curr_node){
            if(eliminate(curr_node->value)){
                prev_node->next = curr_node->next;
                free_node(curr_node, free_val);
                curr_node = prev_node->next;
                removed ++;
            }else{
                curr_node = curr_node->next;
                prev_node = prev_node->next;
            }
        }
        return removed;
    } else {
        return FAILED_EXECUTION;
    }
}

void *remove_first(linked_list_t *my_list){
    if(my_list && my_list->head){
        node_t *ret = my_list->head->next;
        my_list->head->next = my_list->head->next->next;
        return ret->value;
    } else {
        return NULL;
    }
}

linked_list_t *free_linked_list(linked_list_t *my_list, void remove_val(void*)){
    if(my_list){
        node_t *curr = my_list->head->next;
        free_node(my_list->head, NULL);

        while(curr){
            node_t *next = curr->next;
            free_node(curr, remove_val);
        } 
    }
    return NULL;
}

void* move_next(linked_list_t *my_list){
    if(my_list && my_list->iterator){
        my_list->iterator = my_list->iterator->next;
        void *val = my_list->iterator->value;
        return val;
    }
    return NULL;
}

int reset_iterator(linked_list_t *my_list){
    if(my_list){
        my_list->iterator = my_list->head;
        return 1;
    } else {
        return FAILED_EXECUTION;
    }
}

int iter_has_next(linked_list_t *my_list){
    if(my_list){
        return my_list->iterator->next != NULL;
    } else {
        return FAILED_EXECUTION;
    }
}

int list_is_empty(linked_list_t *my_list){
    return my_list->head == my_list->tail;
}