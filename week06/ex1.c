#include <stdio.h>
#include <stdlib.h>

int main (void){

	char* string = malloc(sizeof(char)*5);
	string = "hello";

	char* string2 = malloc(sizeof(char)*5);

	int pip[2];
	pipe(pip);

	write(pip[1], string, sizeof(string));
	printf("%d\n", pip[0]);
	read(pip[0], string2, sizeof(string2));
	printf("%d\n", pip[1]);

	close(pip[1]);
	close(pip[2]);
	printf("%s\n", string);
	printf("%s\n", string2);
}