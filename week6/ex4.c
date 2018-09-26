#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

void handleSIGKILL(){
	printf("Received SIGKILL signal \n");
}

void handleSIGSTOP(){
	printf("Received SIGSTOP signal \n");
}

void handleSIGUSR1(){
	printf("received SIGUSR1 \n");
	return;
}

int main(){
	signal(SIGUSR1, handleSIGUSR1);
	signal(SIGSTOP, handleSIGSTOP);
	signal(SIGKILL, handleSIGKILL);
	while(1){
		sleep(1);
		printf("I'm running. Try sending me signals, and I will try to response\n");
	}
}