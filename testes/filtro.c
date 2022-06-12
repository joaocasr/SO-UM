#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define SIZE 1024

int readln(int fd, char * buff,int tam){
int i=0;
int b;
 for(i=0;i<tam;i++){
	b=read(fd,&buff[i],1);
	if(buff[i]=='\n' || b <=0) break;
 }
return i+1;
}


int main(int argc, char * argv[]){
char buffer[SIZE];
int n=0;
int fd[10];
while(n<10){
	char * ficheiro;
       	sprintf(ficheiro,"ficheiros/ficheiro%d",n);
       	fd[n]=open(ficheiro,O_CREAT | O_WRONLY,0640);
	n++;
}
int bytes_read;
while((bytes_read=readln(0,buffer,SIZE))>=0){
	if(fork()==0){
	        dup2(fd[buffer[0]-'0'],1);
		close(fd[buffer[0]-'0']);
		if((buffer[0]-'0')%2==0) execlp("lower","lower",buffer,NULL);
		else execl("upper","upper",buffer,NULL);
	}
	close(fd[buffer[0]]);
}
return 0;
}

