#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

/* ------ Funcoes relacionadas a Filas */
// Cria nova fila vazia
void criaFila (tFila *Fila) {
	Fila->First = (tCFila *)malloc(sizeof(tCFila));
	Fila->Last = Fila->First;
	Fila->First->Nxt = NULL;
}
//.

// Confere se a fila está vazia
int filaVazia (tFila Fila) {
	return(Fila.First == Fila.Last);
}
// .

// Enfileirar nova pessoa
void enfileiraPessoa (tFila *Fila, int qtd, int s) {
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
void desenfileiraPessoa (tFila *Fila) {
	if (Fila->First == Fila->Last) {
		return;
	}
	pFila pointer = Fila->First;
	Fila->First = Fila->First->Nxt;
	free(pointer);
}
//.

// Implementacao da fila de servir alimentos, para complementar as 4 iterações 
void servingTime (tFila *Fila, int *tamFila, int *contServ) { 
	int i = 0, tamanho = *tamFila;
	pFila pointer;
	pointer = Fila->First->Nxt;
	// varre toda a fila aumentando em uma unidade de tempo o tempo gasto servindo
	while (i < tamanho) { 
		pointer->serving++; 
		pointer = pointer->Nxt;
		i++;
	}
	// .
	i = 0;
	pointer = Fila->First->Nxt; 
	// varre a fila em busca dos totalmente servido, desenfileira e finaliza o servico geral
	while (i < tamanho) { 
		if (pointer->serving == 4) {
			desenfileiraPessoa(Fila);
			*tamFila -= 1;
			*contServ += 1;
		}
		pointer = pointer->Nxt;
		i++;
	}
	free(pointer);
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
void criaPilha (tPilha *Pilha) {
	Pilha->Top = (tCPilha *)malloc(sizeof(tCPilha));
	Pilha->Bottom = Pilha->Top;
	Pilha->Top->Nxt = NULL;
	Pilha->size = 0;
}
//.

// Confere se a pilha esta vazia
int pilhaVazia (tPilha Pilha) {
	return (Pilha.Top == Pilha.Bottom);
}
// .

// Empilha novas bandejas
void empilhaBandeja (tPilha *Pilha, int qtd) {
	int i = 0;
	for (i = 0; i < qtd; i++) {
		if (Pilha->size < 30) {
			pPilha pointer  = (tCPilha *)malloc(sizeof(tCPilha));
			pointer->Nxt = Pilha->Top;
			Pilha->Top = pointer;
			Pilha->size++;
		}
	}
}
// .

// Desempilha uma bandeja
void desempilhaBandeja (tPilha *Pilha) {
	pPilha pointer = Pilha->Top;
	Pilha->Top = pointer->Nxt;
	free(pointer);
	Pilha->size--;
}
// .