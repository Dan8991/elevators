#include "linked_list.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


linked_list_t *create_list()
{
    linked_list_t *ret = malloc(sizeof(linked_list_t));

    ret->head = create_node(NULL);
    ret->tail = ret->head;
    ret->iterator = ret->head;
    ret->length = 0;

    return ret;
}


int add(linked_list_t *my_list, void* value)
{
    if(my_list && my_list->tail)
	{
		//creating new node
        my_list->tail->next = create_node(value);

		//connecting the node with the list
        my_list->tail->next->previous = my_list->tail;

		//mooving the tail to the new tail
        my_list->tail = my_list->tail->next;

        my_list->length++;
    }
	else 
	{
        return FAILED_EXECUTION;
    }
	
	//resetting the iterator to prevent strange behaviours
    reset_iterator(my_list);

    return CORRECT_EXECUTION;
}

void *remove_first(linked_list_t *my_list)
{
    if( (my_list) && (my_list->head) && (my_list->length > 0))
	{
        node_t *to_be_removed = my_list->head->next;
		void *ret_val = ret->value;

		//removing the first node
        my_list->head->next = my_list->head->next->next;
        my_list->length --;

		/*
		if the list is not empty: connect the first node to the other nodes
		else: move the tail back to the head since the node it was pointing
		at doesn't exist anymore
		*/
        if(!list_is_empty(my_list))
		{
            my_list->head->next->previous = my_list->head;
        }
		else
		{
			my_list->tail = my_list->head;
		}

		//reset iterator to prevent strange behaviours
        reset_iterator(my_list);

		//frees the removed node
		free(to_be_removed);
        return ret_val; 
    }
	else 
	{
        return NULL;
    }
}

linked_list_t *free_linked_list(linked_list_t *my_list, void remove_val(void*))
{
    if(!my_list)
	{
		return NULL
	}

	node_t *curr = my_list->head->next;
	//freeing the head that has no value in it 
    free_node(my_list->head, NULL);

	//for every node freeing the space allocated for the value and for the node
    while(curr)
	{
    	node_t *next = curr->next;
        free_node(curr, remove_val);
        curr = next;
    } 

	free(my_list);
}

void* move_next(linked_list_t *my_list)
{
    if(my_list && my_list->iterator)
	{
		//mooving the iterator forward
        my_list->iterator = my_list->iterator->next;

        return my_list->iterator->value;
    }

    return NULL;
}

int reset_iterator(linked_list_t *my_list)
{
    if(my_list)
	{
		//sending the iterator at the beginning of the list
        my_list->iterator = my_list->head;
        return CORRECT_EXECUTION;
    }
	else
	{
        return FAILED_EXECUTION;
    }
}

int iter_has_next(linked_list_t *my_list)
{
    if(my_list)
	{
        return my_list->iterator->next != NULL;
    }
	else 
	{
        return FAILED_EXECUTION;
    }
}

int list_is_empty(linked_list_t *my_list)
{
	if(my_list)
	{
    	return my_list->length == 0; 
	}
	else 
	{
		return FAILED_EXECUTION;
	}
}

void *get_current_iter_value(linked_list_t *my_list)
{
	if(my_list)
	{
		return my_list->iterator->value;
	}
	else
	{
		return NULL;
	}
}

int remove_current_iter_node(linked_list_t *my_list, void free_value(void*))
{
	/*
	execution fails if the list is empty or if the iterator is still
	pointing to the head that is just an empty node
	*/
	if( (list_is_empty(my_list)) || (my_list->iterator == my_list->head))
	{
		return FAILED_EXECUTION;
	}

	if(!iter_has_next(my_list))
	{
		//enters here only if the node to be deleted is the last one

		//mooves the iterator backwards so if next is called no node is skipped
		my_list->iterator = my_list->iterator->previous;

		free_node(my_list->tail, free_value);

		//fixes the tail of the list
		my_list->tail = my_list->iterator;
		my_list->tail->next = NULL;

		my_list->length--;
	}
	else
	{
		//removes the node and fixes connections in the list
        my_list->iterator->next->previous = my_list->iterator->previous;
        my_list->iterator->previous->next = my_list->iterator->next;

        node_t * temp = my_list->iterator->previous;

		//freeing memory from the deleted node
        free_node(my_list->iterator, free_value);

        my_list->iterator = temp;
        my_list->length--;
    }

	return CORRECT_EXECUTION;
}

char *linked_list_to_string(char *list_string, linked_list_t *my_list, 
        char *val_to_string(char* string, void* val), int max_val_string_length)
{

	if(!my_list)
	{
		return NULL;
	}

	//since the iterator is used to print the list it is resetted
    reset_iterator(my_list);

	//sets the string to an empty string to avoid unexpected behaviours
    list_string[0] = '\0';

	//temp string containing the string representation of the node
    char temp[max_val_string_length];
	
	//if the list is empty then EMPTY is returned
    if(linked_list_length(my_list) == 0)
	{
        return strcat(list_string, "EMPTY\n");
    }

	//concatenates all the representations of the values of the nodes
    while(iter_has_next(my_list))
	{
        list_string = strcat(list_string, val_to_string(temp, move_next(my_list)));
    } 

	//since the iterator was used it is resetted again
    reset_iterator(my_list);

    return list_string;
}

int linked_list_length(linked_list_t *list)
{
	if(list)
	{
    	return list->length;
	}
	else
	{
	 	return FAILED_EXECUTION;
	}
}
