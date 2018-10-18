#include <stdio.h>
#include <limits.h>

int main(int argc, char** argv){
	if(argc > 2 || argc == 1){
		printf("Wrong parameter amount, please enter 1 argument. Returning..\n");
		return 1;
	}

	int page_frames = atoi(argv[1]);
	int *frame = malloc(sizeof(int)*page_frames);
	memset(frame, 0, page_frames);
	int *R = malloc(sizeof(int)*page_frames);
	memset(R, 0, page_frames);
	int miss = 0;
	int hit = 0;

	FILE *input;
	input = fopen("input2.txt", "r");
	int temp;
	while(!feof(input)){
		fscanf(input, "%d", &temp);
		int is_in = 0;
		int *least_age = &R[0];
		int *least_aged_frame = &frame[0];
		int index;
		for(int i = 0; i < page_frames; i++){
			if(temp == frame[i]){
				is_in = 1;
				index = i;
				printf("%d ", frame[i]);
			}
			if(R[i] < *least_age){
				least_age = &R[i];
				least_aged_frame = &frame[i];
			}
		}

		if(!is_in){
			*least_aged_frame = temp;
			*least_age = 128;
			miss++;
		}
		else{
			R[index] = div(R[index], 2) + 128;
			hit++;
		}
	}
	printf("hit: %d; miss:%d\n", hit, miss);
}