#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list.h"

typedef struct queue{
    linked_list_t *element_queue;
    int start_time;
}queue_t;


queue_t get_queue();

int queue_element(queue_t *queue, void* element);

void *dequeue_element(queue_t *queue);

#endif