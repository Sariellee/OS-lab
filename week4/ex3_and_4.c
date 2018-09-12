#include <stdio.h>
#include <unistd.h>

int main(){
	while(1){
		char cmd[50];

		printf("$ ");
		fgets(cmd, 50, stdin);
		if(strncmp(cmd, "exit()", 6) == 0){ // if strings are the same, returns 0
			break;
		}
		system(cmd);
	}
}