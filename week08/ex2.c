#include <stdio.h>

int main(){
	for(int j = 0; j < 15; j++){
		int* arr = malloc(sizeof(int)*10*1024*1024);
		memset(arr, 0, 10*1024*1024);
		sleep(1);
		free(arr);
	}
}