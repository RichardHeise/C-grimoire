#include <stdlib.h>
#include <stdio.h>

void merge (int v[], int ini, int mid, int fim) {
    int i;
    int j;
    int k;
    int Vaux[MAX];

    if (v[mid+1] > v[mid])
        return;

    for (i = ini; i <= fim; i++) {
        Vaux[i] = v[i];
    }
    i = ini;
    j = (mid + 1);
    k = ini;
    while (i <= mid && j <= fim) {
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
    while (i <= mid) {
        v[k] = Vaux[i];
        k++;
        i++;
    }
}

int mergeSort (int v[], int ini, int fim) {
    if (ini < fim) {
        int meio;
        meio = ((ini + fim) / 2);
        mergeSort(v, ini, meio);
        mergeSort(v, meio+1, fim);
        merge(v, ini, meio, fim);
        }
    return 0;
}


