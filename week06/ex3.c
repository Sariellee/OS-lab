#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

void catchSIGINT(){
	printf("\nCaught your signal! If your really want to kill me, do the CTRL+\\ \n\n");
	return;
}

int main (void){

	signal(SIGINT, catchSIGINT);
	while(1){
		sleep(1);
		printf("I'm running. Try using CTRL+C, and I will try to response\n");
		
	}
}