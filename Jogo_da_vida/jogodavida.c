#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h> 
#include "vida.h"

int main(int argc, char **argv) {
    initscr(); /*inicia a tela*/
    /* declaração das variáveis */
    int controle;
    int geracoes;
    int linhas, colunas;
    tabuleiro tabuleiro;
    celula celula;
    /* transforma os parametros em inteiros */
    tabuleiro.lin = atoi(argv[1]);
    tabuleiro.col = atoi(argv[2]);
    getmaxyx(stdscr, linhas, colunas); /* pega o tamanho da tela */
    endwin(); /*encerra a tela */

    /* checa por erros de argumentos */
    if (argc != 3) {
        printf("Número de parametros errado.\n");
        return 1;
    }
    if (tabuleiro.lin > linhas || tabuleiro.col > colunas) {
        printf("Erro. Terminal muito pequeno.\n");
        return 2;
    }
    /* fim da checagem */


    aloca(&tabuleiro);
    cria_tabuleiro(&tabuleiro);
    /* verifica se o usuário digitou um valor dentro do esperado */
    if (cria_populacao(&celula, &tabuleiro) == 0) {
        printf("Você digitou um valor invalido. \n");
        return 3;
    }

    printf("Quantas gerações você quer?: ");
    scanf("%d", &geracoes);
    /* realiza a passagem de tempo na matriz e escreve na tela */
    for (controle = 0; controle < geracoes; ++controle) {
        print_tabuleiro(&tabuleiro);
        usleep(199999); 
        printf("\033[H\033[J");
        evolucao(&tabuleiro, &celula);
    }
    return 0;
}
