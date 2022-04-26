/*
 1-
 ** Em sistemas Linux o acesso a ficheiros de um grupo ou utilizadores é restringido devido à existência de permissões.
 Estas permissões apenas atribuem certos previlégios a um user. Estas podem ser de escrita, leitura ou de execução. 
 Estas permissões são validadas no open. Só depois da validacao sem erros é que se podem realizar system calls read ou write e mesmo o exec necessita de abrir um ficheiro (ex: diretoria bin/ ). 
 No momento de fazer o system call open determina-se se o programa pode aceder a um recurso atraves da verificacao das permissoes do user que executou o programa. 
 Em Linux cada utilizador é identificado por um id, que é registado pelo sistema. (Ex.: num ficheiro de passwords). 
 Assim, uma solucao seria a autenticacao atraves de passwords aquando o login, desta forma se poderia verificar se um dado user era o dono ou um membro que possuia certos previlegios sobre o ficheiro ou um diretorio em causa.
 -> Exemplo pratico: Ataques ransomware- usualmente a informacao de uma maquina é acedida e encriptada e é feito um resgate monetario em troca das chaves de decriptacao.

 ** Realizacao de Backups, tarefa esta que não é feita pelo kernel do sistema operativo, mas sim pelo administrador da maquina
 	-> Redundancia de dados leva a um maior gasto de memoria, porem temos a garantia de ter uma copia segura dos dados
  
 ** Existencia de ataques de carisma buffer overflow exploit direcionados à stack
	Linguages como em C permitem o acesso direto a memória, deste modo,
	se injetarmos mais dados do que a capacidade do buffer, parte dos dados
	poderá ser subscrita por outros dados que introduzimos, podendo colocar endereços
	que correspondem a posições de memória em que se encontra codigo malicioso introduzido
	pelo atacante.Ou seja, nestes ataques é necessario saber a localizaçao do codigo executavel. Uma hipótese seria "randomizar" espacos de endereçamento ou colocar flags em certas
	areas da memoria como executavel ou nao, evitando que se possa executar codigo numa regiao em que não é permitida. Utilizacao de certos compiladores adaptados a estes ataques, utilizacao de scanners e funcoes seguras.....


2-
 ** DeadLocks ocorrem quando temos processos que se encontram dependentes uns dos outros indefinidamente, estes podem se encontrar à espera um dos outros criando um ciclo infinito. 
 Um exemplo concreto seria termos um processo filho que se encontra bloqueado à espera de ler bytes do pipe enquanto que o processo pai se encontra à espera ,com o system call wait, do filho para que este termine com exit 0.
*/

/* Exemplo concreto de um deadlock */

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
/*
 Round Robin 
 -> Escalonamento de processos - permite uma melhor distribuicao de trabalho pelos processos
 	Se um processo conseguir executar um dado programa num certo intervalo de tempo,quantum, este sai da fila.
	Caso contrário, este terá de voltar para a fila de espera em ultimo lugar.
	Este algoritmo permite previnir casos de starvation(em que processos com menor prioridade nao têm tempo de processamento
	pois irao existir sempre processos com maior prioridade,ou seja, mesmo que um processo de menor prioridade esteja ativo, o processo
	com maior prioridade é que vai ter CPU). 

	Esta poderá ser uma boa estratégia apenas num cenario em que os processos conseguem executar os seus respetivos códigos dentro do tempo estipulado
	(já que esta estrategia é projetada para sistemas time-sharing e multitasking).
	Se um dos processos não conseguir executar o seu programa dentro desse quantum este terá de ir para o final da fila.
       	Ou seja, a impressão alternada das linhas especificada na questao (ls-df-find-ls-df-find-....) poderia estar comprometida.

*/
