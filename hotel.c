#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"

void person_arrives(char *command, queue_t *floors, int current_time)
{
    int arrival;
    int destination;

	//useless string used just to contain the string in the command
    char mock[MAX_INPUT_LINE_LENGTH];

	//reading arrival and destination
    sscanf(command, "%s %d %d", mock, &arrival, &destination);

	//queueing the person at the proper floor's queue
    queue_element(
		floors + arrival,
		get_person(destination, arrival, current_time),
		current_time
	);
}

void time_step_elevator(elevator_t *elevator,queue_t *floors, int total_time)
{
	//first of all the people that reached the correct destination exit the elevator
	exit_people(elevator);

	/*
	if the queue at the current floor is not empty anyone who
	can enters the elevator
	*/
    if(!queue_is_empty(floors + elevator->current_floor))
	{
        enter_people(elevator, floors + elevator->current_floor, total_time);
    }
}

void time_step(elevator_t *elevators, queue_t *floors, int total_time)
{
	//the elevators moove 
    forward_time(elevators, ELEVATORS_NUMBER, floors, total_time);

	//the elevators let the people in and out at the current floor
    time_step_elevator(elevators, floors, total_time);
    time_step_elevator(elevators + 1, floors, total_time);
}

void print_status(elevator_t *elevators, int elevators_number)
{
    printf("PRINT_STATUS:\n\n");

	//temp string that will contain the elevators infos
	char temp[MAX_ELEVATOR_STRING_LENGTH];

	for(int i = 0; i < elevators_number; i++)
	{
		printf("Elevator %d\n", i);
		printf("%s", elevator_to_string(temp, elevators + i));
	}
}


void initialize_floors(queue_t *floors)
{
    for(int i = 0; i < MAX_FLOOR; i++)
	{
        floors[i] = get_queue();
    }
}


void free_floors_queues(queue_t *floors)
{
    for(int i = 0; i < MAX_FLOOR; i++)
	{
        free_queue(floors + i, free);
    }
}
