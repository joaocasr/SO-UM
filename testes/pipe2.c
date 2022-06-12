#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

// ls -l | grep mes (eg:jun) | wc -l

int main(int argc,char *argv[]){
char mes[20];
int status;
printf("Número de arquivos em ->");
scanf("%s",mes);
int fds[2];
if(pipe(fds)==-1){
perror("error building pipe.");
exit(-1);
}
if(fork()==0){
 close(fds[0]);
 dup2(fds[1],1);
 close(fds[1]);
 execlp("ls","ls","-l",NULL);
}
close(fds[1]);
int fds2[2];
if(pipe(fds2)==-1){
perror("error building pipe.");
exit(-1);
}
if(fork()==0){
 close(fds2[0]);
 dup2(fds[0],0);
 close(fds[0]);
 dup2(fds2[1],1);
 close(fds2[1]);
 execlp("grep","grep",mes,NULL);
}
close(fds[0]);
close(fds2[1]);
if(fork()==0){
 close(fds2[1]);
 dup2(fds2[0],0);
 close(fds2[0]);
 execlp("wc","wc","-l",NULL);
}
close(fds2[0]);
int j;
        for(j=0;j<3;j++){
                wait(&status);
                if(WEXITSTATUS(status)==1) printf("Não existem arquivos dessa data.\n");
        }
return 0;
}

