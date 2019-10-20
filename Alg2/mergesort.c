#include <stdio.h> 

#define MAX 5000


void print_vector (int v[], int size);
void merge (int v[], int ini, int mid, int fim) {
    int i;
    int j;
    int k;
    int Vaux[MAX];
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

void read_vector (int v[], int size) {
	int x;
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &x);
		v[i] = x;
	}
}

void print_vector (int v[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", v[i]);
}

int main() {
	int tam;
	int vetor[MAX];
	printf("Tamanho: ");
	scanf("%d", &tam);
	printf("Elementos: ");
	read_vector(vetor, tam);
	mergeSort(vetor, 0, tam-1);
	printf("O vetor foi ordenado: ");
	print_vector(vetor, tam);
	printf("\n");
	return 0;
}
