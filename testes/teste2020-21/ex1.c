#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define size 1024

char ** parse_entry(char * buffer){
int i=0;
int c=0;
int p=0;
char * entrada[3];
	while(buffer[i]!='\0'){
		if(buffer[i]==' '){	
		   strncpy(entrada[c],buffer+p,i);
		   c++;
	    	   p=i+1;	
		}
	i++;
	}
return entrada;
}

int main(int argc, char * argc[]){
	mkfifo("cliente_servidor_pipe",0644);
	int fd = open("cliente_servidor_pipe",O_RDONLY);
	ssize_t bytes_read;
	int fd[100];//100 regioes


	char buffer[size];
	while((bytes_read=read(fd,buffer,size))>0){
		char ** entradas;
	       while((entradas = parse_entry(&buffer))!=0){
	       		int num=atoi(entradas[2]);
			char * buffer2;
			char * filename;

                        sprintf(filename,"regiao_%d",num);
			int fd[num]=open(filename,O_WRONLY | O_CREATE ,0664);
       			sprintf(buffer2,"%s %s %s",entradas[0],entradas[1],entradas[2]);
			write(fd[num],buffer2,size);
	       };

	}
return 0;
}
