#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "../hotel.h"

int main(){
	srand(time(NULL));

	for(int i = 0; i<1000000;i++){
		int choice = rand() % 3;
		if(!choice){
			int arrival = rand()%20;
			int destination = rand()%20;
			printf("%s %d %d\n", "PERSON_ARRIVES", arrival, destination);
		} else {
			printf("TIME_STEP\n");
			printf("PRINT_STATUS\n");
			continue;
		}
	}

	printf("PRINT_STATUS");
	return 0;

}
