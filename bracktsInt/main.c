#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
	
int  main () { 
	int elemento;
	int ini = -10;
	tad_pilha pilha;
	inicializa_pilha(&pilha);
	scanf("%d", &elemento);
	while (elemento != 0) {
		if (ini == -1*elemento && ini < 0) 
		  	desempilha(&ini, &pilha);
		else
		  empilha(elemento, &pilha);
		topo(&ini, pilha);
		scanf("%d", &elemento);
	}
	if (pilha_vazia(pilha)) 
	  printf("SIM\n"); 
	else
	  printf("NAO\n");
	return 0;
}
		  
