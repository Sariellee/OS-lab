#include <stdio.h>

void bubble_sort(int arr[], int size){
	int temp;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(arr[j] > arr[i]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(){
	int size = 0;
	printf("Input array size: ");
	scanf("%d", &size);
	int arr[size];
	printf("input array: ");
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}

	bubble_sort(arr, size);

	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n")
}