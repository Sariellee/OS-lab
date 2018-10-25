#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

int main (void){

	char* string = malloc(sizeof(char)*5);
	string = "hello";

	char* string2 = malloc(sizeof(char)*5);

	int pip[2];
	pipe(pip);

	int vilka = fork();
	if(vilka > 1){
		write(pip[1], string, sizeof(string));
	}
	else{
		read(pip[0], string2, sizeof(string2));
	}

	close(pip[0]);
	close(pip[1]);
	
	printf("String to write: %s\n", string);
	printf("String received: %s\n", string2);
}