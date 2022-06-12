#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define size 1024


int main(int argc, char * argv[]){
    int pipes[2];
    if (pipe(pipes) == -1) {
        perror("Pipe creation failed");
    }
    if (fork() == 0) {
        close(pipes[0]);
        dup2(pipes[1], STDOUT_FILENO);
        close(pipes[1]);
        execlp("grep", "grep", argv[1], argv[2], NULL);
    }
    close(pipes[1]);
    int pipes2[2];
    if (pipe(pipes2) == -1) {
        perror("Pipe creation failed");
    }

    if (fork() == 0) {
        close(pipes2[0]);
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        dup2(pipes2[1], STDOUT_FILENO);
        close(pipes2[1]);
        execlp("wc", "wc", "-l", NULL);
    }
    close (pipes[0]);
    close(pipes2[1]);
    int read_bytes = 0;
    char buf[1025];
    read_bytes = read(pipes2[0], buf, 1024);
    close(pipes2[0]);
    buf[read_bytes]=0;
    printf("%s",buf);
    return atoi(buf);

}
