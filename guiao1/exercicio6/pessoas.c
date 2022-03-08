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


//File aniversarios.txt working as a database of people's birthday


int main(int argc, char * argv[]){
  int fp1;
  ssize_t w1,w2;
  struct Pessoa pessoa;

  if(argc!=4){
  	perror("Incorrect number of arguments!");
	exit(1);	
  }
  if(strcmp(argv[1],"-i")==0)
  {
	  if((fp1=open("aniversarios.txt",O_RDWR|O_CREAT|O_APPEND,0660))==-1){
          perror ("Couldn't create/open aniversarios.txt!");
          exit(1);
 	 }
     strcpy(pessoa.nome, argv[2]);
     strcat(pessoa.nome," ");
     strcpy(pessoa.data, argv[3]);
     strcat(pessoa.data,"\n");
     //ssize_t wr =write(fp1,&pessoa,sizeof(struct Pessoa));
     //if(wr<0) perror("erro ao adicionar pessoa");
     w1=write(fp1,pessoa.nome,strlen(pessoa.nome));
     w2=write(fp1,pessoa.data,strlen(pessoa.data));
     if(w1<0 || w2<0 ){
       perror("couldn't write!");
       exit(1);
     }
     close(fp1);
  }
  else if(strcmp(argv[1],"-u")==0){
	  ssize_t r,w3,w4;
	  int found = 0;
	  
	  int fd= open("aniversarios.txt",O_RDWR,0660);
	  
	  if (fd<0){
		  perror("error opening aniversarios!");
	  	  exit(1);
	  }
	  strcat(argv[2]," ");
	  while((r=read(fd,&(pessoa),sizeof(struct Pessoa)))>0 && found==0){  
	     if(strcmp(pessoa.nome,argv[2])==0){
	           strcpy(pessoa.data,argv[3]);
		   lseek(fd,-(off_t) sizeof(pessoa), SEEK_CUR);
		   w3=write(1,pessoa.nome,strlen(pessoa.nome));
     	    	   w4=write(1,pessoa.data,strlen(pessoa.data));
		   //ssize_t wr2 = write(fp1, &(pessoa), sizeof(struct Pessoa));
		   //if(wr2<0) perror("erro ao modificar data");
	           if(w3<0 || w4){
		   perror("couldn't write!");
		   exit(1);
		   }
		   found = 1;
	       }
	  }
	  close(fd);
  }
  if((system("cat aniversarios.txt")<0)) perror("cat error!");
  return 0;
}
