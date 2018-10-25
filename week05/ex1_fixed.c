#include <stdio.h>
#include <pthread.h>

void func(n){
	printf(" %d\n", n);
	pthread_exit(NULL);
}

int main(){
	int n = 5;
	pthread_t* threads = malloc(sizeof(pthread_t)*n);
	for(int i = 0; i < n; i++){
		pthread_create(&threads[i], NULL, func, (void*) i);
		printf("Thread created!");
		pthread_join(threads[i], NULL);
	}
}