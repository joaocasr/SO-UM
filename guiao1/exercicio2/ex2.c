#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdlib.h>
#include <errno.h>

#define buff_size 1024*1024

int main(int argc, char *argv[]){
  char buffer[buff_size];
  ssize_t fread;
  while((fread=read(0,buffer,buff_size))>0){
       //escritor do ficheiro do stdin a 1 para o read
      write(1,buffer,fread);
      //escritor do ficheiro do stdout a 0 para o write
  }
}
