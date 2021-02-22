/*
*	Autora: Mariana Moreira dos Santos
*	Informatica Biomedica - GRR20186554 
*	Ultima atualização: 15 de dez, 2020. 23:45.
*
*	Trabalho Pratico 01: Implementacao do algoritmo VRing no ambiente de simulação SMPL.
*
*/

#include <stdio.h>
#include <stdlib.h>

// Biblioteca de simulacao do MIT
#include "smpl.h"

// Eventos
#define TEST 1
#define FAULT 2
#define RECOVERY 3

// Intervalo de teste
#define TIME_INTERVAL 30.0

// Quantidade maximo de tempo que a simulacao deve rodar
#define MAX_TIME 300.0

// Estados
#define INDEFINIDO -1
#define SEM_FALHA 0
#define COM_FALHA 1

// Descritor do processo
typedef struct {
	// Identificador de facility do SMPL
	int id;		

	// Vetor state que indica estado do processo
	int *STATE;

	// Quantidade de testes realizada pelo processo
	int tests;
} TipoProcesso;

// Ponteiro
TipoProcesso *processo;

int main (int argc, char *argv[]) {
	// N: numero de processos, token: processo que esta sendo executado
	static int N, token, event, r, i, testado;

	// Numeros de processos com falha, n de processos sem falha, rodada
	static int nf = 0, nsf = 0, rodada = 0;

	// Nome da facility
	static char fa_name[5];

	// Caso o input esteja errado
	if(argc != 2) {
		puts ("O input inserido está errado. O uso corretor é o seguinte: tempo <número de processos>");
		exit(1);
	}

	// N recebe o numero de processos inserido pelo usuario
	N = atoi(argv[1]);


	printf("===========================================================\n"); 
 	printf("Algoritmo VRing\n");
  	printf("Aluna: Mariana Moreira dos Santos\n");
  	printf("Disciplina: Sistemas Distribuidos\n");
  	printf("Ultima Modificacao: 15/12/2020\n");
  	printf("===========================================================\n\n"); 

	printf("----------------------------------------------------------- \n");
	printf("Existem %d processos no sistema.\n", N);
	printf("O tempo do intervalo de testes é de %4.1f unidades de tempo.\n", TIME_INTERVAL);
	printf("O tempo máximo de execução é de %4.1f unidades de tempo.\n", MAX_TIME);
	printf("----------------------------------------------------------- \n");
	printf("\n");

	smpl(0, "Tarefa 04 - VRing");
	reset();

	// Indica que existe apenas uma thread trabalhando
	stream(1);

	// Alocacao de memoria para N processos
	processo = (TipoProcesso *) malloc(sizeof(TipoProcesso) * N);

	// Inicializando os processos
	for (i = 0; i < N; i++){
		// Copia a string para o fa_name
		memset(fa_name, '\0', 5);

		// Envia a saída formatada para uma string
		sprintf(fa_name, "%d", i);

		// Setando o ID para o SMPL
		processo[i].id = facility(fa_name, 1);

		processo[i].STATE = (int*) malloc(sizeof(int)*N); 

		// Inicializa o STATE do proprio processo como SEM_FALHA
		processo[i].STATE[i] = SEM_FALHA;

		// Inicializa o STATE de todos os outros processos como INDEFINIDO (-1)
		for(int j = 1; j < N; j++){ 
			processo[i].STATE[(i+j) % N] = INDEFINIDO;
		}

		processo[i].tests = 0;
	}

	// Escalonamento inicial de eventos
	// Nossos processos vao executar testes em intervalos detestes
	// O intervalo de testes vai ser de 30 unidades de tempo
	// A simulacao começa no tempo 0 e vamos escalonar o primeiro teste 
	// de todos os processos para o tempo 30

	for (i = 0; i < N; i++){
		schedule (TEST, TIME_INTERVAL, i);
	}

	 schedule(FAULT, 31.0, 0);
	 schedule(FAULT, 90.0, 2);
	 schedule(FAULT, 110.0, 3);
	 schedule(RECOVERY, 120.0, 0);
	 schedule(RECOVERY, 130.0, 2);
	 schedule(RECOVERY, 140.0, 3);

	while (time() < MAX_TIME){
		// Retorna o ID do processo que esta sendo executado
		// e qual evento ele esta executando
		cause(&event, &token);

		// Dependendo do evento, faca..
		switch(event) {

			// Test
			case TEST:
				// Testa proximo no anel
				testado = (token+1)%N;

				// Se o processo esta falho, nao testa 
				if (status(processo[token].id) != 0)
					break;

				// Exibe o vetor STATE do processo atual (token) 
				printf("Vetor STATE do processo %d\n>> ", token);
				for(int j = 0; j < N; j++)
					printf("%d ", processo[token].STATE[j]);
				printf("\n");

				
				// Procurando processo sem-falha
				for(i = 0; i < N; i++) {

					// Incremente quantidade de testes realizados pelo processo
					processo[token].tests++;

					if(status(processo[testado].id) != 0) {
						// Se falho, entao atualiza valor de STATE para 1 e exibe mensagem
						processo[token].STATE[testado] = COM_FALHA;
						printf("O processo %d encontrou o processo %d FALHO no tempo %5.1f e continuou a procurar\n", token, testado, time());
	                    printf("O valor de STATE do processo %d foi atualizado para 1 (COM FALHA)\n", testado);
	                    printf("------\n");

	                    nf++;

	                    // Incrementa ate achar um sem-falha
						testado++;
					}
					//Se processo a ser testado nao for o atual (token), entao encontrou um processo sem-falha
					else if(testado != token) {
						//Se sem-falha, atualiza valor de STATE para 0 e exibe mensagem
						processo[token].STATE[testado] = SEM_FALHA;
						printf("O processo %d encontrou o processo %d SEM-FALHA no tempo %5.1f\n", token, testado, time());
	                    printf("O valor de STATE do processo %d foi atualizado para 0 (SEM FALHA)\n", testado);
	                    printf("------\n");

	                    nsf++;

	                    // Atualiza o vetor STATE de token com as informacoes do processo sem-falha encontrado
	                    for(int j = 0; j < N; j++) {
	                    	// Obtem apenas informacoes dos processos que ainda nao testou
							if(processo[token].STATE[j] == INDEFINIDO) {
								processo[token].STATE[j] = processo[testado].STATE[j];
							}
						}
						break;
					}
				}
				if (nsf + nf == N) {
					// Completou uma rodada
				 	rodada++;
			 		nsf = nf = 0;
		 			printf("\n....Fim da rodada %d....\n\n", rodada);
				}

				schedule(TEST, TIME_INTERVAL, token);
				break;

			// FAULT
			case FAULT:
				r = request (processo[token].id, token, 0);
				if (r != 0) {
					// Isso ocorre caso a gente tenha esquecido de que ele já falhou antes
					printf("Não foi possível falhar o processo %d", token);
					exit (1);
				}
				printf("O processo %d falhou no tempo %4.1f\n", token, time());
				break;

			// Recovery
			case RECOVERY:
				release(processo[token].id, token);
				printf ("O processo %d recuperou no tempo %4.1f\n", token, time());
				schedule (TEST, TIME_INTERVAL, token);
				break;
		}
	}

	printf("\n\n ----------- Fim da Simulação  -----------\n\n");
	printf("Resultados: \n");
	for(int j = 0; j < N; j++)
			printf("Numero de testes executados pelo processo %d: %d\n", j, processo[j].tests);
		printf("\n");

	printf("\nNumero de rodadas completas de testes durante a simulacao: %d\n\n", rodada);

	return 0;
}
