#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "elevator.h"
#include "linked_list.h"
#include "node.h"
#include "queue.h"

elevator_t get_elevator(){
    return (elevator_t){
        in_people: create_list(),
        current_floor: 0,
        destination: 0,
    };
}

void forward_time(elevator_t *elevator, queue_t *people_queue, int total_time){
    if(elevator->current_floor == elevator->destination){
        choose_next_destination(elevator, people_queue, total_time);
    }
    if(elevator->current_floor > elevator->destination){
        elevator->current_floor--;
    } else if(elevator->current_floor < elevator->destination) {
        elevator->current_floor++;
    }
}


elevator_t *free_elevator(elevator_t *elevator){
    free_linked_list(elevator->in_people, free);
    elevator->in_people = NULL;
    return NULL;
}

void choose_next_destination(elevator_t *elevator, queue_t *floors, int total_time){
    int priorities[MAX_FLOOR] = {0};
	reset_iterator(elevator->in_people);
    while(iter_has_next(elevator->in_people)){
        person_t *person = (person_t*) move_next(elevator->in_people);
        priorities[person->destination] += total_time - person->arrival_time;
    }


    if(elevator_load(elevator) < MAX_ELEVATOR_CAPACITY){
        for(int i = 0; i < MAX_FLOOR; i++){
			if(!queue_is_empty(floors + i)){	
				priorities[i] += total_time - floors[i].start_time;
			}
        }
    }


    int max_priority = -1;
    int max_floor = -1;

    for(int i = 0; i < MAX_FLOOR; i++){
        if(priorities[i] > max_priority){
            max_floor = i;
            max_priority = priorities[i];
        }
    }

    elevator->destination = max_floor;
}

void enter_people(elevator_t *elevator, queue_t *people_queue, int total_time){
    while(elevator_load(elevator) < MAX_ELEVATOR_CAPACITY && 
            !queue_is_empty(people_queue )){
        person_t *person = dequeue_element(people_queue);
        person->arrival_time = total_time;
        add(elevator->in_people, person);
        people_queue->start_time = total_time;
    }
}

void exit_people(elevator_t *elevator){
	reset_iterator(elevator->in_people);
    while(iter_has_next(elevator->in_people)){
        person_t *person = move_next(elevator->in_people);
        if(person->destination == elevator->current_floor){
        	remove_current_iter_node(elevator->in_people, free);
        }
    }    
}

int elevator_load(elevator_t *elevator){
    return linked_list_length(elevator->in_people);
}

char *elevator_to_string(char *elevator_string, elevator_t *elevator){
    elevator_string[0] = '\0';
    char temp[MAX_PERSON_STRING_LENGTH * MAX_ELEVATOR_CAPACITY];
    elevator_string = strcat(elevator_string, "elevator:\n");
    elevator_string = strcat(elevator_string, linked_list_to_string(
                                                                    temp, 
                                                                    elevator->in_people, 
                                                                    person_to_string, 
                                                                    MAX_PERSON_STRING_LENGTH));
    sprintf(temp, "current_floor:%d\ndestination:%d\n", elevator->current_floor, elevator->destination);
    elevator_string = strcat(elevator_string, temp);
    return elevator_string;
}
