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
    if(argc < 6) exit(1);

    int infd;
    int outfd;

    if(!strcmp(argv[1], "-i")) {
        infd = open(argv[2], O_RDONLY);
	dup2(infd,0);
	close(infd);
    }

    if(!strcmp(argv[3], "-o")) {
        outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(outfd,1);
	close(outfd);
    }

	if(fork() == 0) {
		execvp(argv[5], argv + 5);
		_exit(1);
	} else wait(NULL);

	return 0;
}      
