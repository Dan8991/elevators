#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "pbl/src/src/pbl.h"
#include "persona.h"

typedef struct elevator{
    person_t *in_people; 
    person_t *wait_people;
    int current_floor;
}elevator_t;

elevator_t get_elevator();

void forward_time();

#endif