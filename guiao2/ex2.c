#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#define SIZE 100
/*STDERR_FILENO
    File number of stderr; 2.
STDIN_FILENO
    File number of stdin; 0.
STDOUT_FILENO
    File number of stdout; 1
    */


int countBytes(char buff[],int tam){
int c=1;
ssize_t bread;
int i;
for(i=0;i<tam;i++){
   if(buff[i]=='\0') break;
   c++;
}
return c;
}


int main(int argc, char * argv[]){
  pid_t pid,ant;
  pid = fork();
  char buffFilho[SIZE];
  char buffPai[SIZE];
  if(pid==0){ // fork retorna 0 ao processo filho
	  //Código do filho
	sprintf(buffFilho, "[Fillo]Pid:%d , [Filho] Pid pai:%d\n",getpid(),getppid());
	int tam = countBytes(buffFilho,sizeof(buffFilho));
	write(1,buffFilho,tam);
  }else{//apos o filho terminar
	  //Código do pai
        sprintf(buffPai, "[Pai] Pid:%d , [Pai] Pid pai:%d [Pai] Pid filho: %d\n",getpid(),getppid(),pid);
        int tam = countBytes(buffPai,sizeof(buffPai));
        write(1,buffPai,tam);
  }
  return 0;
}
