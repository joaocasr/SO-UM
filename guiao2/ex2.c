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
  pid = fork();// o fork devolve o pid do filho
  char buffFilho[SIZE];
  int i=0;
  char buffPai[SIZE];
  if(pid==0){ // fork retorna 0 ao processo filho
	  //Código do filho
	i++;
	printf("variavel nao partilhada filho i=%d\n",i);
	sprintf(buffFilho, "[Fillo]Pid:%d , [Filho] Pid pai:%d\n",getpid(),getppid());
	int tam = countBytes(buffFilho,sizeof(buffFilho));
	write(1,buffFilho,tam);
  }else{//apos o filho terminar
	  //Código do pai
	  //como nao tem um wait o filho vai ficar orfao
        i--;
	printf("variavel nao partilhada pai i=%d\n",i);
	sprintf(buffPai, "[Pai] Pid filho:%d , [Pai] Pid pai:%d [Pai] Pid: %d\n",pid,getpid(),getppid());
        int tam = countBytes(buffPai,sizeof(buffPai));
        write(1,buffPai,tam);
  }
  return 0;
}
