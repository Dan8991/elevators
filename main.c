#include <string.h>
#include <stdio.h>
#include "elevator.h"
#include "queue.h"
#include "hotel.h"

int main(int argv, char **argc){

	//input file where the commands can be found
    FILE *input_file = fopen(argc[1], "r");

	//temp string that will contain the command found in one of the lines in the file
    char command[MAX_INPUT_LINE_LENGTH]; 

	//system time
    int current_time = 0;

	//array of queues for each floor
    queue_t floors[MAX_FLOOR];

	//array of elevators in the hotel
    elevator_t elevators[2];

	//initializing elevators and floors queues
    elevators[0] = get_elevator();
    elevators[1] = get_elevator();
    initialize_floors(floors);

	//TODO second elevator follows first until it is full

    while(fgets(command, MAX_INPUT_LINE_LENGTH, input_file))
	{
		//temp string containing the line
        char base_command[MAX_INPUT_LINE_LENGTH];

		//extracting the command alone from the line
        sscanf(command, "%s", base_command);

		//execute a different function for each of the three different commands
        if(strcmp(base_command, PRINT_STATUS) == 0)
		{
            print_status(elevators);
        } 
		else if(strcmp(base_command, "TIME_STEP") == 0)
		{
            current_time++;
            time_step(elevators, floors, current_time);
        } 
		else
		{
            person_arrives(command, floors, current_time);
        }
		
    }

	//freeing memory
    fclose(input_file);
    free_elevator(elevators + 1);
    free_elevator(elevators);
	free_floors_queues(floors);
}
