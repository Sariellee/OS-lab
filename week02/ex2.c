#include <stdio.h>
#include <string.h>

int main(){
	char m[200];
	printf("Input a string: ");
	scanf("%[^\n]", m);
	int i;
	for(i = strlen(m); i >= 0; i--){
		printf("%c", m[i]);
	}
	printf("\n\n");
	return 0;
}
