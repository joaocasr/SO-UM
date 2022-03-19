#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int procura(int** m,int r,int x,int N){
	int i;
	for(i=0;i<N;i++){
	   if(m[r][i]==x) return 1;
	}
	return 0;
}


int main(int argc, char * argv[]){
int linhas = 10;
int colunas =1000;
int ** matrix = (int ** ) malloc(sizeof(int*) * linhas);
for(int i=0;i<linhas;i++){
 matrix[i]=(int *) malloc(sizeof(int) * colunas);
 for(int j=0;j<colunas;j++){
   matrix[i][j] = rand() % 1000;
 }
}

int x = atoi(argv[1]);
int status;
int k=0;
int r,y;
while(k<linhas){
pid_t child=fork();
if(child==0){
	if(procura(matrix,WEXITSTATUS(status),x,colunas)==1){;
	 _exit(k);
	}
	else _exit(-1);
}
k++;
}
pid_t pidchild;
int c=0;
int * aux=(int *) malloc(sizeof(int) * linhas);
for(int l=0;l<linhas;l++){
 	if(WEXITSTATUS(status)!=-1){	
		pidchild = wait(&status);
		aux[c]=WEXITSTATUS(status); 
		c++;	
	}
}
	for(int j=0;j<sizeof(aux);j++) printf(" %d ",aux[j]);
return 0;
}
