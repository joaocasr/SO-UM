#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
//----tania_esteves--------
/* chamadas ao sistema: defs e decls essenciais */
/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <string.h>

#define size 1024*1024

int main(int argc, char * argv[]){
    int fd1,fd2,fd3;
    ssize_t bytes_read;
    int res;
    char buffer[size];	
    int terminal_fd = dup(1);
        
    fd1 = open("etc/passwd.txt",O_RDONLY);
        if(fd1==-1) perror("erro");
	
	fd2 = open("saida.txt",O_WRONLY|O_CREAT,0666);	
	if(fd2==-1) perror("erro");
	
	fd3 = open("erros.txt",O_WRONLY|O_CREAT,0666);
    	if(fd3==-1) perror("erro");
	
	
	dup2(fd1,0);
	dup2(fd2,1);
	dup2(fd3,2);
        
	close(fd1);
	close(fd2);
	close(fd3);
	

	while((bytes_read=read(0,buffer,size))>0){
		write(1,buffer,bytes_read);
	}
	//write(terminal_fd,"terminei",strlen("terminei"));
close(0);
close(1);

	return 0;
}      
