#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>


int main(int argc, char *argv[]) {

//char *files[3]={"../../poo.txt","../../comandos.txt","../../texto.txt"};
int i=0;
int pid,status;
while(i<3){
if((pid=fork())==0){
	execl("/usr/bin/grep","grep",argv[1],argv[i]);
	_exit(0);
}
i++;
}
int k;
for(k=0;k<3;k++){
  wait(&status);	
}
return 0;
}
