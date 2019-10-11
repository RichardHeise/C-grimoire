#include <stdio.h>
#include <stdlib.h>

void read_matrix (int l, int c, int **m) {
    int rc;
    int cc;
    for (rc = 0; rc < l; rc = rc + 1)
        for (cc = 0; cc < c; cc = cc + 1)
            scanf("%d", &m[rc][cc]);

}

void print_matrix (int l, int c, int **m) {
    int rc;
    int cc;
    for (rc = 0; rc < l; rc = rc + 1) {
        for (cc = 0; cc < c; cc = cc + 1)
            printf("%d ", m[rc][cc]);
        printf("\n");
    }
}

void multiplica_matriz (int **m1, int **m2, int *l1, int *c2,int *l2, int **mr) {
    int c;
    int d;
    int k;
    for (c = 0; c < *l1; c = c + 1) {
        for (d = 0; d < *c2; d = d + 1) {
            mr[c][d] = 0;
            for (k = 0; k < *l2; k = k + 1) {
                mr[c][d] = mr[c][d] + (m1[c][k] * m2[k][d]);
            }
        }
    }
}   

int main() {
    /* Declação das variáveis */
    int linhas1, linhas2;
    int colunas1, colunas2;
    int **matrix1, **matrix2, **matrix_resposta;
    /* contador */
    int i;
    printf("Escreva as linhas e colunas da matrix A: ");
    scanf("%d %d", &linhas1, &colunas1);
    printf("Escreva as linhas e colunas da matrix B: ");
    scanf("%d %d", &linhas2, &colunas2);
    /* verifica-se se é possível realizar a multiplicação */
    if (colunas1 != linhas2) {
        printf("NÃO É POSSÍVEL \n");
        return 1; /*código de erro*/
    }
    /* método de alocação dinâmica de matrizes. */
    /* uma matriz é um ponteiro de ponteiros, pois vetores são ponteiros */
    /* logo, fazemos ponteiros dinâmicos */
    matrix1 = (int **)malloc(linhas1 * sizeof(int *));
    for (i = 0; i < linhas1; i = i + 1)
        matrix1[i] = (int *)malloc(colunas1 * sizeof(int));
    if (matrix1 == NULL) {
        printf("Malloc falhou. Abortando");
        return 0;
    }
    matrix2 = (int **)malloc(linhas2 * sizeof(int *));
    for (i = 0; i < linhas2; i = i + 1) 
        matrix2[i] = (int *)malloc(colunas2 * sizeof(int));
 
    if (matrix2 == NULL) {
        printf("Malloc falhou. Abortando");
        return 0;
    }
    matrix_resposta = (int **)malloc(linhas1 * sizeof(int *));
    for (i = 0; i < linhas1; i = i + 1)
        matrix_resposta[i] = (int *)malloc(colunas2 * sizeof(int));

    if (matrix_resposta == NULL) {
        printf("Malloc falhou. Abortando");
        return 0;
    }
    printf("Escreva os elementos da matrix A \n ");
    read_matrix(linhas1, colunas1, matrix1);
    printf("Escreva os elementos da matrix B \n ");
    read_matrix(linhas2, colunas2, matrix2);
    printf("Matrix A: \n");
    print_matrix(linhas1, colunas1, matrix1);
    printf("\n");
    printf("Matrix B: \n");
    print_matrix(linhas2, colunas2, matrix2);
    printf("Multiplicando... \n");
    multiplica_matriz(matrix1, matrix2, &linhas1, &colunas1, &colunas2, matrix_resposta);
    printf("Resultado: \n");
    print_matrix(linhas1, colunas2, matrix_resposta);
    free(matrix1);
    free(matrix2);
    free(matrix_resposta);
    return 1;
}        
