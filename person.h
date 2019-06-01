#ifndef PERSONA_H
#define PERSONA_H

#define BASE_PRIORITY 0
#define MAX_PERSON_STRING_LENGTH 30
#include "linked_list.h"
#include "node.h"

typedef struct person{
   int destination;
   int arrival;
   int arrival_time;
}person_t;

person_t *get_person(int destination, int arrival, int arrival_time);

char* person_to_string(char* person_string, person_t person);

#endif