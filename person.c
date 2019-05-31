#include "person.h"

person_t get_person(int destination, int arrival){
    return (person_t) {
        destination: destination,
        arrival: arrival,
        priority: BASE_PRIORITY
    };
}

void increase_priority(person_t *person){
    person->priority++;
}

void bulk_increase_priority(person_t *people, int arr_len){
   for(int i = 0; i < arr_len; i++) {
       if(people+i != 0){
           increase_priority(people+i);
       }
   }
}