#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

int main() {  
    // criacao das filas (caixa e bandeja) e pilha (de bandejas)
    tFila *filaCaixa = (tFila *)malloc(sizeof(tFila));
    criaFila(filaCaixa);
	tFila *filaBandeja = (tFila *)malloc(sizeof(tFila));
    criaFila(filaBandeja);
    tPilha *pilhaBandeja = (tPilha *)malloc(sizeof(tPilha));
    criaPilha(pilhaBandeja);
    tFila *filaServing = (tFila *)malloc(sizeof(tFila));
    criaFila(filaServing);
	// .
	// criacao de variaveis auxiliares
    int time = 0, contReplaceTime = 0, contCustomers = 0, contServiceDone = 0, tamFila = 0;
	// .
	
	// empilhamento inicial de bandejas (supondo que comece com 30)
	empilhaBandeja(pilhaBandeja, 30);
	// .

	// repeticao referente ao tempo limite de análise (4 horas = 240 iterações)
	do {
		// manutencao dos contadores de tempo e tempo de reposicao
		time++;
		contReplaceTime++;
		contCustomers += 2;
		// .

		// manutencao de pilhas/filas : entrada e saida padrao de objetos de acordo com o tempo
		enfileiraPessoa(filaCaixa, 2, 0); // entrada de duas pessoas na fila do caixa a cada unidade de tempo
		if (contReplaceTime == 12) { // reposicao de bandejas a cada 12 unidades de tempo
			contReplaceTime = 0;
			empilhaBandeja(pilhaBandeja, 10);
		}
		// .

		// manutencao do tempo servindo alimentos
		if (!filaVazia(*filaServing)) {
			servingTime (filaServing, &tamFila, &contServiceDone);
		}
		// .

		// confere pilha de bandejas; se houver bandeja na pilha, desenfileira uma pessoa da fila de bandejas e enfileira na de servirpilhaBandeja));
		if (!filaVazia(*filaBandeja) && !pilhaVazia(*pilhaBandeja)) {
			desenfileiraPessoa(filaBandeja);
			desempilhaBandeja(pilhaBandeja);
			enfileiraPessoa(filaServing, 1, 1);
			tamFila++;
		}
		// .

		// desenfileira uma pessoa da fila do caixa a cada unidade de tempo
		desenfileiraPessoa(filaCaixa);
		enfileiraPessoa(filaBandeja, 1, 0);
		// .
	} while (time<240);
	// .

	printf("Numero de pessoas servidas em 4 horas = %d\nClientes totais = %d", contServiceDone, contCustomers);

    return 0;  
}