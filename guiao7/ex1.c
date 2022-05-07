#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ctrlc = 0;
int nsec = 0;

void sigint_handler(int signum){
    printf("\nTime: %d seconds\n", nsec);
    ctrlc++;
}

void sigquit_handler(int signum){
    printf("\nCarregou Ctrl+C %d vezes\n", ctrlc);
    _exit(0);
}

void sigalrm_handler(int signum){
    	nsec++;
	alarm(1);
}

void sigterm_handler(int signum){
	printf("Sinal SIGTERM recebido!");
}


int main(){
    if(signal(SIGINT,sigint_handler) ==SIG_ERR){
        printf("error\n");
        exit(1);
    }
    if(signal(SIGQUIT,sigquit_handler) == SIG_ERR){
        printf("error\n");
        exit(1);
    }
    if(signal(SIGALRM,sigalrm_handler)==SIG_ERR){
    	printf("error\n");
	exit(1);
    }
    
     if(signal(SIGTERM,sigterm_handler)==SIG_ERR){
        printf("error\n");
        exit(1);
    }

    
    alarm(1);
    while(1){
	 pause();
    	//sleep(1);
	//nsec++;
	//pause(); nao é retomado
	printf("%d secs\n",nsec);
    }

    return 0;
}
