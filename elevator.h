#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "pbl/src/src/pbl.h"
#include "person.h"

#define MAX_ELEVATOR_CAPACITY 12

typedef struct elevator{
    person_t *in_people; 
    int in_people_number;
    person_t *wait_people;
    int current_floor;
    int destination;
}elevator_t;

elevator_t get_elevator();

void forward_time(elevator_t *elevator);

void choose_next_destination(elevator_t *elevator);

#endif