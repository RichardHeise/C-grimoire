#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* struct do tabuleiro */
typedef struct tabuleiro 
{
    int **matrix;
    int lin;
    int col;
} tabuleiro; 

/* struct da celula */
typedef struct celular 
{
    int posy;
    int posx;
} celula;

/* libera memória alocada dinamicamente */
void libera (tabuleiro *tab);

/* função que cria o tabuleiro com bordas */
void cria_tabuleiro (tabuleiro *tab);

/* aloca memória para tabuleiros */
void aloca (tabuleiro *tab);

/* cria a população a partir de inputs. Se o usuário digitar um valor errado -- fora do tamanho da matriz -- ela retorna 0 */
int cria_populacao (celula *cel, tabuleiro *tab);

/* conta quantos vizinhos cada célula tem e retorna esse valor */
int conta_vizinhos(tabuleiro *tab, int posx, int posy);

/* organiza quais células vão morrer, quais vão nascer e quais vão continuar vivas */
/* utiliza uma matriz auxiliar alocada dinamicamente e declarada em evolução() */
/* NÃO UTILIZE ESSA FUNÇÃO SEM CHAMAR EVOLUÇÃO() */
void proxima_geracao (tabuleiro *tab, int **m);

/* realiza a evolução do tabuleiro. Utiliza uma matriz auxiliar alocada dinamicamente */
void evolucao (tabuleiro *tab, celula *cel);

/* escreve o tabuleiro na tela */
void print_tabuleiro (tabuleiro *tab);
