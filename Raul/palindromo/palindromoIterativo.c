#include <stdio.h>
#include <stdlib.h>

void read_word (char *v, int *i) {
    char x;
    scanf("%c", &x);
    for (*i = 0;x != 10;*i = *i + 1) {
        v[*i] = x;
        scanf("%c", &x);
    }
}

int palindromo (char v[], int ini, int fim) {
    int i;
    for (i = 0; ini < fim && v[ini+i] == v[fim-i]; ++i);
    if (i >= fim)
        return 1;
    return 0;
}

int main() {
    int size;
    char *vetor;
    vetor = malloc(100 * sizeof(char));
    if (vetor == NULL) {
        printf("Malloc falhou. Abortando por questões de segurança.");
        return 0;
    }
    read_word(vetor, &size);
    if (palindromo(vetor, 0, size-1))
        printf("SIM\n");
    else
        printf("NAO\n");
    free(vetor);
    return 1;
} 

