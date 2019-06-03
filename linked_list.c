#include "linked_list.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

linked_list_t *create_list(){

    linked_list_t *ret = malloc(sizeof(linked_list_t));
    ret->head = create_node(NULL);
    ret->tail = ret->head;
    ret->iterator = ret->head;
    ret->length = 0;
    return ret;
}

int add(linked_list_t *my_list, void* value){
    if(my_list && my_list->tail){
        my_list->tail->next = create_node(value);
        my_list->tail->next->previous = my_list->tail;
        my_list->tail = my_list->tail->next;
        my_list->length++;
    } else {
        return FAILED_EXECUTION;
    }
    reset_iterator(my_list);
    return CORRECT_EXECUTION;
}

void *remove_first(linked_list_t *my_list){
    if(my_list && my_list->head && my_list->length > 0){
        node_t *ret = my_list->head->next;
        my_list->head->next = my_list->head->next->next;
        my_list->length --;
        if(!list_is_empty(my_list)){
            my_list->head->next->previous = my_list->head;
        }else{
			my_list->tail = my_list->head;
		}
        reset_iterator(my_list);
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
            curr = next;
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
    return my_list->length == 0; 
}

void *get_current_iter_value(linked_list_t *my_list){
    return my_list->iterator->value;
}

void remove_current_iter_node(linked_list_t *my_list, void free_value(void*)){
	if(list_is_empty(my_list)){
		return;
	}
	if(!iter_has_next(my_list)){
		my_list->iterator = my_list->iterator->previous;
		free_node(my_list->tail, free_value);
		my_list->tail = my_list->iterator;
		my_list->tail->next = NULL;
		my_list->length--;
	} else if(my_list->iterator != my_list->head){
        my_list->iterator->next->previous = my_list->iterator->previous;
        my_list->iterator->previous->next = my_list->iterator->next;
        node_t * temp = my_list->iterator->previous;
        free_node(my_list->iterator, free_value);
        my_list->iterator = temp;
        my_list->length--;
    }
}

char *linked_list_to_string(char *list_string, linked_list_t *my_list, 
        char *val_to_string(char* string, void* val), int max_val_string_length)
{
    reset_iterator(my_list);
    list_string[0] = '\0';
    char temp[max_val_string_length];
    if(linked_list_length(my_list) == 0){
        return strcat(list_string, "EMPTY\n");
    }
    while(iter_has_next(my_list)){
        list_string = strcat(list_string, val_to_string(temp, move_next(my_list)));
    } 
    reset_iterator(my_list);
    return list_string;
}

int linked_list_length(linked_list_t *list){
    return list->length;
}
