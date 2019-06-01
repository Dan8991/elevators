#include "queue.h"


queue_t get_queue(){
    return (queue_t){
        element_queue: create_list(),
        start_time: 0,
    };
}


int queue_element(queue_t *queue, void* element){
    if(queue && element){
        add(queue->element_queue, element);
        return CORRECT_EXECUTION;
    } else {
        return FAILED_EXECUTION;
    }
}

void *dequeue_element(queue_t *queue){
    return remove_first(queue);
}

queue_t *free_queue(queue_t* queue){
    free_linked_list(queue->element_queue);
}