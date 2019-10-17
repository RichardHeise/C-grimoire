#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct t_item t_item;

struct t_nodo {
    int chave;
    struct t_nodo *prox; 
};
typedef struct t_nodo t_nodo;

struct t_lista {
    t_nodo *ini;
    int tamanho;
};
typedef struct t_lista t_lista;


int cria_lista(t_lista *l) {
    l->ini = NULL;
    l->tamanho = 0;
    return 1;
}

int lista_vazia(t_lista *l) {
    if (l->tamanho == 0)
        return 1;
    return 0;
}

void destroi_lista(t_lista *l) {
    t_nodo *ptraux;
    while (l->ini != NULL) {
        ptraux = l->ini;
        l->ini = l->ini->prox;
        free(ptraux->prox); 
    }
    l->tamanho = 0;
}

int insere_inicio_lista(int x, t_lista *l) {
    t_nodo *garrafa;
    garrafa = malloc(sizeof(struct t_nodo));
    if (garrafa == NULL) {
        return 0;
    }
    garrafa->chave = x;
    garrafa->prox = l->ini;
    l->ini = garrafa;
    l->tamanho++;
    return 1; 
}

int insere_fim_lista(int x, t_lista *l) {
    t_nodo *garrafa;
    garrafa = malloc(sizeof(struct t_nodo));
    if (garrafa == NULL) {
        return 0;
    }
    for ()
    
}
int insere_ordenado_lista(int x, t_lista *l);
void imprime_lista(t_lista *l);
int remove_primeiro_lista(int *item, t_lista *l);
int remove_ultimo_lista(int *item, t_lista *l);
int remove_item_lista(int chave, int *item, t_lista *l);
int pertence_lista(int chave, t_lista *l);
int concatena_listas(t_lista *l, t_lista *m);
int copia_lista(t_lista *l, t_lista *m);
