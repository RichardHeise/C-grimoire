#define MAX 50

typedef struct tad_pilha {
   int topo;
   char v[MAX];
} tad_pilha; 
 
void inicializa_pilha (tad_pilha *p); /*inicializa pilha com -1 no topo*/

int pilha_vazia (tad_pilha p); /*se a pilha eh vazia retorna 1, caso contrario retorna 0*/

int empilha (char x, tad_pilha *p);  /*empilha o elemento x no topo, se funcionar retorna 1, se não funcionar -- pilha cheia -- retorna 0*/

int desempilha (char *t, tad_pilha *p); /*desempilha o elemento do topo, se funcionar retorna 1, caso contrario -- pilha vazia -- retorna 0*/

int topo (char *t, tad_pilha p); /*retorna o elemento do topo, se funcionar retorna 1, caso contrário -- pilha vazia -- retorna 0*/

int tamanho_pilha(tad_pilha p); /*retorna o tamanho da pilha*/

int charmemo (char t, char *x); /*identifica a entrada char e retorna o "inverso" do valor, essencialmente um dicionário, um "memo". Retorna 1 se achou e 0 se não*/ 
