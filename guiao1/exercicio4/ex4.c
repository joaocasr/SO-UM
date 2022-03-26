#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define buff_size 1024*1024

/*
ssize_t readln(int fd, char *line, ssize_t size){
 ssize_t i;
 ssize_t bRead;
 for(i=0;i<size;i++){
   bRead = read(fd,&line[i],1);
   if(line[i]=='\n' || bRead <=0) break;
 }
  return i;
}
*/

ssize_t readln(int fd, char *line, ssize_t size){
 ssize_t i=0;
 ssize_t bRead;
 while(i<size && read(fd,&line[i],1)>0){
   i++;
   if(line[i-1]=='\n') return i;
 }
}

int main(int argc, char *argv[]){
  char buffer[buff_size];
  char buffer2[buff_size];
  int i=1;
  ssize_t fread;
  while((fread=readln(0,buffer,buff_size))>0){//while number of bytes read greater than 0 | when is only written '\n' number of bytes read equal to 0
	  //fread->number of bytes read in buffer
	 if(buffer[0]!='\n' && fread<=buff_size){
	 sprintf(buffer2,"\t%d  ",i);//int sprintf(char *str, const char *format, ...) sends formatted output to a string pointed to, by str.
	 write(1,buffer2,strlen(buffer2));
	 write(1,buffer,fread);
	 i++;
	 }
	 else write(1,buffer,fread);
	 }
  return 0;
}
