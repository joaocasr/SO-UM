#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define size 1024

int main(int argc, char *argv){
int i=0;
int fds[10][2];
int status;
int pid;
while(i<10){
 if(pipe(fds[i])==-1){
 	perror("error creating pipe.");
	_exit(-1);
 }
	if((pid=fork())==0){
	   char *arg;
   	   sprintf(arg,"/proc/%d/memstats",pid);	   
	   if(fork()==0){
	     close(fds[i][0]);
     	     dup2(fds[i][1],1);
	     close(fds[i][1]);
	     execlp("grep","grep","VmPeak",arg,NULL);
	     _exit(0);		     
	   }
		
	   close(fds[i][1]);
	   if(fork()==0){
	    close(fds[i][1]);
	    dup2(fds[i][0],0);
	    close(fds[i][0]);
	    execlp("cut","cut","-d"," ","-f4",NULL);
	    _exit(0);
	   }
	   close(fds[i][0]);
	
	   _exit(0)
	}
	else{
		int child= wait(&status);
		if(WIFEXITED(status)==-1){
			printf("exit error from son!");
		}
	}

	i++;
}
return 0;
}
