#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "elevator.h"
#include "queue.h"
#include "hotel.h"

int main(int argv, char **argc){

    FILE *input_file = fopen(argc[1], "r");
    char command[MAX_INPUT_LINE_LENGTH]; 
    int current_time = 0;
    queue_t floors[MAX_FLOOR];
    elevator_t elevators[2];
    elevators[0] = get_elevator();
    elevators[1] = get_elevator();
    initialize_floors(floors);
    

    while(fgets(command, MAX_INPUT_LINE_LENGTH, input_file)){
        char base_command[MAX_INPUT_LINE_LENGTH];
        sscanf(command, "%s", base_command);
        if(strcmp(base_command, PRINT_STATUS) == 0){
            print_status(elevators, floors);
        } else if(strcmp(base_command, "TIME_STEP") == 0){
            current_time++;
            time_step(elevators, floors, current_time);
        } else {
            person_arrives(command, floors, current_time);
        }
    }
}