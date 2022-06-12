#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[]){
int i=1;
int j=0;
int c=0;
char ch;
    char *aux = malloc(sizeof(200));
        while(argv[i][j]){
         ch=argv[i][j];
         aux[j]=tolower(ch);
         j++;
        }
        write(1,aux,strlen(aux));
return 0;
}

