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

void time_step_elevator(elevator_t *elevator,queue_t *floors, int time){
    if(!queue_is_empty(floors + elevator->current_floor)){
        enter_people(elevator, floors + elevator->current_floor);
    }
}

void time_step(elevator_t *elevators, queue_t *floors, int time){
    time_step_elevator(elevators, floors, time);
    time_step_elevator(elevators + 1, floors, time);
    forward_time(elevators, floors);
    forward_time(elevators + 1, floors);
}

void print_status(elevator_t *elevators, queue_t* floors){
    printf("PRINT_STATUS:\n\n");
    char elevator_string[MAX_ELEVATOR_CAPACITY * MAX_PERSON_STRING_LENGTH + MAX_ELEVATOR_EXTRA_STRING_LENGTH];
    printf("%s\n", elevator_to_string(elevator_string, elevators));
    printf("%s\n", elevator_to_string(elevator_string, elevators + 1));
    for(int i = 0; i < MAX_FLOOR; i++){
        char *floors_string = queue_to_string(floors + i, person_to_string, MAX_PERSON_STRING_LENGTH);
        printf("floor #%d:\n%s\n", i, floors_string);
        free(floors_string);
    }
}

void initialize_floors(queue_t *floors){
    for(int i = 0; i < MAX_FLOOR; i++){
        floors[i] = get_queue();
    }
}