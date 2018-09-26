#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int main(){
	int child_pid;

	int pip[2];
	pipe(pip);
	child_pid = fork();
	printf("child_pid with PID %d forked by process with PID %d\n", child_pid, getpid());

	if (child_pid == 0) {
		while (1) {
		// child_pid Code
			printf("I am alive\n");
			sleep(1);
		}
	} else {
		// Parent Code
		sleep(10);
		kill(child_pid, SIGTERM);
		printf("child_pid with PID %d is killed\n", child_pid);
	}
}