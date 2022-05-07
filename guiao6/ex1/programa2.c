#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define size 1024

int main(){
    int fd = open("fifo", O_WRONLY);
    char buf[size];
    size_t rd;
    while((rd = read(STDIN_FILENO,buf,size)) > 0){
            write(fd, buf, rd);
        }
    close(fd);
    return 0;
}
