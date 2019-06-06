#include <stdlib.h>
#include <stdio.h>
#include "elevator.h"

elevator_t get_elevator()
{
	elevator_t ret = (elevator_t){
        in_people: create_list(),
        current_floor: 0,
        destination: 0,
    };

    return ret;
}

void forward_time(elevator_t *elevators, int elevators_length, 
					queue_t *people_queue, int total_time)
{
	for(int i = 0; i < elevators_length; i++){
		//if the elevator has arrived to destination find the new destination
    	if(elevators[i].current_floor == elevators[i].destination)
		{
        	choose_next_destination(elevators + i, people_queue, total_time, i % 2);
    	}
	
		//if the destination is below go down otherwise go up
    	if(elevators[i].current_floor > elevators[i].destination)
		{
        	elevators[i].current_floor--;
    	} 
		else if(elevators[i].current_floor < elevators[i].destination) 
		{
        	elevators[i].current_floor++;
    	}
	}
}


void free_elevator(elevator_t *elevator)
{
    free_linked_list(elevator->in_people, free);

	//setting in_people to NULL to make sure no unallocated memory is accessed
    elevator->in_people = NULL;
}

void choose_next_destination(elevator_t *elevator, queue_t *floors,
								int total_time, int from_top_or_bottom)
{
	//array containing priorities for each floor
    int priorities[MAX_FLOOR] = {0};

	//resetted iterator since it is necessary to traverse the list
	reset_iterator(elevator->in_people);

	//iterate over all the people in the elevator
    while(iter_has_next(elevator->in_people))
	{
        person_t *person = (person_t*) move_next(elevator->in_people);

		//increase the priority of the floor where the current person wants to go
        priorities[person->destination] += total_time - person->arrival_time;
    }

	/*
		the people waiting in the floors are considered for the priority only
		if the elevator is not full
	*/
    if(elevator_load(elevator) < MAX_ELEVATOR_CAPACITY)
	{
        for(int i = 0; i < MAX_FLOOR; i++)
		{
			/*
			if the queue at the ith floor is not empty then increase the priority
			by the time the first of the queue has been waiting
			*/
			if(!queue_is_empty(floors + i))
			{
				priorities[i] += total_time - floors[i].start_time;
			}
        }
    }


    int max_priority = -1;
    int max_floor = -1;

	//i want from_top_or_bottom to be 0 or 1
	if(from_top_or_bottom != 0)
	{
	 	from_top_or_bottom = 1;	
	}

	//search for the floor with the highest priority
    for(int i = 0; i < MAX_FLOOR; i++)
	{
		/*if from_top_or_bottom == 0 then the inequality is priorities[i] > max_priority,
		this means that we are returning the first floor from the bottom that has 
		maximum priority, else if from_top_or_bottom == 1 the the inequality is
		priorities[i] >= max_priority so we are returning the first floor from 
		the top with the highest priority 
		This is useful because it sometimes prevent elevators from 
		choosing the same destination.
		*/
        if(priorities[i] > max_priority - from_top_or_bottom)
		{
            max_floor = i;
            max_priority = priorities[i];
        }
    }

    elevator->destination = max_floor;
}

void enter_people(elevator_t *elevator, queue_t *people_queue, int total_time)
{
	//while there is still space in the elevator and the queue is not empty
    while( (elevator_load(elevator) < MAX_ELEVATOR_CAPACITY) && 
           (!queue_is_empty(people_queue)) )
	{
		//dequeue a person
        person_t *person = dequeue_element(people_queue);

		//set the person arrival time in the elevator
        person->arrival_time = total_time;

		//add the person to the elevator
        add(elevator->in_people, person);

		//reset the timer of the current floor
        people_queue->start_time = total_time;
    }
}

void exit_people(elevator_t *elevator)
{
	/*
	since the list of people inside the elevator needs to be iterated through 
	the iterator is reset
	*/
	reset_iterator(elevator->in_people);

	//check all the people in the elevator if someone has arrived he can exit
    while(iter_has_next(elevator->in_people))
	{
        person_t *person = move_next(elevator->in_people);

		//if the person reached the destination remove it from the elevator
        if(person->destination == elevator->current_floor)
		{
        	remove_current_iter_node(elevator->in_people, free);
        }
    }    
}

int elevator_load(elevator_t *elevator)
{
	if(!elevator)
	{
		return FAILED_EXECUTION;
	}

    return linked_list_length(elevator->in_people);
}

char *elevator_to_string(char *elevator_string, elevator_t *elevator)
{
	//setting the string to an empty string to avoid unexpected behaviours
    elevator_string[0] = '\0';
	
	//printing the correct representation inside the elevator_string string
	sprintf(	
		elevator_string, 
		"elevator:\ncurrent floor: %d\npeople inside: %d\ndestination:%d\n\n",
		elevator->current_floor, 
		elevator_load(elevator), 
		elevator->destination
	);
	
	return elevator_string;
}
