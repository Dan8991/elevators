#include "queue.h"
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

void *dequeue_element(queue_t *queue){
    return remove_first(queue->element_queue);
}

queue_t *free_queue(queue_t* queue){
    free_linked_list(queue->element_queue, free);
    return NULL;
}

char *queue_to_string(queue_t *queue, char* val_to_string(char* val_string, void* val), int max_val_string_length)
{
    char *list_string = malloc(sizeof(char)*(
            EXTRA_QUEUE_STRING_LENGTH + max_val_string_length * queue->element_queue->length
        ));
    list_string = linked_list_to_string(list_string, queue->element_queue, val_to_string, max_val_string_length);
    char temp[EXTRA_QUEUE_STRING_LENGTH];
    sprintf(temp, "length:%d\n", queue->element_queue->length);
    return strcat(list_string, temp);
}

int queue_is_empty(queue_t *queue){
    return list_is_empty(queue->element_queue);
}