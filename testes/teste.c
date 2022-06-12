#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#define SIZE 1024

int main(int argc,char * argv[]){
	char * msg ="sdijsajdia";
	execl("upper","upper",msg,NULL);
return 0;
}
