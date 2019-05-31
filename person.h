#ifndef PERSONA_H
#define PERSONA_H

#define BASE_PRIORITY 0

typedef struct person{
   int destination;
   int arrival;
   int priority;
}person_t;

person_t get_person(int destination, int arrival);

void increase_priority(person_t *person);

void bulk_increase_priority(person_t *people, int arr_len);

#endif