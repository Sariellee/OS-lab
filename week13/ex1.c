#include <stdio.h>
void the_end();


void read_str(int m, char* e, char* line){
	for(int i = 0; i < m; i++){
  		if(e[i] == ' '){
  			continue;
  		}
  		else{
  			e[i] = atoi(&line[i*2]);
  		}
  		printf("%d ", e[i]);
  	}
  	printf("\n");
}

int main(){
  goto end_of_semester;


	// read file

	FILE* f = fopen("input_ok.txt", "r");
  	char *line = NULL;
  	size_t whatever = 0;
    ssize_t len;
  	len = getline(&line, &whatever, f);
	int m = (int) len/2;

  	// read existing

  	int *e = malloc(sizeof(int)*m);
	read_str(m, e, line);

	// read available

	int *a = malloc(sizeof(int)*m);
  	len = getline(&line, &whatever, f);
  	read_str(m, a, line);

  	// read allocation matrix

  	int **almatrix = malloc(sizeof(int)*m);

  	int i = 0;

  	while(1){
  		if(feof(f)){
  			break;
  		}
  		else if(fgetc(f) == '\n'){
  			printf("End of line!");
  		}
  		else{
  			len = getline(&line, &whatever, f);
  			almatrix[i] = malloc(sizeof(int)*m);
  			read_str(m, almatrix[i], line);
  		}
  		for(int j = 0; j < m; j++){
  			printf("%d ", almatrix[i][j]);
  		}
  		printf("\n");

  		i++;
  	}
    end_of_semester:
    the_end();

}

void the_end(){
      sleep(2);
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNikita, thank you for everything.");
      sleep(3);
      printf("\nI learned a lot during this course");
      sleep(3);
      printf("\nlike, seriously!");
      sleep(3);
      printf("\n*cries deeply with big manly tears*");
      sleep(3);
      printf("\nThank you...");
      sleep(2);
      printf("\n             for everything.\n\n\n\n");
      sleep(2);
      sleep(2);
      printf("\n(I very zaebalsya parsit' this file)\n\n\n");
  }