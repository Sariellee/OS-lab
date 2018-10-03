#include <stdio.h>

int main(){
	int n;
	printf("Type N: ");
	scanf("%d", &n);

	int* arr = malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	free(arr);
	printf("\n");
}