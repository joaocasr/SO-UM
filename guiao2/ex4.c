#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]){
  pid_t pid;
  int i=1;
  while(i<=20){
  if((pid=fork())==0){ // fork retorna 0 ao processo filho
	  //Código do filho 
	_exit(i);
  }
  i++;
  }
  pid_t childpid;
  int status;
  while((childpid=wait(&status))!=-1){
      printf("Filho %d terminou com codigo de saida -> %d\n", childpid, WEXITSTATUS(status));
       }
  return 0;
}
