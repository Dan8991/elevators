#include "person.h"

person_t get_person(int destination, int arrival){
    return {destination: destination, arrival: arrival, priority: BASE_PRIORITY}
}

void increase_priority(person_t *person);