#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define size 1024


int vacinados(char * regiao,int idade){
int fds[2];
  char * num;
  char * filename;
  sprintf(num,"%d",idade);
  sprintf(filename,"regiao_%s",regiao);
int status;
if(pipe(fds)==-1){
perror("Error creating pipe.");
_exit(-1);
}

if(fork()==0){
  close(fds[0]);
  dup2(fds[1],1);
  close(fds[1]);
  execlp("grep","grep",num,filename,NULL);
  _exit(0);  
}

	 close(fds[1]);
if(fork()==0){
	close(fds[1]);
      	dup2(fds[0],0);
  	close(fds[0]);
  	execlp("wc","wc","-l",NULL);
  	_exit(0);
}
	close(fds[0]);

int i=0;
for(i=0;i<2;i++)
	wait(&status);
return 0;
}
