#include <stdio.h> 

#define MAX 5000

void intercala (int v[], int ini, int meio, int fim) {
    int i;
    int j;
    int k;
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
    int pivo;
    int i = ini + 1;
    int j;
    pivo = v[ini];
    for (j = (ini + 1); j <= fim; ++j) {
        if (v[j] <= pivo) {
            troca(v, j, i);
            ++i;
        }
    } 
    troca(v, i-1, ini);
    return i;
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
	int tam, seletor;
	int vetor[MAX];
	printf("Tamanho: ");
	scanf("%d", &tam);
	printf("Elementos: ");
	read_vector(vetor, tam);
    printf("Merge: 1 // Quick: 2\n");
    scanf("%d", &seletor);
    if (seletor == 1) {
	    mergeSort(vetor, 0, tam-1);
	    printf("O vetor foi ordenado: ");
	    print_vector(vetor, tam);
	    printf("\n");
    } else {
        quicksort(vetor, 0, tam-1);
        printf("O vetor foi ordenado: ");
        printf_vector(vetor, tam);
        printf("\n");
    }
	return 0;
}
