#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	
	printf("\n\nValues are: \n %d for int \n %f for float \n %lf for double", a, b, c);
	printf("\n\nSizes are: \n %ld for int \n %ld for float \n %ld for double", sizeof(int), sizeof(float), sizeof(double));
	printf("\nDiscussing the results now ...");
	printf("\nDone!\n\n\n");
	return 0;
}
