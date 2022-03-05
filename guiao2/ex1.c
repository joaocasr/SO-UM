#include <unistd.h>
#include <sys/wait.h>
/* chamadas ao sistema: defs e decls essenciais */
/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define size 50

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


int main(int argc, char * argv[]){
pid_t pid,pidpai;
pid = getpid();
pidpai= getppid();
char buffer[size];
sprintf(buffer, "PID[fillo]:%d , PID[pai]:%d\n",pid,pidpai);//comando sprintf | posso usar(?)
int tam = countBytes(buffer,sizeof(buffer));
write(1,buffer,tam);
return 0;
}
