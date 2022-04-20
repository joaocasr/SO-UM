#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h> 

#define size 1024

int main(int argc , char * argv){
char buffer[size];
int fds[2];
if(pipe(fds)==-1){
        perror("could not create pipe!");
        _exit(-1);
}
if(fork()==0){
   close(fds[1]);
   dup2(fds[0],0);
   close(fds[0]);
   execlp("wc","wc",NULL);
   _exit(0);
}
close(fds[0]);
ssize_t bytes_read;
while((bytes_read= read(0,buffer,size))>0){
	write(fds[1],buffer,bytes_read);
}
close(fds[1]);
if(wait(NULL)==-1){
	perror("erro");
};
return 0;
}
