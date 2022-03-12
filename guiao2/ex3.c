#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#define SIZE 1024*1024

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
//execucao em cadeia um processo n nao executa se um processo n-1 nao tiver sido executado
//a bash quando faco ./ex3 é um processo o ./ex3 cria um fork em que corre o executavel
//nao existe conteudo partilhado/ os processos filho e pai correm em espacos de enderecamento diferentes
//caso o pai incremente um i=0 para i=1 o filho ve i=0
int main(int argc, char * argv[]){
  pid_t pid;
  int status;
  int i=1;
  char buffer[SIZE];
  while(i<=10){
  pid=fork();
  if(pid==0){ // fork retorna 0 ao processo filho
	  //Código do filho 
	printf("~~~[FILHO] O meu pid é %d e o pid do meu pai é %d\n",getpid(),getppid());
	_exit(i);//indica o código de saida do processo filho ------------> força a saída dos filhos deste código | se nao tiver exit os filhos vao terminar com o return 0
	
  }else{
	pid_t childpid = wait(&status);//so posso avancar para o seguinte se o anterior terminou ----------> força o pai a esperar pelo filho anterior antes de avancar  
	if(WIFEXITED(status)){//conferir se o processo filho já terminou sem erros
	sprintf(buffer,"\n-----Ordem de término: %d------\nPai: Eu sou o pai e o meu id é -> %d e o meu filho é -> %d\n\n",WEXITSTATUS(status),getppid(),childpid);
  	int size = countBytes(buffer,sizeof(buffer));
	write(1,buffer,size);
	}
	else{
		printf("exit error from son!");
	}
  }
	i++;
  }
  return 0;
}
