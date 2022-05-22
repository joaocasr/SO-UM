#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

bool vacinado(char* cidadao){
int i,r;
int pid;
int arr[10];
char filename;
bool exists=false;

for(i=0,i<100,i++){ //criar 100 processos para executarem em concorrencia e pesquisarem nos 100 arquivos(100 regioes)
  if((pid=fork())==0){
    sprintf(filename,"regiao_%d",i);	   
    r=exclp("grep","grep",cidadao,filename,NULL);    
    arr[i]=pid;
    _exit(r);	    
  }
 }

int status;
while(wait(&status)!=-1){
 if(WEXITSTATUS(status)==0){
	exists=true; 
 	for(i=0,i<10,i++){
	 kill(arr[i],SIGKILL);
	}
	printf("Cidadao já foi vacinado.");
 }
}
return exists;
}
