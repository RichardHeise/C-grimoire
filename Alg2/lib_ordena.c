#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_ordena.h"
#define MAX 100000

void imprime_vetor (int v[], int tam) {
    int i;

    for (i=0; i<tam-1; i++)
        printf("%d ",v[i]);
    printf("%d\n",v[tam-1]);
}

void troca (int *i, int *j) {
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;
}

void gera_vetor_ordenado (int v[], int tam) {
    int i;

    for (i=0; i<tam; i++)
        v[i] = i;
}

void gera_vetor_randomico (int v[], int tam) {
    int i;

    srand(time(0));
    for (i=0; i<tam; i++)
        v[i] = (unsigned int) (rand() % (tam*3)); /* pode modificar se quiser */
}

void embaralha_vetor (int v[], int tam) {
    int k, i, j, max_trocas;

    max_trocas = (unsigned int) (rand() % tam) + tam; /* pode modificar */
    for (k=0; k<max_trocas; k++) {
        i = (unsigned int) (rand() % tam);
        j = (unsigned int) (rand() % tam);
        troca (&v[i],&v[j]);
    }
}

void intercala_normal (int v[], int ini, int meio, int fim) {
    int i;
    int j;
    int k = 0;
    int Vaux[MAX];
    for (i = ini; i <= fim; i++) {
        Vaux[i] = v[i];
    }
    i = ini;
	j = (meio + 1);
	k = ini;
    while (i <= meio && j <= fim) {
        if (Vaux[i] <= Vaux[j]) {
            v[k] = Vaux[i];
            i++;
        } 
        else {
            v[k] = Vaux[j];
            j++;
        }   
        k++;
    }
    while (i <= meio) {
        v[k] = Vaux[i];
        k++;
        i++;
    }  
}

void intercala(int v[], int ini, int meio, int fim) {
    if (v[meio] < v[meio+1])
        return;
    int i;
    int j;
    int k = 0;
    int Vaux[MAX];
    for (i = ini; i <= fim; i++) {
        Vaux[i] = v[i];
    }

    i = ini;
    j = (meio + 1);
    k = ini;
    while (i <= meio && j <= fim) {
        if (Vaux[i] <= Vaux[j]) {
            v[k] = Vaux[i];
            i++;
        }
        else {
            v[k] = Vaux[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        v[k] = Vaux[i];
        k++;
        i++;
    }
}

int particiona (int v[], int ini, int fim) {
    int pivo = v[ini];
    int i = ini+1;
    int j;
    for (j = ini + 1; j <= fim; ++j) {
        if (v[j] <= pivo) {
            troca(&v[j],&v[i]);
            ++i;
        }
    }
    troca(&v[i-1], &v[ini]);
    return (i-1);
}

void insertionsort (int v[], int ini, int fim) {
    int i;
    int key;
    int j;
    for (i = ini+1; i <= fim; ++i) {
        j = i - 1;
        key = v[i];
        while ((key < v[j]) && (j >= 0)) {
            v[j+1] = v[j];
            --j;
        }
    v[j+1] = key;
    }
}

void quicksort (int v[], int ini, int fim) {
    if (ini < fim) {
        int p = (particiona(v, ini, fim));
        quicksort(v, ini, p-1);
        quicksort(v, p+1, fim);
    }
}

void mergesort (int v[], int ini, int fim) {
    if (ini < fim) {
        int meio;
        meio = ((fim + ini) / 2);
        mergesort(v, ini, meio);
        mergesort(v, meio+1, fim);
        intercala(v, ini, meio, fim);
    }
}

void mergesort_normal (int v[], int ini, int fim) {
    if (ini < fim) {
        int meio;
        meio = ((fim + ini) / 2);
        mergesort_normal(v, ini, meio);
        mergesort_normal(v, meio+1, fim);
        intercala_normal(v, ini, meio, fim);
    }
}


int particiona_mediana3(int v[], int ini, int fim) {
    int pivo;
    int j;
    int i = ini -1;
    int med;
    int meio = (fim + ini) / 2;
    if ((v[ini] < v[meio]) && (v[meio] < v[fim])) {
        med = meio;
    }
    if ((v[meio] < v[ini]) && (v[ini] < v[fim])) {
        med = ini;
    }
    if ((v[ini] < v[fim]) && (v[fim] < v[meio])) {
        med = fim;
    }
    troca(&v[fim], &v[med]);
    pivo = v[fim];

    for (j = ini; j < fim; ++j) {
        if (v[j] <= pivo) {
            troca(&v[j],&v[i+1]);
            ++i;
        }
    }
    troca(&v[fim], &v[i+1]);
    return i+1;
}

void quicksort_mediana3_insertion (int v[], int ini, int fim) {
    if (ini < fim) {
        if ((fim - ini + 1) <= 30) {
            insertionsort(v, ini, fim);
        } 
        int p = particiona_mediana3(v, ini, fim);
        quicksort_mediana3_insertion(v, ini, p - 1);
        quicksort_mediana3_insertion(v, p + 1, fim);
    }
}    
void quicksort_mediana3 (int v[], int ini, int fim) {
    if (ini < fim) {
        int p = particiona_mediana3(v, ini, fim);
        quicksort_mediana3(v, ini, p - 1);
        quicksort_mediana3(v, p + 1, fim);
    }

}











