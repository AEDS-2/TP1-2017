/* ------ TADs - Fila */
typedef struct tadCFila *pFila;
typedef struct tadCFila {
	int key;
	pFila Nxt;
}tCFila;

typedef struct tadFila {
	pFila First, Last;
} tFila;

/* ------ TADs - Pilha */
typedef struct tadCPilha *pPilha;
typedef struct tadCPilha {
	int key;
	pPilha Nxt;
} tCPilha;
typedef struct tadPilha {
	pPilha Bottom, Top;
	int size;
} tPilha;