#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

int main()  
{  
    // criacao das filas (caixa e bandeja) e pilha (de bandejas)
    tFila *filaCaixa = (tFila *)malloc(sizeof(tFila));
    criaFila(filaCaixa);
	tFila *filaBandeja = (tFila *)malloc(sizeof(tFila));
    criaFila(filaBandeja);
    tPilha *pilhaBandeja = (tPilha *)malloc(sizeof(tPilha));
    criaPilha(pilhaBandeja);
    tFila *serving = (tFila *)malloc(sizeof(tFila));
    criaFila(serving);
	// .
	// criacao de variaveis auxiliares
    int time = 0, contReplaceTime = 0, contServiceDone = 0, pilhaVazia = 0, tamFila = 0;
	// .
	
	// repeticao referente ao tempo limite de análise (4 horas = 240 iterações)
	do {
		// manutencao dos contadores de tempo e tempo de reposicao
		time++;
		contReplaceTime++;
		// .
printf("aqui foi\n");
		// manutencao de pilhas/filas : entrada e saida padrao de objetos de acordo com o tempo
		enfileiraPessoa(filaCaixa, 2, 0); // entrada de duas pessoas na fila do caixa a cada unidade de tempo
		if (contReplaceTime == 12) { // reposicao de bandejas a cada 12 unidades de tempo
			contReplaceTime = 0;
			empilhaBandeja(pilhaBandeja, &pilhaVazia);
		}
		// .
printf("manutencao 1\n");
		// manutencao do tempo servindo alimentos
		servingTime (serving, &tamFila, &contServiceDone);
		// .
printf("manu 2\n");		
		// confere pilha de bandejas; se houver bandeja na pilha, desenfileira uma pessoa da fila de bandejas e enfileira na de servir
		if (!pilhaVazia) {
			desenfileiraPessoa(filaBandeja);
			desempilhaBandeja(pilhaBandeja, &pilhaVazia);
			enfileiraPessoa(serving, 1, 1);
			tamFila++;
		}
		// .
printf("pilha\n");
		// desenfileira uma pessoa da fila do caixa a cada unidade de tempo
		desenfileiraPessoa(filaCaixa);
		enfileiraPessoa(filaBandeja, 1, 0);
		// .
printf("e caixa\n");		
	} while (time<=240);
	// .

	printf("Numero de pessoas servidas em 4 horas = %d\n", contServiceDone);

    return 0;  
}