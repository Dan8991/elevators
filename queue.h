#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list.h"

#define EXTRA_QUEUE_STRING_LENGTH 10

typedef struct queue{
    linked_list_t *element_queue;
    int start_time;
}queue_t;


queue_t get_queue();

int queue_element(queue_t *queue, void* element);

void *dequeue_element(queue_t *queue);

queue_t *free_queue(queue_t* queue);

int queue_is_empty(queue_t *queue);

char *queue_to_string(queue_t *queue, char* val_to_string(char* val_string, void* val), int max_val_string_length);

#endif