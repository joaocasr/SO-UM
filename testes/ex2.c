#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

#define size 1024

typedef struct notas{
	int nota;
	char * numero;
}*Notas;

struct notas n[size];

int readln(int fd, char * buffer, int size){
int i=0;
while(i<size && read(fd,&buffer[i],1)>0)
	i++;
	if(buffer[i-1]!='\n') return i;
}


int main(int argc, char * argv){
  char buffer[size];
  int fd1;
  if((fd1=open(argv[2],O_RDONLY))==-1){
  	perror("Não foi possivel abrir o ficheiro.");
	exit(-1);
  }
  int bytes_read;
  int i=0;
  while((bytes_read=readln(fd1,buffer,size))>0){
  	  buffer=buffer+1;
	  n[i].nota=atoi(strsep(&buffer,">"));
	  buffer=buffer+1;
	  n[i].numero=strdup(strsep(&buffer,">"));
	  i++;
  }
  //criar 10 forks 
  //1 fork para para salvaguadar codigo apos exec
  //wait dos 10 filhos idk

}
