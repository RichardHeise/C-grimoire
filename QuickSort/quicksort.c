#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 5000

void gera_vetor_aleatorio (int v[], int tam) {

    int i;

    srand(time(0));
    for (i = 0; i < tam; i++)
        v[i] = (unsigned int) (rand() % (tam*3)); /* pode modificar se quiser */

}

void print_vector (int v[], int size);

void troca (int *i, int *j) {
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;
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
            i++;
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
	int *vetor;
	printf("Tamanho: ");
	scanf("%d", &tam);
    vetor = malloc(sizeof(int) * tam);
	gera_vetor_aleatorio(vetor, tam);
    printf("Merge: 1 // Quick: 2 // Insertion: 3 // Quick_Med: 4\n");
    scanf("%d", &seletor);
    if (seletor == 1) {
	    mergeSort(vetor, 0, tam-1);
	    printf("O vetor foi ordenado: ");
	    print_vector(vetor, tam);
	    printf("\n");
    } else if (seletor == 2) {
        quicksort(vetor, 0, tam-1);
        printf("O vetor foi ordenado: ");
        print_vector(vetor, tam);
        printf("\n");
    } else if (seletor == 3) {
        insertionsort(vetor, 0, tam-1);
        printf("O vetor foi ordenado: ");
        print_vector(vetor, tam);
        printf("\n");
    } else {
        quicksort_mediana3_insertion(vetor, 0, tam-1);
        printf("O vetor foi ordenado: ");
        print_vector(vetor, tam);
        printf("\n");
    } 
	return 0;
}
