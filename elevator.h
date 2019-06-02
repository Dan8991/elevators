#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "person.h"
#include "linked_list.h"
#include "node.h"
#include "queue.h"

#define MAX_ELEVATOR_CAPACITY 12
#define MAX_FLOOR 20

typedef struct elevator{
    linked_list_t *in_people; 
    int *wait_people;
    int current_floor;
    int destination;
    int total_time;
}elevator_t;

elevator_t get_elevator();

void forward_time(elevator_t *elevator, queue_t *queue);

void choose_next_destination(elevator_t *elevator, queue_t *floors);

void enter_people(elevator_t *elevator, queue_t *people_queue);

void exit_people(elevator_t *elevator);

elevator_t *free_elevator(elevator_t *elevator);

#endif