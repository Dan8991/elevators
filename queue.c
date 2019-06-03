#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


queue_t get_queue(){
    return (queue_t){
        element_queue: create_list(),
        start_time: 0,
    };
}


int queue_element(queue_t *queue, void* element, int current_time){
    if(queue && element){
        if(queue_is_empty(queue)){
            queue->start_time = current_time;
        }
        add(queue->element_queue, element);
        return CORRECT_EXECUTION;
    } else {
        return FAILED_EXECUTION;
    }
}

void *dequeue_element(queue_t *queue)
{
	if(!queue)
	{
		return NULL;
	}

    return remove_first(queue->element_queue);
}

void free_queue(queue_t* queue, void free_val(void*))
{
    free_linked_list(queue->element_queue, free_val);
}

char *queue_to_string(queue_t *queue, char* val_to_string(char* val_string, void* val), int max_val_string_length)
{
    char *list_string = malloc(sizeof(char)*(
            EXTRA_QUEUE_STRING_LENGTH + max_val_string_length * queue_length(queue) 
        ));
    list_string = linked_list_to_string(list_string, queue->element_queue, val_to_string, max_val_string_length);
    char temp[EXTRA_QUEUE_STRING_LENGTH];
    sprintf(temp, "length:%d\n", queue_length(queue));
    return strcat(list_string, temp);
}

int queue_is_empty(queue_t *queue)
{
	if(!queue)
	{
		return FAILED_EXECUTION;
	}

    return list_is_empty(queue->element_queue);
}

int queue_length(queue_t *queue){

	if(!queue)
	{
		return FAILED_EXECUTION;
	}

    return linked_list_length(queue->element_queue);
}
