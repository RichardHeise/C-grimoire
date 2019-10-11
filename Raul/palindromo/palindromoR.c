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

/*void printword (char v[], int i) {
  	int j;
  	for (j = 0; j <= i; j++)  
	  	printf("%c", v[j]); 
	printf("\n");
} */

int palindromo (char v[], int ini, int fim) {
	if (ini < fim) { 
	  if (v[ini] == v[fim])
	    return (1 && palindromo(v, ini+1, fim-1));
	  else
	    return 0;
	}
	return 1;  
	
}	


int main () {
    int size;
	char *vetor; 
    vetor = (char *) malloc(100 * sizeof(char));
    if (vetor == NULL) {
        printf("Malloc falhou. Abortando por questões de segurança");
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
