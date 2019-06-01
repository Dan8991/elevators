#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #include "person.h"
// #include "elevator.h"

#define PRINT_STATUS "PRINT_STATUS" 
#define TIME_STEP "TIME_STEP" 
#define MAX_INPUT_LINE_LENGTH 21 

void print_status(){
    printf(PRINT_STATUS);
    printf("\n");
}

void time_step(){
    printf(TIME_STEP);
    printf("\n");
}

void person_arrives(char *string){
    int arrival;
    int destination;
    char mock[MAX_INPUT_LINE_LENGTH];
    sscanf(string, "%s %d %d", mock, &arrival, &destination);
    printf("%d %d\n", arrival, destination);
}

int main(int argv, char **argc){
    FILE *input_file = fopen(argc[1], "r");
    char command[MAX_INPUT_LINE_LENGTH]; 
    while(fgets(command, MAX_INPUT_LINE_LENGTH, input_file)){
        char base_command[MAX_INPUT_LINE_LENGTH];
        sscanf(command, "%s", base_command);
        if(strcmp(base_command, PRINT_STATUS) == 0){
            print_status();
        } else if(strcmp(base_command, "TIME_STEP") == 0){
            time_step();
        } else {
            person_arrives(command);
        }
    }
}