#ifndef HOTEL_H
#define HOTEL_H
#include "queue.h"

#define PRINT_STATUS "PRINT_STATUS" 
#define TIME_STEP "TIME_STEP" 
#define MAX_INPUT_LINE_LENGTH 21 

void person_arrives(char *string, queue_t *floors, int current_time);

void time_step();

void print_status(queue_t *floors);

void initialize_floors(queue_t *floors);

#endif