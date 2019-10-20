#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h> 

typedef struct tabuleiro 
{
    int **matrix; /* matrix do tabuleiro */
    int lin; /* linhas da matrix */
    int col; /* colunas da matrix */
} tabuleiro; 

typedef struct celular 
{
    int posy; /* pos em relação as colunas */
    int posx; /* posição em relação as linhas */
} celula;

void cria_tabuleiro (tabuleiro *tab) {
    int i;
    int j;
    /* escreve zero na matriz inteira */
    for (i = 0; i <= tab->lin; ++i) {
        for (j = 0; j <= tab->col; ++j) {
            tab->matrix[i][j] = 0;
        }
    }
    /* coloca -8 nas bordas */
    /* -8 é um valor aleatório. Qualquer valor negativo seria equivalente */
    for (i = 0; i <= tab->lin; ++i) {
        tab->matrix[i][0] = -8;
        tab->matrix[i][tab->col-1] = -8;
    } 
    for (i = 0; i <= tab->col; ++i) {
        tab->matrix[0][i] = -8;
        tab->matrix[tab->lin-1][i] = -8;
    }
}

void print_tabuleiro (tabuleiro *tab) {
    int i, j;
    for (i = 0; i <= tab->lin; ++i){
        for (j = 0; j <= tab->col; ++j) {
            /* ajeita a forma como o usuário vê o tabuleiro */
            if (tab->matrix[i][j] == 0 || tab->matrix[i][j] == -8) 
                printf(" ");
            else 
                printf("#"); 
        }
    printf("\n");
    }
}

void aloca (tabuleiro *tab) {
    int i;
    /* aloca dinamicamente a matrix do struct tab */
    tab->matrix = NULL; 
    tab->matrix = malloc(tab->lin * sizeof(int *)+1);
    for (i = 0; i <= tab->lin; ++i) {
        tab->matrix[i] = malloc(tab->col * sizeof(int)+1);
    /* +1 evita alguns seg fault */
    }
}

void libera (tabuleiro *tab) {
    free(tab->matrix);
}

int cria_populacao (celula *cel, tabuleiro *tab) {
    /* variaveis */
    int Entrada;
    int Erro = 0;
    /* inputs */
    printf("Digite -1 para parar.\n");
    printf("Entre com as posições iniciais das populações: ");
    scanf("%d", &Entrada);
    if (Entrada > tab->lin || Entrada > tab->col) {
        Erro = 1; /* controle de input */
    }
    while (Entrada != -1 && !Erro) {
        /* escreve na posição de linhas da celula */
        cel->posx = Entrada;
        /* nova entrada será lida */
        scanf("%d", &Entrada);
        /* realiza o controle da entrada lida */
        if (Entrada > tab->lin || Entrada > tab->col) {
            Erro = 1;
            break;
        }
        /* escreve a nova entrada na posição de colunas da celula */
        cel->posy = Entrada;
        /* torna a celula "viva" */
        tab->matrix[cel->posx][cel->posy] = 1;
        /* escreve o tabuleiro em tempo real */
        print_tabuleiro(&*tab);
        printf("Entre com as posições iniciais das populações: ");
        scanf("%d", &Entrada);
        /* controle da entrada */
        if (Entrada > tab->lin || Entrada > tab->col) {
            Erro = 1;
            break;
        }
    }
    if (Erro) {
        return 0;
    }
    return 1;
}

int conta_vizinhos(tabuleiro *tab, int posx, int posy) {
    int cont = 0;
    /* conta os vizinhos por força bruta */
    if (tab->matrix[posx][posy+1] == 1)
        ++cont;
    if (tab->matrix[posx][posy-1] == 1)
        ++cont;
    if (tab->matrix[posx-1][posy+1] == 1)
        ++cont;
    if (tab->matrix[posx-1][posy-1] == 1)
        ++cont;
    if (tab->matrix[posx-1][posy] == 1)
        ++cont;
    if (tab->matrix[posx+1][posy+1] == 1)
        ++cont;
    if (tab->matrix[posx+1][posy-1] == 1)
        ++cont;
    if (tab->matrix[posx+1][posy] == 1)
        ++cont;
    return cont;
}

void proxima_geracao (tabuleiro *tab, int **m) {
    int i;
    int j;
    /* decide, a partir da matrix passada, */
    /* o que acontece com as celulas do tabuleiro */
    for (i = 1; i < tab->lin; ++i) {
        for (j = 1; j < tab->col; ++j) {
            /* se a celula era morta e cumpre o requerimento de vida */
            /* ela passa a ser viva */
            if (tab->matrix[i][j] == 0 && m[i][j] == 3) {
                tab->matrix[i][j] = 1;
            }
            /* se a celula era viva e cumpre o requerimento de morte. */
            /* Então ela passa a ser morta */
            else if (tab->matrix[i][j] == 1 && (m[i][j] < 2 || m[i][j] >= 4)) {
                tab->matrix[i][j] = 0;
            }
        }
    }
}

void evolucao (tabuleiro *tab, celula *cel) {
    int i;
    int j;
    /* matrix auxiliar */
    int **Maux;
    /* alocação dinamica da matriz auxiliar */
    Maux = malloc(tab->lin * sizeof(int *));
    for (i = 0; i < tab->lin; ++i)
        Maux[i] = malloc(tab->col * sizeof(int));

    /* essa matriz guarda os valores de vizinhos */
    /* em cada posição do tabuleiro */
    /* essencialmente é uma matriz de vizinhos de cada celula */
    for (i = 1; i < tab->lin; ++i) {
        for (j = 1; j < tab->col; ++j) {
            Maux[i][j] = conta_vizinhos(&*tab, i, j);
        }
    }
    proxima_geracao(&*tab, Maux); 
}

