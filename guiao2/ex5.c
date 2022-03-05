#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int procura(int m[5][30],int r,int x){
	int i;
	for(i=0;i<5;i++){
	   if(m[i][r]==x) return 1;
	}
	return 0;
}


int main(int argc, char * argv[]){
int i=1;
int matrix[5][30]= {
{59,56,46,85,51,29,71,19,79,43,70,45,91,16,76,11,39,69,23,60,92,85,83,74,44,22,91,10,43,64},
{27,45,41,98,96,97,95,89,72,44,58,19,29,63,86,85,27,67,51,63,82,25,68,30,64,23,29,71,57,74},
{70,31,96,67,93,22,72,88,20,93,49,36,16,19,70,78,65,95,85,0,62,41,77,47,16,50,94,89,46,88},
{62,16,54,44,26,12,49,52,98,83,50,22,43,53,23,40,22,88,66,83,43,44,25,72,84,52,74,76,51,95},
{84,78,51,91,60,21,15,13,18,24,23,15,16,16,76,27,98,41,44,54,93,40,98,28,45,37,47,48,53,29}
		   };

int x = atoi(argv[1]);
while(i<=30){
pid_t pid=fork();
if(pid==0){//esta a ocorrer o processo filho
	_exit(i);
}
i++;
}
pid_t pidchild;
int status;
int r=0;
int n=0;
while((pidchild=wait(&status))!=-1){
       	if (procura(matrix,WEXITSTATUS(status),x)==1){
	       	printf("EXISTEEE!");
		r=1;
		break;
	}
	printf("%d - status: %d\n",n,WEXITSTATUS(status));
	n++;
}
if(r==0) printf("Não existe!");
return 0;

}
