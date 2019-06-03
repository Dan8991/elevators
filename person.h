#ifndef PERSONA_H
#define PERSONA_H

#include "linked_list.h"
#include "node.h"

/*
*struct representing a person that can queue to wait
*for an elevator and can enter the elevator
* destination = floor that the person wants to reach with the elevator
* emulates the button pressed by the person when entering the elevator
* arrival = floor where the person queues for the elevator
* arrival_time = time when the person entered the elevator
*/
typedef struct person
{
   int destination;
   int arrival;
   int arrival_time;
}
person_t;

/*
*constructor for a person, it allocates memory with malloc, this memory thus needs
*to be freed
* destination = floor that the person wants to reach with the elevator
* emulates the button pressed by the person when entering the elevator
* arrival = floor where the person queues for the elevator
* arrival_time = time when the person entered the elevator
* returns a pointer to a person structure
*/
person_t *get_person(int destination, int arrival, int arrival_time);

/*
*Function that sets the arrival_time of a person in the elevator
* person = person whoose arrival_time needs to be changed
* arrival_time = new arrival_time
*/
void set_arrival_time(person_t *person, int arrival_time);

#endif
