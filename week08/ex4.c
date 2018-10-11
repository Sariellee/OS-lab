#include <stdio.h>
#include <sys/resource.h>

int main(){
	struct rusage r_usage;
	for(int j = 0; j < 15; j++){
		int* arr = malloc(sizeof(int)*10*1024*1024);
		memset(arr, 0, 10*1024*1024);
		getrusage(RUSAGE_SELF, &r_usage);
		printf("%ld\n", r_usage.ru_maxrss);
		sleep(1);
		free(arr);
	}
}