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

        //ret = execl("/bin/ls","ls","-l",NULL);
	//ret = execv("/bin/ls",args);
	//ret = execvp("ls",args);
	//ret = execlp("ls","ls","-l",NULL);

ssize_t pid;
int status;
if((pid=fork())==0){
        ret = execl("/bin/ls","ls","-l",NULL);
	_exit(ret);
}else{
	ssize_t wret = wait(&status);

}
	return 0;	
}
