
/*
No caso dos pipes, o EOF apenas é enviado assim que não existir nenhum descriptor de escrita aberto. 
Como processo filho está num while a tentar ler do pipe, este vai ficar bloqueado se não houver conteúdo no pipe mas o descritor de escrita (pipe_fd[1]) ainda estiver aberto. 
Como o processo pai lança o processo filho e fica logo à espera que este termine, sem antes fechar o descritor de escrita do pipe, criamos aqui um deadlock. 
O processo pai fica à espera que o processo filho termine, algo que só iria acontecer se o processo filho recebesse um EOF do pipe. 

Se experimentarmos fechar o pipe_fd[1] no pai antes do wait podemos verificar que o programa termina sem problemas.
 
*/

int main(int argc, char const *argv[]) {
        int pipe_fd[2];
        ssize_t pid,bytes_read;
        int status;
        char buffer[size];
        if(pipe(pipe_fd) == -1) {
                perror("error creating pipe");
                exit(1);
        }
        if((pid = fork()) == 0) {
                close(pipe_fd[1]);
                while(bytes_read = read(pipe_fd[0], buffer, size)>0);
                close(pipe_fd[0]);
                _exit(0);
        } else {
                close(pipe_fd[0]);
                wait(&status);
        }

        return 0;
}

