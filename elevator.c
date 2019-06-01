#include <stdlib.h>
#include "elevator.h"
#include "linked_list.h"
#include "node.h"

elevator_t *get_elevator(){
    elevator_t *ret = malloc(sizeof(elevator_t));
    ret->in_people = create_list();
    ret->in_people_number = 0;
    ret->wait_people = (int[MAX_FLOOR]) {};
    ret->current_floor = 0;
    ret->destination = 0;
    return ret;
}

void forward_time(elevator_t *elevator){
    if(elevator->current_floor > elevator->destination){
        elevator->current_floor--;
    } else if(elevator->current_floor < elevator->destination) {
        elevator->current_floor++;
    }
    if(elevator->current_floor == elevator->destination){
        choose_next_destination(elevator);
    }
}

elevator_t *free_elevator(elevator_t *elevator){
    free_linked_list(elevator, NULL);
    free(elevator);
    return NULL;
}

void choose_next_destination(elevator_t *elevator){
    int priorities[MAX_FLOOR] = {};
    

}

