#include "person.h"
#include <stdlib.h>

person_t *get_person(int destination, int arrival, int arrival_time)
{
    person_t *person = malloc(sizeof(person_t));

    person->destination = destination;
    person->arrival = arrival;
    person->arrival_time = arrival_time;

    return person;
}

void set_arrival_time(person_t *person, int arrival_time)
{
    person->arrival_time = arrival_time;
}
