#include <stdio.h>

int* reallocate(int* a1, int size){
	int* temp = malloc(sizeof(int)*size);
	if(a1 == NULL){
		return temp;
	}
	if(size == 0){
		free(a1);
		return NULL;
	}

	memcpy(temp, a1, malloc_size(a1));
	free(a1);
	return temp;
}

int main(){
	int n;
	printf("Type N: ");
	scanf("%d", &n);

	int* arr = malloc(sizeof(int)*n);

	for(int i = 0; i < n; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");

	int newSize = 0;
	printf("Type new size: ");
	scanf("%d", &newSize);

	arr = reallocate(arr, newSize);
	for(int i = 0; i < newSize; i++){
		printf("%d ", arr[i]);
	}
}