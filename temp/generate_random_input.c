#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "../hotel.h"

int main(){
	srand(time(NULL));

	for(int i = 0; i<50;i++){
		int choice = rand() % 10;
		if(choice < 3){
			int arrival = 0;	
			int destination = 0;
			while(arrival == destination){
				arrival = rand()%20;
				destination = rand()%20;
			}
			printf("%s %d %d\n", "PERSON_ARRIVES", arrival, destination);
		} else if(choice >= 3 && choice <=8){
			printf("TIME_STEP\n");
		} else{
			printf("PRINT_STATUS\n");
		}
	}

	printf("PRINT_STATUS");
	return 0;

}
