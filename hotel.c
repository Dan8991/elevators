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

void time_step(){
    printf(TIME_STEP);
    printf("\n");
}

void print_status(queue_t* floors){
    for(int i = 0; i < MAX_FLOOR; i++){
        char *floors_string = queue_to_string(floors + i, person_to_string, MAX_PERSON_STRING_LENGTH);
        printf("%s", floors_string);
        free(floors_string);
    }
}

void initialize_floors(queue_t *floors){
    for(int i = 0; i < MAX_FLOOR; i++){
        floors[i] = get_queue();
    }
}