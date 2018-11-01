#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IOLBF, 0);
	for(int i = 0; i < 5; i++){
		printf("H");
		sleep(1);
		printf("E");
		sleep(1);
		printf("L");
		sleep(1);
		printf("L");
		sleep(1);
		printf("O \n");
		sleep(1);
	}
}