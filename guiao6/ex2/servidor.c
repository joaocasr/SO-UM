#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define size 1024

int main(int argc, char * argv[]){
	char buffer[size];

	mkfifo("cliente_servidor",0644);
	int fd = open("cliente_servidor",O_RDONLY);
	write(1,"[+] Em execução...\n",21);
while(1){
	int fd2 = open("log.txt", O_CREAT | O_WRONLY, 0640);
	ssize_t bytes_read;
	while((bytes_read=read(fd,buffer,size))>0){
		write(fd2,buffer,bytes_read);
		close(fd);
		return 0;
	}
	        close(fd2);
}
return 0;
}
