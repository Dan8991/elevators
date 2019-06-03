#ifndef HOTEL_H
#define HOTEL_H
#include "queue.h"
#include "elevator.h"

#define PRINT_STATUS "PRINT_STATUS" 
#define TIME_STEP "TIME_STEP" 

//max length of a single command
#define MAX_INPUT_LINE_LENGTH 23

/*
*Function that handles the arrival of a new person
* command = command from the input file
* floors = array of the queues for every floors
* current_time = time passed since the beginning
*/
void person_arrives(char *command, queue_t *floors, int current_time);

/*
*Function that handles a time_step
* elevators = array of the elevators in the hotel
* floors = array of queues at the various floors
* time_passed = time passed since the beginning
*/
void time_step(elevator_t *elevators, queue_t *floors, int time_passed);

/*
*function that prints the status of the hotel
* elevators = array that contains the two elevators
*/
void print_status(elevator_t *elvators);

/*
*Function that initializes the queues for each floor
* floors = array of queues
*/
void initialize_floors(queue_t *floors);

#endif
