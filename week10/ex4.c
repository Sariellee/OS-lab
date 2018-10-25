#include <stdio.h>

int main(){
	DIR* dir = opendir("tmp");
	struct dirent* entry;

	while ((entry = readdir(dirp)) != NULL){
		if((stat(entry) -> nlink_t) > 2){
			
		}
	}
}