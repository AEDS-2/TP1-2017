/* ------ TADs - Fila */
typedef struct tadCFila *pFila;
typedef struct tadCFila {
	int serving, tempoAtend;
	pFila Nxt;
}tCFila;

typedef struct tadFila {
	pFila First, Last;
} tFila;

/* ------ TADs - Pilha */
typedef struct tadCPilha *pPilha;
typedef struct tadCPilha {
	pPilha Nxt;
} tCPilha;
typedef struct tadPilha {
	pPilha Bottom, Top;
	int size;
} tPilha;

/* ------ Cabecalho das funcoes */
// Funcoes de Fila
void criaFila (tFila *Fila);
void enfileiraPessoa (tFila *Fila, int qtd, int s);
void desenfileiraPessoa (tFila *Fila);
void servingTime (tFila *Fila, int *tamFila, int *contServ);
int filaVazia (tFila Fila);
// .

// Funcoes de Pilha
void criaPilha (tPilha *Pilha);
void empilhaBandeja (tPilha *Pilha, int qtd);
void desempilhaBandeja (tPilha *Pilha);
int pilhaVazia (tPilha Pilha);
// .

