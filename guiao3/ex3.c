#include <unistd.h>
#include <sys/wait.h>
/* chamadas ao sistema: defs e decls essenciais */
/* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	int ret;
        //char *args[3]={"/bin/ls","-l",NULL};
        //ret = execl("/bin/ls","ls","-l",NULL);
	//ret = execv("/bin/ls",args);
	//ret = execvp("ls",args);
	//ret = execlp("ls","ls","-l",NULL);

ssize_t pid;
int status;
for(int i=1;i<argc;i++){
if((pid=fork())==0){
        ret = execlp(argv[i],argv[i],NULL);
	_exit(ret);
 }
}
ssize_t wret;
for(int i=1;i<argc;i++){
	wret = wait(NULL);
}
return 0;	
}
