#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "elevator.h"

#define MAX_INPUT_LINE_LENGTH 20

int main(int argv, char **argc){
    FILE *input_file = fopen(argc[1], "r");
    char command[MAX_INPUT_LINE_LENGTH]; 
    while(!fscanf(input_file, "%s", command)){
        printf("%s", command);
    }
}