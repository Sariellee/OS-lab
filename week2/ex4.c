#include <stdio.h>

void swap(int *a, int *b){
        int c = *a;
        *a = *b;
        *b = c;
}

int main(){
	int a, b;
	printf("Print numbers: ");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}
