#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc , char * argv){
char *bash[2]={"ls","wc"};
int fds[2];
if(pipe(fds)==-1){
	perror("could not create pipe!");
	_exit(-1);
}

	 if(fork()==0){
	   close(fds[0]);
	   dup2(fds[1],1);
	   close(fds[1]);
	   execlp(bash[0],bash[0],"/etc",NULL);
	   _exit(0);
	}
	 close(fds[1]);
	
	if(fork()==0){
	   close(fds[1]);
           dup2(fds[0],0);
           close(fds[0]);
           execlp(bash[1],bash[1],"-l",NULL);
           _exit(0);
        }
	close(fds[0]);
int j;
	for(j=0;j<2;j++) wait(NULL);
return 0;
}
