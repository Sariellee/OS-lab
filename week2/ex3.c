#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	printf("Size is %d\n\n", n);
	int sides = n-1;
	int stars = 1;
	while(stars < 2*n){
		int i;
		for(i=0; i<sides; i++){
			printf(" ");
		}
		for(i=0; i<stars; i++){
			printf("*");
		}
		sides--;
		stars+=2;
		printf("\n");
	}
	return 0;
}
