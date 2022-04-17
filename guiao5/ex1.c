#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#define size 1024*1024

int main(int argc, char const *argv[]) {
	int pipe_fd[2];
        ssize_t pid;
	char message[20]="shaazaaaam\n";
	char buffer[size];
	if(pipe(pipe_fd) == -1) {
		perror("pipe");
		exit(1);
	}
	if((pid = fork()) == 0) {
		close(pipe_fd[1]);
		int bytes = read(pipe_fd[0], buffer, 10);
		close(pipe_fd[0]);
		write(1, buffer, bytes);
		_exit(0);
	} else {
		close(pipe_fd[0]);
		write(pipe_fd[1], message, strlen(message));
		close(pipe_fd[1]);
		wait(NULL);
	}

	return 0;
}
