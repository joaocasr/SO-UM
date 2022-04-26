

Desafectação forçada -> ocorre quando o SO retira o CPU de um processo para dar a outro(mais curto).
			Este conceito ocorre em escalonamentos preemptive. Isto permite
			que todos os processos tenham um tempo de CPU equilibrado e permite
			correr varios processos em simultaneo,muito bem como dar tempos de 
			resposta muito rápidos a processos que são prioritários

Interrupcao -> Ocorre quando temos um processo que se encontrava running e que passou para ready.
O seu estado fica guardado e fica numa fila de espera. O processo fica
interrumpido devido a um por exemplo sinal de evento I/O.

Quando uma página necessária para a execução de um processo não se
encontra numa frame ocorre um "page fault". Quando este fenomeno
ocorre com maior frequencia temos o que é designado por "thrashing".
Temos que a localidade de um processo é o conjunto de
paginas que este utiliza num determinado periodo de tempo. Assim, a 
quando a soma do tamanho das localidade é superior ao tamanho da
memoria principal temos "thrashing".

Em sistemas de memória virtual quando o espaço de enderecamento de um dado programa
é maior que o tamanho da memória principal livre, ocorre a alocacao de blocos(paginas)
para memoria secundaria sendo carregado para memoria principal execertos de codigo que queremos executar.
Só carregamos paginas da memoria secundaria à medida que necessitamos
como sabemos carregar paginas da memoria principal para secundaria e vice versa 
representa um elevado custo por parte do cpu, o que causam um gasto de tempo de cpu.Quando
este fenomeno ocorre excessivamente podemos ter varios processos a aceder aos mesmos recursos
que se encontram em memoria. Nestes casos,"thrashing" é inevitável.
	Solucao? Diminuir o número de processos?



