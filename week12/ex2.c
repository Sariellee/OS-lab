#include <stdio.h>

int main(int argc, char const *argv[]){
	int length = 100;
	char buf[length];
	if (argc==1){
		while (fgets(buf, length, stdin) != NULL){
			printf("%s", buf);
		}
	}
	else if (argc == 2){
		FILE* output = fopen(argv[1], "w");
		while (fgets(buf, length, stdin) != NULL){
			printf("%s", buf);
			fprintf(output, "%s\n", buf);
		}
		fclose(output);
	}
	else{
		if (strcmp("-a", argv[1])){
			FILE* output = fopen(argv[2], "a");
			while (fgets(buf, length, stdin) != NULL){
				printf("%s", buf);
				fprintf(output, "%s", buf);
			}
			fclose(output);
		}
		else
			printf("No arguments were passed");;
	}
}