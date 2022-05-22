#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define size 1024

bool ronda=true;
int count=0;
int pids[100];

void timeout_handler(){
 int i=0;
for(i=0,i<100,i++){
   kill(pids[i],SIGKILL);	
} 
char buffer[100];
sprintf(buffer,"Foram terminadas %d instâncias",count);
write(1,buffer,strlen(buffer));
}


int main(int argc, char *argv[]){
int i,pid;
int status;
if(signal(SIGALRM,timeout_handler)==-1){
	perror("error");
	_exit(-1);
}
while(ronda){
alarm(20);	
for(i=0;i<100;i++){
   if((pid=fork())==0){
	pids[i]=pid;   
   	execlp("cmd","cmd",NULL);
	_exit(0);
   }
}

while(WIFEXITED(&status)!=-1){
  if(WEXITSTATUS(status)==0){
  	count++;
  }
}
char buffer[100];
sprintf(buffer,"Foram terminadas %d instâncias",count);
write(1,buffer,strlen(buffer));
}

return 0;
}
