#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_word (char *v, int *i) {
  	char x;
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
	char *tmp = (char *) malloc(100 * sizeof(char));
    read_word(tmp, &size);
    vetor = (char *) realloc(tmp, size * sizeof(char));
    if (vetor == NULL) {
        printf("Realloc falhou");
        return 0;
    }
  	if (palindromo(vetor, 0, sizeof(vetor))) 
	  printf("SIM\n");
	else 
	  printf("NAO\n");
	return 1;
}
