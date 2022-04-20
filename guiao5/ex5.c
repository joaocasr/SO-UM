#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc , char * argv){
char *bash[4]={"grep","cut","uniq","wc"};
int fds[4][2];
int i;
for(i=0;i<4;i++){

if(pipe(fds[i])==-1){
        perror("could not create pipe!");
        _exit(-1);
}
	if(i==0 && fork()==0){
	   close(fds[i][0]);
	   dup2(fds[i][1],1);
	   close(fds[i][1]);
	   execlp(bash[i],bash[i],"-v","^#","/etc/passwd",NULL);
	   _exit(0);
	}
	 if(i==0) close(fds[i][1]);
	
	if(i==1 && fork()==0){
	   close(fds[i][0]);
           dup2(fds[i-1][0],0);
	   dup2(fds[i][1],1);
           close(fds[i-1][0]);
	   close(fds[i][1]);
           execlp(bash[i],bash[i],"-f7","-d:",NULL);
           _exit(0);
        }
	if(i==1){
        close(fds[i-1][0]);
        close(fds[i][1]);
        }

	if(i==2 && fork()==0){
           close(fds[i][0]);
           dup2(fds[i-1][0],0);
           dup2(fds[i][1],1);
           close(fds[i-1][0]);
           close(fds[i][1]);
           execlp(bash[i],bash[i],NULL);
           _exit(0);
        }
	if(i==2){
	close(fds[i-1][0]);
	close(fds[i][1]);
	}

	if(i==3 && fork()==0){
           dup2(fds[i-1][0],0);
           close(fds[i-1][0]);
           execlp(bash[i],bash[i],"-l",NULL);
           _exit(0);
        }
	if(i==3) close(fds[i-1][0]);
}
	int j;
	for(j=0;j<4;j++) wait(NULL);
return 0;
}
