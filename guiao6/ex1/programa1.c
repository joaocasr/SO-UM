#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
        mkfifo("fifo",0666);
	int fd = open("cliente_servidor",O_WRONLY);
return 0;
}

