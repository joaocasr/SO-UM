#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
	if(argc!=2) perror("Número errado de argumentos!");
	int fd = open("cliente_servidor",O_WRONLY);
	write(fd,argv[1],strlen(argv[1]));
	close(fd);
return 0;
}
