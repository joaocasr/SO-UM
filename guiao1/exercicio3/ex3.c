#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#define BUFFER_SIZE 1024*1024


ssize_t readln(int fd, char *line, ssize_t size){
 ssize_t i;
 ssize_t bRead;
 for(i=0;i<size;i++){
   bRead = read(fd,&line[i],1);
   if(line[i]=='\n' || bRead <=0) break;
 }
  return i+1;
}

/*
ssize_t readln(int fd, char *line, ssize_t size){
 ssize_t i=0;
 ssize_t bRead;
 while(i<size && read(fd,&line[i],1)>0){
   i++;
   if(line[i-1]=='\n') return i; 
 }
}
*/

int main(int argc, char *argv[]){
char buffer[BUFFER_SIZE];
ssize_t a= readln(0,buffer,BUFFER_SIZE);
write(1,buffer,a);
return 0;
}
