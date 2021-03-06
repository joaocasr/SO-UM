#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "pessoas.h"
#include <stdio.h>
#include <ctype.h>
#define buff_size 1024*1024


//File aniversarios.bin working as a database of people's birthday


int main(int argc, char * argv[]){
  int fp1;
  ssize_t wr1;
  struct Pessoa pessoa;

  if(argc!=4){
  	perror("Incorrect number of arguments!");
	exit(1);	
  }
  if(strcmp(argv[1],"-i")==0)
  {
	  if((fp1=open("aniversarios.bin",O_RDWR|O_CREAT|O_APPEND,0660))==-1){
          perror ("Couldn't create/open aniversarios.bin!");
          exit(1);
 	 }
     strcpy(pessoa.nome, argv[2]);
     strcpy(pessoa.data, argv[3]);
     lseek(fp1,0,SEEK_END);
     wr1 =write(fp1,&pessoa,sizeof(struct Pessoa));
     if(wr1<0) perror("erro ao adicionar pessoa!");
     close(fp1);
  }
  else if(strcmp(argv[1],"-u")==0){
	  ssize_t r,wr2;
	  int found = 0;
	  
	  int fd= open("aniversarios.bin",O_RDWR);
	  
	  if (fd<0){
		  perror("error opening aniversarios!");
	  	  exit(1);
	  }
	  while((r=read(fd,&pessoa,sizeof(struct Pessoa)))>0 && found==0){  
	     if(strcmp(pessoa.nome,argv[2])==0){
	           strcpy(pessoa.data,argv[3]);
		   //escrever a struct toda
		   //vai escrever no seguinte/preciso de recuar de posicao com o tamanho da struct
		   lseek(fd,-(off_t) sizeof(pessoa), SEEK_CUR);
		   wr2 = write(fd, &(pessoa), sizeof(struct Pessoa));
		   if(wr2<0) perror("erro ao modificar pessoa!");
		   found = 1;
	       }
	  }
	  close(fd);
  }
  if((system("cat aniversarios.bin")<0)) perror("cat error!");
  return 0;
}
