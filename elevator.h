#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "person.h"
#include "queue.h"

//maximum number of persons in the elevator
#define MAX_ELEVATOR_CAPACITY 12

//maximum numer of floors in the hotel
#define MAX_FLOOR 20

//extra characters needed for the to_string function
#define MAX_ELEVATOR_STRING_LENGTH 100

#define DOWN_TO_UP_PRIORITY 0

/*
*Structure representing an elevator
* in_people = list of people inside the elevator
* current_floor = floor where the elevator is at the moment
* destination = destination of the elevator
*/
typedef struct elevator
{
    linked_list_t *in_people; 
    int current_floor;
    int destination;
}
elevator_t;

/*
*constructor of the elevator returns an elevator by value
* returns an elevator the only allocated memory in there is the one in the linked
* list and it needs to be freed.
*/
elevator_t get_elevator();

/*
*Function that tells the elevator to make a step in time
* elevators = array of elevators that need to make a time step
* elevators_num = length of elevators
* queue = array of queues representing the queues at every floor
* total_time = time passed since the beginning 
*/
void forward_time(elevator_t *elevators, int elevators_length, 
					queue_t *queue, int total_time);

/*
*function that sets the destination of the elevator to its new value.
*The value is computed by considering how much people have been waiting 
*the elevator in a queue, how long people have been waiting inside the
*elevator and how many people want to go to a certain floor
* elevator = elevator to which the new destination has to be assigned
* floors = array of queues representing the queues at every floor
* total_time = time passed since the beginning
* priority = can be 0 or non zero, if zero then the lowest floor with highest
* priority is set as the destination, if non zero then the highest floor with 
* highest priority is set as the destination
*/
void choose_next_destination(elevator_t *elevator, 
			queue_t *floors, int total_time, int from_top_or_bottom);

/*
*Functions that lets the people in the current_floor enter the elevator
*until the elevator is full or the queue is empty
* elevator = elevator where the people are going to enter
* people_queue = queue of people at the current floor 
* total_time = time passed since the beginning
*/
void enter_people(elevator_t *elevator, queue_t *people_queue, int total_time);

/*
*Function that lets all the people that reached their destination exit the elevator
* elevator = elevator where the people are waiting to reach the correct floor
*/
void exit_people(elevator_t *elevator);

/*Frees all the memory allocated by the constructor if elevator is NULL 
* SEGMENTATION FAULT will most likely occur but some unexpected behaviour can 
* happen as well
* elevator = elevator that contains the memory to be freed
*/
void free_elevator(elevator_t *elevator);

/*
*Function that tells how many people are in the elevator
* elevator = elevator where the people are waiting
* returns the number of people in the elevator or FAILED_EXECUTION if elevator 
* is null
*/
int elevator_load(elevator_t *elevator);

/*
*Computes a string representation of the elevator
* elevator_string = string that will contain the representation
* elevator = elevator to be represented as a string
* returns elevator_string
*/
char *elevator_to_string(char *elevator_string, elevator_t *elevator);

#endif
