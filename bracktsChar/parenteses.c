#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"

int  main () { 
	char elemento;
	char ini = 'a';
	char aux;
	tad_pilha pilha;
	inicializa_pilha(&pilha);
	scanf("%c", &elemento);
	while (elemento != '0') {
	  	charmemo(elemento, &aux);
		if (ini == aux) 
		  	desempilha(&ini, &pilha);
		else
		  empilha(elemento, &pilha);
		topo(&ini, pilha);
		scanf(" %c", &elemento);
	}
	if (pilha_vazia(pilha)) 
	  printf("SIM\n"); 
	else
	  printf("NAO\n");
	return 0;
}
		  
		  
