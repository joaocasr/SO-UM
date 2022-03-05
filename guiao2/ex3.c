#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]){
  pid_t pid;
  int status;
  int i=1;
  while(i<=10){
  pid=fork();
  if(pid==0){ // fork retorna 0 ao processo filho
	  //Código do filho 
	printf("O meu pid é %d e o pid do meu pai é %d\n",getpid(),getppid());
	_exit(i);
  }else{
	pid_t childpid = wait(&status);
	if(WIFEXITED(status)){
	printf("Pai: Eu sou o pai o meu id é %d e o meu filho é %d\n-----NºOrdem: %d------\n",getppid(),childpid,WEXITSTATUS(status));
  }
	else{
		printf("exit error from son!");
	}
  }
	i++;
  }
  return 0;
}
