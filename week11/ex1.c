#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd = open("ex1.txt", O_RDWR);

    struct stat *file_info = malloc(sizeof(struct stat));

    if(fd == -1){
        printf("Failed to open");
        return 1;
    }
    if(fstat( fd, file_info) < 0){
        printf("Fstat failed");
        close(fd);
        return 1;
    }
    int size = (int) file_info->st_size;

    printf("%d\n", size);
    char* file = mmap(NULL, (size_t) size, PROT_READ | PROT_WRITE, MAP_SHARED,  fd, 0);
    memcpy(file, "This is a nice day", strlen("This is a nice day"));
    if (msync(file, strlen("This is a nice day"), MS_SYNC != 0)){
        printf("MSYNC failed");
        close(fd);
        return 1;
    }
    munmap(file, (size_t) size);
    close(fd);
}