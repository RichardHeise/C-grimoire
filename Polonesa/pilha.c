#define MAX 50 

typedef struct tad_pilha 
{
	int topo ;
	float v[MAX] ;
} tad_pilha ;
 
void inicializa_pilha (tad_pilha *p) {
	p->topo = -1;
}

int pilha_vazia (tad_pilha p) {
	if (p.topo == -1) 
		return 1;
	return 0;
}

int empilha (float x, tad_pilha *p) {
	if (p->topo == MAX-1) 
		return 0;
	p->topo = p->topo + 1;
	p->v[p->topo] = x;
	return 1;
}

int desempilha (tad_pilha *p) {
	if (pilha_vazia(*p)) 
		return 0;
	p->topo = p->topo - 1;
  return 1;
}

int topo (float *t, tad_pilha p) {
	if (pilha_vazia(p))
		return 0;
	*t = (p.v[p.topo]);
	return 1;
}
int tamanho_pilha(tad_pilha p) {
	return (p.topo+1);
}

