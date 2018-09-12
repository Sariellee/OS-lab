#include <stdio.h>
#include <unistd.h>

int main(){
	int n = 11;
	int returnCode = fork();
	if (returnCode > 0){
		printf("Hello from parent [%d; %d] \n", returnCode, n);
	}
	else if(returnCode == 0){
		printf("Hello from child [%d; %d] \n", returnCode, n);
	}
	else{
		printf("Say what? %d \n", returnCode);
	}
}