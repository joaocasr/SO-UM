#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define size 1024

int main(){
    
    int fd = open("fifo", O_RDONLY);

    char buf[size];
    size_t rd;
    while((rd = read(fd,buf,size)) > 0){
            write(STDOUT_FILENO, buf, rd);
        }
    close(fd);
    return 0;
}
