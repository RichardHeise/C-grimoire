#include <stdio.h>
#include <stdlib.h>

void read_vector (int *v, int tam) {
    int i;
    int x;
    for (i = 0; i < tam; ++i) {
        scanf("%d", &x);
        v[i] = x;
    }
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


int BBR (int *v,int x, int ini, int fim) {
    if (ini <= fim) {
        int meio = (fim + ini) / 2;
        if (x == v[meio]) 
            return 1;
        if (x < v[meio])
            return (BBR(v, x, ini, meio-1));
        if (x > v[meio])
            return (BBR(v, x, meio+1, fim));
    }
    return 0;
}

int main () {
    int *x;
    int elemento;
    int tam;
    scanf("%d", &tam);
    printf("Elemento: ");
    scanf("%d", &elemento);
    x = malloc(sizeof(int) * tam);
    read_vector(x, tam);
    insertionsort(x, 0, tam-1);
    if (BBR(x, elemento, 0, tam-1)) {
        printf("SIM");
    } else {
        printf("NAO");
    }
    return 1;
}