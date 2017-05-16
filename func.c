#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

/* ------ Funcoes relacionadas a Filas */
// Cria nova fila vazia
void criaFila (tFila *Fila) { printf("essa funcao foi 1\n");
	Fila->First = (tCFila *)malloc(sizeof(tCFila));
	Fila->Last = Fila->First;
	Fila->First->Nxt = NULL;
}
//.

// Enfileirar nova pessoa
void enfileiraPessoa (tFila *Fila, int qtd, int s) { printf("essa funcao foi 2\n");
	int i;
	for (i = 0; i < qtd; i++) {
		Fila->Last->Nxt = (tCFila *)malloc(sizeof(tCFila));
		Fila->Last = Fila->Last->Nxt;
		Fila->Last->Nxt = NULL;
	}
	if (s) {
		Fila->Last->serving = 0;
	}
}
//.

// Desenfileirar uma pessoa
void desenfileiraPessoa (tFila *Fila) { printf("essa funcao foi 3\n");
	if (Fila->First == Fila->Last) {
		printf("nao rolou Desenfileirar\n");
		return;
	}
	pFila pointer = Fila->First;
	Fila->First = Fila->First->Nxt;
	free(pointer);
}
//.

// Implementacao da fila de servir alimentos, para complementar as 4 iterações 
void servingTime (tFila *Fila, int *tamFila, int *contServ) { printf("essa funcao foi 4\n");
	int i = 0, tamanho = *tamFila;
	pFila pointer;
	pointer = Fila->First->Nxt;
printf("queeee\n");
	// varre toda a fila aumentando em uma unidade de tempo o tempo gasto servindo
	while (i < tamanho) { printf("han\n");
		pointer->serving++; printf("ajuda lusiano\n");
		pointer = pointer->Nxt;printf("qye\n");
		i++;
	}
	// .

	i = 0;printf("pfvr\n");
	pointer = Fila->First->Nxt; printf("que\n");
	// varre a fila em busca dos totalmente servido, desenfileira e finaliza o servico geral
	while (i < tamanho) { printf("essa funcao foi 5\n");
		printf("user %d\n", pointer->serving);
		if (pointer->serving == 4) {
			desenfileiraPessoa(Fila);
			*tamFila--;
			*contServ++;
		}
		pointer = pointer->Nxt;
		i++;
	}

	// varre fila
	// aumenta o int serving de cada um
	// varre de novo
	// confere os int serving = 4
	// desenfileira os int serving = 4
	// aumenta contador de service done
}
// .

/* ------ Funcoes relacionadas a Pilhas */
// Cria nova pilha vazia
void criaPilha (tPilha *Pilha) { printf("essa funcao foi 6\n");
	Pilha->Top = (tCPilha *)malloc(sizeof(tCPilha));
	Pilha->Bottom = Pilha->Top;
	Pilha->Top->Nxt = NULL;
	Pilha->size = 30; // supondo que a pilha comece cheia
}
//.
// Empilha 10 novas bandejas
void empilhaBandeja (tPilha *Pilha, int *empty) { printf("essa funcao foi 7\n");
	*empty = 0;
	pPilha pointer  = (tCPilha *)malloc(sizeof(tCPilha));
	pointer->Nxt = Pilha->Top;
	Pilha->Top = pointer;
	Pilha->size += 10;
	if (Pilha->size > 30)
		Pilha->size = 30;
}
// .
// Desempilha uma bandeja
void desempilhaBandeja (tPilha *Pilha, int *empty) {printf("essa funcao foi 8\n");
	if (Pilha->Top == Pilha->Bottom) {
		*empty = 1;	
	}
	else {
		pPilha pointer = Pilha->Top;
		Pilha->Top = pointer->Nxt;
		free(pointer);
		Pilha->size--;
	}
}
// .