#include <unistd.h>
#include <sys/wait.h>
/* chamadas ao sistema: defs e decls essenciais */
/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	int ret;
	char *args[3]={"/bin/ls","-l",NULL};

        ret = execl("/bin/ls","ls","-l",NULL);
	//ret = execv("/bin/ls",args);
	//ret = execvp("ls",args);
	//ret = execlp("ls","ls","-l",NULL);

	if(ret>0) printf("Executado com sucesso!");
	return 0;	
}
