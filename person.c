#include "person.h"

person_t get_person(int destination, int arrival, int arrival_time){
    return (person_t) {
        destination: destination,
        arrival: arrival,
        arrival_time: arrival_time
    };
}


void bulk_increase_priority(person_t *people, int arr_len){
   for(int i = 0; i < arr_len; i++) {
       if(people+i != 0){
           increase_priority(people+i);
       }
   }
}