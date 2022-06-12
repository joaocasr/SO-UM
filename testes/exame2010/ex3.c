#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define size 1024

int main(int argc,char * argv[]){
int i;
int status;
for(i=1;argc>i;i++){
if(fork()==0){
 execlp(argv[i],argv[i],NULL);
 perror("erro");
 _exit(1);//se chegar aqui quer dizer que algo correu mal com o execlp
}else{
        wait(&status);
	if(WIFEXITED(status)) {
        printf("O comando nº %i terminou\nOVER\n",i);
	}
}
}
return 0;
}
