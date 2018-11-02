#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd = open("ex1.txt", O_RDWR);
    int fd1 = open("ex1_copy.txt", O_RDWR | O_CREAT);

    struct stat *stat = malloc(sizeof(struct stat));
    fstat(fd, stat);

    int size = stat -> st_size;
    ftruncate(fd1, (off_t) size);

    char *file = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    char *file1 = mmap(0, size, PROT_WRITE, MAP_SHARED, fd1, 0);
    memcpy(file1, file, size);

    msync(file1, size, MS_SYNC);
    munmap(file, size);
    munmap(file1, size);



}