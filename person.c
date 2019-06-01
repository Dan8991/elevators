#include "person.h"
#include <stdlib.h>
#include <string.h>

person_t *get_person(int destination, int arrival, int arrival_time){
    person_t *person = malloc(sizeof(person_t));
    person->destination = destination;
    person->arrival = arrival;
    person->arrival_time = arrival_time;

    return person;
}

char *person_to_string(char *person_string, person_t person){
    sprintf(
        person_string, 
        "person: a=%d d=%d t=%d\n",
        person.arrival, 
        person.destination, 
        person.arrival_time
    ); 
    return person_string;
}