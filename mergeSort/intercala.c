#include <stdio.h>
#define MAX 500
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
        printf("%d", v[i]);
}
void intercala (int v1[], int v2[], int t1, int t2, int vsaida[], int *tsaida) {
	int i;
	int j;
	int k = 0;
	*tsaida = t1+t2;
	if (t1 >= t2) {
		for (i = 0; i < *tsaida; i=i+2) {
			j=i+1;
			vsaida[i] = v1[k];
			vsaida[j] = v2[k];
			k = k + 1;
		}
	}
	else {
		for (i = 0; i < *tsaida; i=i+2) {
			j=i+1;
			vsaida[i] = v2[k];
			vsaida[j] = v1[k];
			k = k + 1;
		}
	}
}

int main() {
	int vetor1[MAX];
	int vetor2[MAX];
	int vetorR[MAX];
	int sizeR;
	int size1;
	int size2;
	printf("tamanho do vetor: ");
	scanf("%d", &size1);
	printf("elementos do vetor: ");
	read_vector(vetor1, size1);
	printf("tamanho do vetor: ");
	scanf("%d", &size2);
	printf("elementos do vetor: ");
	read_vector(vetor2, size2);
	print_vector(vetor1, size1);
	printf("\n");
	print_vector(vetor2, size2);
	printf("\n");
	intercala(vetor1,vetor2,size1,size2,vetorR,&sizeR);
	print_vector(vetorR,sizeR);
	printf("\n");
	return 0;
}


