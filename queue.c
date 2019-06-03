#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


queue_t get_queue()
{
	//initializing an empty queue	
	queue_t ret = (queue_t)
	{
        element_queue: create_list(),
        start_time: 0,
    };

    return ret;
}


int queue_element(queue_t *queue, void* element, int current_time)
{
	//checking if the arguments are ok
	if( (!queue) || (!element) )
	{
		return FAILED_EXECUTION;
	}

	//if noone was in queue the new arrived presses the button
    if(queue_is_empty(queue))
	{
        queue->start_time = current_time;
    }
	
	//adding element to the queue
    add(queue->element_queue, element);

    return CORRECT_EXECUTION;
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

char *queue_to_string(queue_t *queue, char* val_to_string(char* val_string, void* val), 
				int max_val_string_length)
{
	/*
		string to be returned, contains queue.length values and some extra
		EXTRA_QUEUE_STRING_LENGTH characters
	*/
    char *list_string = malloc(
		sizeof(char)*(
            EXTRA_QUEUE_STRING_LENGTH + max_val_string_length * queue_length(queue) 
    	)
	);

	//first of all assigning the representation of the linked list
    list_string = linked_list_to_string(list_string, queue->element_queue, 
					val_to_string, max_val_string_length);
	
	//extra characters containing the length of the queue
    char temp[EXTRA_QUEUE_STRING_LENGTH];

	//putting the length in the temp variable
    sprintf(temp, "length:%d\n", queue_length(queue));

	//returning the linked list representation concatenated with the length of the queue
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
