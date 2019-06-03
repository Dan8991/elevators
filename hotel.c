#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#include "queue.h"
#include "elevator.h"

void person_arrives(char *string, queue_t *floors, int current_time){
    int arrival;
    int destination;
    char mock[MAX_INPUT_LINE_LENGTH];
    sscanf(string, "%s %d %d", mock, &arrival, &destination);
    queue_element(floors + arrival, get_person(destination, arrival, current_time), current_time);
}

void time_step_elevator(elevator_t *elevator,queue_t *floors, int total_time){
	exit_people(elevator);
    if(!queue_is_empty(floors + elevator->current_floor)){
        enter_people(elevator, floors + elevator->current_floor, total_time);
    }
}

void time_step(elevator_t *elevators, queue_t *floors, int total_time){
    time_step_elevator(elevators, floors, total_time);
    time_step_elevator(elevators + 1, floors, total_time);
    forward_time(elevators, floors, total_time);
    forward_time(elevators + 1, floors, total_time);
}

void print_status(elevator_t *elevators, queue_t* floors){
    printf("PRINT_STATUS:\n\n");
	char temp[MAX_ELEVATOR_STRING_LENGTH];
	print_info(elevator_to_string(temp, elevators));
	print_info(elevator_to_string(temp, elevators + 1));
}


void initialize_floors(queue_t *floors){
    for(int i = 0; i < MAX_FLOOR; i++){
        floors[i] = get_queue();
    }
}
