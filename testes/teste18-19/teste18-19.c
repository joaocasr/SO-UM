## Teste 2018-2019
/*
1-
 O algoritmo de escalonamento round robin é bastante popular devido ao caracter pratico de sua implementacao, por outro lado, é uma boa estratégia para contornar casos de starvation.
 Tomemos um caso pratico em que temos um processo com prioridade máxima, se este processo possuir ummaior trabalho este vai possuir um maior tempo do cpu acabando por sacrificar
 outros processos com prioridades inferiores. Estes casos, em escalonamento round robin não ocorrem, porem casos de starvation sao possiveis em short job first,
 ja que processos mais longos irao ficar para tras na fila de espera. Em RR o trabalho é distribuido igualmente pelos processos, não penalizando processos que podem ser mais longos. 
 Em SJF é necessario saber antecipadamente a duracao da execucao de um processo/job e guardar o tempo decorrido o que acaba por resultar num maior overhead.

2- Quando temos um ou mais programas que pedem ao sistema operativo mais memoria do que aquela existente na RAM, podemos dividir os nossos programas em pedacos(overlays) 
atraves da estrategia de memoria virtual. Os overlays que estao a ser executados sao mantidos em memoria principal, enquanto que os outros em disco. 
Deste modo apenas os pedacos de codigo que estao a ser executados nesse momento estao em memoria principal, evitando carregar tudo para memoria o que leva a um maior custo,
nomeadamente, ao caso referido de atrasos da execucao de programas, devido ao maior tempo que este procedimento leva.

 */
