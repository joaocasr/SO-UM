#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define size 1024

int main(int argc, char * argc[]){

	//mkfifo("cliente_servidor_pipe",0644);
	int fd = open("cliente_servidor_pipe",O_RDONLY);
	ssize_t bytes_read;

	int n[9];
	char * file_names[9];
	for(int i=0;i<9;i++){
		sprintf(file_names[i],"regiao_%d",i+1);
		n[i]=open(file_names[i],O_WRONLY,0644);
	}
	char * buffer[size];
	while((bytes_read=read(fd,buffer,size))>0){
		char ** entradas;
	       while((entradas = parse_entry(&buffer))!=0){
	       		int num=atoi(entradas[2]);
			char * buffer2[size];
			sprintf(buffer2,"%s %s %s",entradas[0],entradas[1],entradas[2]);
			write(n[num-1],buffer2,size);
	       };

	}
return 0;
}
