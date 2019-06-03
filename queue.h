#ifndef QUEUE_H
#define QUEUE_H
#include "linked_list.h"

#define EXTRA_QUEUE_STRING_LENGTH 10

/*
*Queue outside floors, the values in the queue are generic
* element_queue = linked_list representing a queue
* start time = time when the button was pressed by the first person in queue
*/
typedef struct queue
{
    linked_list_t *element_queue;
    int start_time;
}
queue_t;

/*
*constructor of the queue, does not allocate dynamic memory for the queue but just
*for the linked_list element_queue
*returns a queue
*/
queue_t get_queue();

/*
*Adds an element to the queue
* queue = queue where the element is to be added
* element = element to be added to the queue
* current_time = time when the element joined the queue
* returns FAILED_EXECUTION if queue or element are NULL, CORRECT_EXECUTION otherwise
*/
int queue_element(queue_t *queue, void* element, int current_time);

/*
*dequeues the first element of the queue
* queue = queue where the first element has to be dequeued
* returns the first element of the queue, NULL if the queue is NULL or the queue is empty
*/
void *dequeue_element(queue_t *queue);

/*
*frees the memory allocated by the constructor, if queue is NULL an
*unexpected behaviour will occur
*  queue = queue where the memory has to be freed
*  free_val = function that frees the memory of one of the elements in the queue
*/
void free_queue(queue_t* queue, void free_val(void*));

/*
*Checks if the queue is empty
* queue = queue to be checked
* returns 1 if the queue is empty, 0 if it is not and FAILED_EXECUTION if queue = NULL
*/
int queue_is_empty(queue_t *queue);

/*
*Gives a string representation of the queue
* queue = queue to be represented as a string
* val_to_string = function that transform an element of the queue to a string
* 		val_string = string where the representation of the value is saved
*		val = valued to be represented
* 		returns val_string
* max_val_string_length = max length of the representation of val
* returns a pointer to some heap allocated memory containing the string representation,
* this implies that the pointer to the string needs to be freed sooner or later
*/
char *queue_to_string(queue_t *queue, char* val_to_string(char* val_string, void* val), 
					int max_val_string_length);

/*
*Function that tells the length of the queue
* queue = queue to be checked
* returns the length of the queue or FAILED_EXECUTION if queue == NULL
*/
int queue_length(queue_t *queue);

#endif
