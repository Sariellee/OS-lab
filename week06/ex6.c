#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

int main(){
	int child_id0;
	int child_id1;

	int pip[2];
	pipe(pip);
	child_id0 = fork();
	printf("Child 0 created \n");

	if(child_id0 == 0){
	    int id = 0;
	    read(pip[0], &id, 10);
	    close(pip[0]);
	    printf("Child 1 PID is %d\n", id);
	    sleep(2);

	    printf("SIGSTOP to child 1\n");
	    kill(id, SIGSTOP);

	    printf("Killing child 1!\n");
	    kill(id, SIGKILL);

	}
	else{
		child_id1 = fork();
		if(child_id1 == 0){
			printf("Child 1 created\n");
      		while(1);
		}
		else{
			int id;
	        write(pip[1], &child_id1, 10);
	        close(pip[0]);
	        close(pip[1]);
	        waitpid(child_id1, &id, 0);
	        printf("Child 2 killed!\n");
	        printf("Done");
		}
	}
}
