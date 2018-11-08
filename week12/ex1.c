#include <stdio.h>

int main(){
	char *ran_str = malloc(sizeof(char)*20);
	FILE *random = fopen("/dev/random", "r");
	fread(ran_str, sizeof(char), 20, random);

	for(int i = 0; i < 20; i++){
		printf("%c ", ran_str[i]);
	}

}