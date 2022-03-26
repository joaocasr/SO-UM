#include <unistd.h>
#include <sys/wait.h>
/* chamadas ao sistema: defs e decls essenciais */
/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int mySystem(char *comandos[]){
ssize_t pid,ret;
if((pid=fork())==0){
	ret = execvp(comandos[0],comandos);
	_exit(ret);
}else{
  ssize_t child = wait(NULL);
  if(ret>0) return pid;
}
}


int main(int argc, char * argv[]){
        int i=0;
        int c=0;
        char * comandos[10]={0};
        char *resto;
    while( ( resto= strsep(&argv[1]," ")) != NULL ){
        comandos[c]=strdup(resto);
        c++;
}
	mySystem(comandos);
	printf("O filho saiu com código 0.");
return 0;
}
