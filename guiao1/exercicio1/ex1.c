#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */ 
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024*1024
/*
 *escritores de ficheiros a apontar para tabela de ficheiros---open
 * vptr a apontar para tabela de info dos ficheiros
 *
 *permissoes de ficheiro rw-(owner)(nao tem permissoes de execucao)r--(group)r--(others)
 *
 *
 * */
int main(int argc , char * argv[]){
char buffer[BUFFER_SIZE];
int fp1,fp2;

if((fp1=open(argv[1],O_RDONLY))==-1){
  perror("Couldn't open the source file!");
  exit(1);
}
if((fp2=open(argv[2],O_CREAT| O_TRUNC| O_WRONLY,0640))==-1){
	/*
	 * 0640 -> permission bits of a file and  only used when the file is actually created(does not exist).
         * using 0640 will create a file that is Read/Write for owner, and Read Only for everyone else
	 * */
  perror("Couldn't create destiny file!");
  exit(1);
}
 int fread;
 while((fread=read(fp1,buffer,BUFFER_SIZE))>0){
      write(fp2,buffer,fread);   
      //1argumento escritor de ficheiro
      //vamos escrever a quantidade de bytes lidos
}
close(fp1);
close(fp2);
return 0;
}
