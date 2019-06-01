#include "person.h"
#include <stdlib.h>

person_t *get_person(int destination, int arrival, int arrival_time){
    person_t *person = malloc(sizeof(person_t));
    person->destination = destination;
    person->arrival = arrival;
    person->arrival_time = arrival_time;

    return person;
}


void bulk_increase_priority(person_t *people, int arr_len){
   for(int i = 0; i < arr_len; i++) {
       if(people+i != 0){
           increase_priority(people+i);
       }
   }
}