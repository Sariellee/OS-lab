#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(){
	DIR* dir = opendir("tmp");
	struct dirent* entry;
	char comm[100];
	char buff[100];
	struct stat info;

	while ((entry = readdir(dir)) != NULL){
		if(info.st_nlink >= 2){
			strcpy(comm, "find . -inum ");
			sprintf(buff, "%d", info.st_ino);
			strcat(comm, buff);
			strcat(comm, " -printf \"%f \"");
			system(comm);
			printf("\n");
		}
	}
	for(int i = 0; i< 100; i++){
		printf("%c ", comm[i]);
	}
}