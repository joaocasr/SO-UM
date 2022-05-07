#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define size 1024

int main(int argc, char * argv[]){
	char buffer[size];
	int fd1,fd2;
	
	fd2 = open("log.txt", O_CREAT | O_WRONLY, 0640);
if(fd2==-1) perror("erro");	
	mkfifo("cliente_servidor",0666);
	write(1,"[+] Em execução...\n",21);

while(1){

	fd1 = open("cliente_servidor",O_RDONLY);
	if(fd1==-1) perror("erro");
	ssize_t bytes_read;
	while((bytes_read=read(fd1,buffer,size))>0){
		write(fd2,buffer,bytes_read);
	} 
		close(fd1);
}
close(fd2);
return 0;
}
