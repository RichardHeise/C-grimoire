#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "lib_ordena.h"

#define MAX 100000
#define MAX_IT 10 /* isto pode ser ajustado */

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int *v;
    v = malloc(MAX * sizeof(int)); 
    int i, tam;
    double ini, fim, soma_tempo;

    /* testes com vetores gerados randomicamente */

    /* defina tam como voce achar melhor */
    tam = 10000;
    soma_tempo = 0;
    for (i=0; i<MAX_IT; i++) {
        gera_vetor_randomico (v,tam);
        embaralha_vetor(v, tam);
        ini = timestamp();
        quicksort_mediana3_insertion(v,0,tam-1);  /* mede tempo so do quicksort */
        fim = timestamp();
        soma_tempo += (fim-ini);
        /* nao conta o tempo de embaralhar */
    }
    printf("tempo medio do quicksort mediana de 3 com insertion: %f\n", soma_tempo/MAX_IT);
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_randomico (v,tam);
        ini = timestamp();
        mergesort(v,0,tam-1);  /* mede tempo so do quicksort */
        fim = timestamp();
        soma_tempo += (fim-ini);    /* nao conta o tempo de embaralhar */
    }
    printf("tempo medio do mergesort que não chama intercala() se vetor já está ordenado: %f\n", soma_tempo/MAX_IT);
        soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_randomico (v,tam);
        embaralha_vetor(v, tam);
        ini = timestamp();
        insertionsort(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do insertionsort: %f\n", soma_tempo/MAX_IT); 
        soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_randomico (v,tam);
        embaralha_vetor(v, tam);
        ini = timestamp();
        quicksort(v,0,tam-1);
        fim = timestamp();
        soma_tempo += (fim-ini);
    }
    printf("tempo medio do quicksort: %f\n", soma_tempo/MAX_IT);
        soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_randomico (v,tam);
        embaralha_vetor(v, tam);
        ini = timestamp();
        mergesort_normal(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do mergesort normal: %f\n", soma_tempo/MAX_IT);
    printf("Agora para vetores ordenados\n");
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        insertionsort(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do insertionsort: %f\n", soma_tempo/MAX_IT); 
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        quicksort(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do quicksort: %f\n", soma_tempo/MAX_IT); 
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        quicksort_mediana3_insertion(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do quicksort mediana3 com insertionsort: %f\n", soma_tempo/MAX_IT); 
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        quicksort_mediana3(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do quicksort mediana de 3 sem o insertion: %f\n", soma_tempo/MAX_IT); 
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        mergesort(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do mergesort: %f\n", soma_tempo/MAX_IT); 
    return 0;
    soma_tempo = 0;
        for (i=0; i<MAX_IT; i++) {
        gera_vetor_ordenado (v,tam);
        ini = timestamp();
        mergesort_normal(v,0,tam-1);  
        fim = timestamp();
        soma_tempo += (fim-ini);    
    }
    printf("tempo medio do mergesort que não chama intercala() se os vetores de comparação já estão ordenados: %f\n", soma_tempo/MAX_IT); 
    return 0;

}
