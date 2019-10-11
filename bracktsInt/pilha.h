#define MAX 50

typedef struct tad_pilha {
   int topo;
   int v[MAX];
} tad_pilha; 
 
void inicializa_pilha (tad_pilha *p); /*inicializa pilha com -1 no topo*/

int pilha_vazia (tad_pilha p); /*se a pilha eh vazia retorna 1, caso contrario retorna 0*/

int empilha (int x, tad_pilha *p);  /*empilha o elemento x no topo, se funcionar retorna 1, se não funcionar -- pilha cheia -- retorna 0*/

int desempilha (int *t, tad_pilha *p); /*desempilha o elemento do topo, se funcionar retorna 1, caso contrario -- pilha vazia -- retorna 0*/

int topo (int *t, tad_pilha p); /*retorna o elemento do topo, se funcionar retorna 1, caso contrário -- pilha vazia -- retorna 0*/

int tamanho_pilha(tad_pilha p); /*retorna o tamanho da pilha*/
