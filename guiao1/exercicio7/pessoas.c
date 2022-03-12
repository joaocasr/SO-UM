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


int countBytes(char buff[],int tam){
int c=1;
int i;
for(i=0;i<tam;i++){
   if(buff[i]=='\0') break;
   c++;
}
return c;
}

//File aniversarios.bin working as a database of people's birthday


int main(int argc, char * argv[]){
  int fp1;
  ssize_t wr1,wr3;
  struct Pessoa pessoa;
  char buffer[buff_size];

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
     sprintf(buffer,"Registo - %ld\n",(lseek(fp1,0,SEEK_END)/sizeof(struct Pessoa)+1));
     wr1 =write(fp1,&pessoa,sizeof(struct Pessoa));
     if(wr1<0) perror("erro ao adicionar pessoa!");
     wr3=write(1,buffer,countBytes(buffer,sizeof(buffer)));
     if(wr3<0){
	     perror("Erro ao adicionar pessoa!");
     }
     close(fp1);
  }
  else if(strcmp(argv[1],"-o")==0){
	  ssize_t wr2;
	  int n = atoi(argv[2]);
	  
	  int fd= open("aniversarios.bin",O_RDWR);
	  
	  if (fd<0){
		  perror("error opening aniversarios!");
	  	  exit(1);
	  }
		   lseek(fd, (n-1) * sizeof(pessoa), SEEK_CUR);
		   read(fd,&pessoa,sizeof(struct Pessoa));//ao fazer o read o apontador passa a apontar para a proxima struct pessoa
		   strcpy(pessoa.data,argv[3]);
		   lseek(fd, -(off_t) sizeof(pessoa), SEEK_CUR);
		   wr2 = write(fd,&pessoa, sizeof(struct Pessoa));
		   if(wr2<0) perror("erro ao modificar pessoa!");
	  close(fd);
  }
  //if((system("cat aniversarios.bin")<0)) perror("cat error!");
  return 0;
}
