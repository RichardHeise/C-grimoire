#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cria_lista(t_lista *l) {
    l->ini = NULL;
    l->tamanho = 0;
    return 1;
}

int lista_vazia(t_lista *l) {
    if (l->ini == NULL || l->tamanho == 0)
        return 1;
    return 0;
}

/* um ponteiro auxiliar destroi a proxima posição */
/* enquanto o inicio percorre a lista. Custo linear */
void destroi_lista(t_lista *l) {
    if (! lista_vazia(l)) {
        t_nodo *ptraux = malloc(sizeof(t_nodo));
        if (ptraux == NULL) {
            printf("Falha de memória. Abortando.\n");
            return 0;
        }
        while (l->ini != NULL) {
            ptraux->prox = l->ini;
            l->ini = l->ini->prox;
            free(ptraux->prox); 
        }
        free(ptraux);
        l->tamanho = 0;
    }
    printf("Não destruida: lista vazia\n");
}

/* um ponteiro auxiliar aponta para a primeira posição */
/* o inicio passa a apontar para o auxiliar */
int insere_inicio_lista(int x, t_lista *l) {
    t_nodo *ptraux;
    ptraux= malloc(sizeof(struct t_nodo));
    if (ptraux == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    ptraux->chave = x;
    ptraux->prox = l->ini;
    l->ini = ptraux;
    l->tamanho++;
    return 1; 
}

/* percorre a lista, usando um auxiliar, até achar o fim */
/* o fim passa a apontar para o auxiliar e este recebe null */
int insere_fim_lista(int x, t_lista *l) {
    t_nodo *ptraux;
    ptraux= malloc(sizeof(struct t_nodo));
    if (ptraux == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    if (l->ini == NULL) {
        insere_inicio_lista(x, l);
        return 1;
    }
    ptraux->chave = x;
    ptraux->prox = l->ini;
    while (ptraux->prox->prox != NULL) {
        ptraux->prox = ptraux->prox->prox;
    }
    ptraux->chave = x;
    ptraux->prox->prox = ptraux;
    ptraux->prox = NULL;
    l->tamanho++;
    return 1;
}

/* insere um elemento na posição correta */
int insere_ordenado_lista(int x, t_lista *l) {
    /* se a lista é vazia o elemento é inserido no inicio */
    if (lista_vazia(l)) {
        insere_inicio_lista(x, l);
        return 1;
    }
    /* se a primeira posição é menor que o elemento */
    /* o elemento é inserido no início */
    if (x < l->ini->chave) {
        insere_inicio_lista(x, l);
        return 1;
    } 
    /* acabamos de garantir que o tamanho da lista é maior que 2 */
    t_nodo *ptraux = malloc (sizeof(t_nodo));
    if (ptraux == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    ptraux->prox = l->ini;

    /* enquanto não estivermos na última posição */
    while (ptraux->prox->prox != NULL) {
        /* verificamos se o x se encaixa */
        /* com nosso auxiliar apontado para o um nodo antes */
        /* da posição maior que x, ou seja, se y < x < w */
        /* estamos apontando para o nodo de chave y */
        if (x >= ptraux->prox->chave && x <= ptraux->prox->prox->chave) {
            t_nodo *tmp = malloc (sizeof(t_nodo));
            if (tmp == NULL) {
                printf("Falha de memória. Abortando.\n");
                return 0;
            }
            tmp->prox = ptraux->prox;
            ptraux->prox = ptraux->prox->prox;
            ptraux->chave = x;
            tmp->prox->prox = ptraux;
            l->tamanho++;
            free(tmp);
            return 1;
        }
        /* andamos na lista se ainda não achamos o lugar de x */
        ptraux->prox = ptraux->prox->prox;
    }
    /* andamos até a última posição e não achamos o lugar de x; */
    /* comparamos, então, com o último elemento */
    if (x > ptraux->prox->chave) {
        insere_fim_lista(x, l);
        return 1;
    }
    return 0;
}   

/* imprimimos elementos até a última a posição */
void imprime_lista(t_lista *l) {
    if (! lista_vazia(l)) {
        t_nodo *ptraux = malloc(sizeof(t_nodo));
        if (ptraux == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return 0;
        } 
        ptraux->prox = l->ini;
        while (ptraux->prox != NULL) {
            printf("%d ", ptraux->prox->chave);
            ptraux->prox = ptraux->prox->prox;
        }
        printf("\n");
    }
}

/* se a lista não é vazia vamos fazer o inicio */
/* apontar para o próximo nodo e liberar o antigo primeiro nodo*/
int remove_primeiro_lista(int *item, t_lista *l) {
    if (l->ini != NULL) {
        t_nodo *ptraux = malloc(sizeof(t_nodo));
        if (ptraux == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return 0;
        }
        ptraux->prox = l->ini;
        l->ini = l->ini->prox;
        *item = ptraux->prox->chave;
        free(ptraux->prox);
        free(ptraux);
        l->tamanho--;
        return 1;
    }
    return 0;
}

/* andamos até o último nodo e o removemos */
int remove_ultimo_lista(int *item, t_lista *l) {
        /* se a lista não for vazia */
        if (l->ini != NULL) {
        /* se o tamanho da lista é 1, então removemos o único nodo */
        if (l->tamanho == 1) {
            remove_primeiro_lista(item, l);
            return 1;
        } 
        t_nodo *ptraux = malloc(sizeof(t_nodo));
        if (ptraux == NULL) {
            printf("Falha de memória. Abortando.\n\n");
            return 0;
        }
        ptraux->prox = l->ini;
        /*enquanto não estamos no último nodo */
        while (ptraux->prox->prox->prox != NULL) {
            ptraux->prox = ptraux->prox->prox;
        }
        *item = ptraux->prox->chave;
        free(ptraux->prox->prox);
        ptraux->prox->prox = NULL;
        free(ptraux);
        l->tamanho--;
        return 1;
    }
    return 0;
}

/* remove um nodo se ele é igual a chave */
int remove_item_lista(int chave, int *item, t_lista *l) {
    /* se houver elementos na lista */
    if (! lista_vazia(l)) {
        /* se a primeira posição for igual achave nós a removemos */
        if (chave == l->ini->chave) {
            remove_primeiro_lista(item, l);
            return 1;
        }
        /* garantimos que o tamanho da lista é maior ou igual a dois elementos */
        if (l->tamanho > 1) {
            t_nodo *ptraux = malloc(sizeof(t_nodo));
            if (ptraux == NULL) {
                printf("Falha de memória. Abortando.\n");
                return 0;
            }
            ptraux->prox = l->ini;
            /* apontamos sempre uma posição antes do nodo que será removido */
            while (ptraux->prox->prox->prox != NULL && ptraux->prox->prox->chave != chave) {
                ptraux->prox = ptraux->prox->prox;
            }
            /* se acharmos o elemento ele é removido */
            if (ptraux->prox->prox->chave == chave) {
                t_nodo *tmp = malloc(sizeof(t_nodo));
                if (tmp == NULL) {
                    printf("Falha de memória. Abortando.\n");
                    return 0;
                }
                tmp->prox = ptraux->prox->prox;
                ptraux->prox->prox = tmp->prox->prox;
                *item = tmp->prox->chave;
                free(tmp);
                free(ptraux);
                l->tamanho--;
                return 1;
            }
            printf("elemento não encontrado.\n");
            return 0;
        }
    }
    printf("elemento não encontrado.\n");
    return 0;
}

/* verificamos se o elemento chave está na lista */
int pertence_lista(int chave, t_lista *l) {
    t_nodo *ptraux = malloc(sizeof(t_nodo));
    if (ptraux == NULL || lista_vazia(l)) {
        printf("Lista vazia ou falha de memória.");
        return 0;
    }
    ptraux->prox = l->ini;
    /* caminhamos até o último nodo procurando o elemento */
    while (ptraux->prox->chave != chave && ptraux->prox->prox != NULL) { 
        ptraux->prox = ptraux->prox->prox;
    }
    /* se encontramos, retornamos 1 */
    if (ptraux->prox->chave == chave) {
        free(ptraux);
        return 1;
    }
    return 0;
}

 /* caminhamos até o último elemento da lista l */
 /* fazemos esse elemento apontar para o inicio da lista m */
int concatena_listas(t_lista *l, t_lista *m) {
    t_nodo *ptraux = malloc(sizeof(t_nodo));
    if (ptraux == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    ptraux->prox = l->ini;
    while (ptraux->prox->prox != NULL) {
        ptraux->prox = ptraux->prox->prox;
    }
    ptraux->prox->prox = m->ini;
    free(ptraux);
    m->ini = NULL;
    return 1;
}

int copia_lista(t_lista *l, t_lista *m) {
    cria_lista(m);
    int i;
    int x;
    t_nodo *ptraux = malloc(sizeof(t_nodo));
    if (ptraux == NULL) {
        printf("Falha de memória. Abortando.\n");
        return 0;
    }
    ptraux->prox = l->ini;
    /* usamos o tamanho da lista para criar uma lista nova */
    /* e copiamos cada chave na lista nova */
    for (i = 0; i < l->tamanho; ++i) {
        x = ptraux->prox->chave;
        insere_fim_lista(x, m);
        ptraux->prox = ptraux->prox->prox;
    }
    free(ptraux);
    return 1;
}

