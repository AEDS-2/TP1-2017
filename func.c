#include <stdlib.h>
#include <stdio.h>
#include <biblioteca.h>

/* ------ Funcoes relacionadas a Filas */
// Cria nova fila vazia
void criaFila (tFila *Fila) {
	Fila->First = (tCFila *)malloc(sizeof(TContent));
	Fila->Last = Fila->First;
	Fila->First->Nxt = NULL;
}
//.

// Enfileirar nova pessoa
void enfileiraPessoa () {
	
}
//.

/* ------ Funcoes relacionadas a Pilhas */



