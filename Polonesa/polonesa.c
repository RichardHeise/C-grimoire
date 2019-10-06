#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"
#define MAX 50
	

int valida_numero (char v[]) { /*verifica se a string digitada é composta somente por números. Retorna 1 se sim e 0 caso contrário.*/
	int i = 0;
	if (v[i] == '-')
		i = 1;
	while (v[i] != '\0') { 
		if (!isdigit(v[i]) && v[i] != '.' && v[i] != 'e')
			return 0;
		i++;
	}
	return 1;   
}

int valida_operacao (char v[]) { /*verifica se a operação é valida -- soma, subtração, multiplicação e divisão -- e retorna 1 se sim e 0 se não*/
	if (v[0] == '+' || v[0] == '-' || v[0] == '*' || v[0] == '/')
		return 1;
	return 0;
}

float faz_operacao (char v[], float x, float y) { /*faz a operação respectiva a entrada. O vetor só tem uma posição pois as operações binárias são só um char*/
	if (v[0] == '+')
		return (x+y);
	if (v[0] == '-')
		return (x-y);
	if (v[0] == '*')
		return (x*y);
	if (v[0] == '/')
		return (x/y);
	return 0; /*o compilador reclama se a função do tipo float não retornar valor, mesmo que seja impossível chegar nesse valor*/
} 

int main() {
	tad_pilha pilha;             /*inicializando as variaveis*/
	char Entrada[MAX];           /*vetor de entrada*/
	float operando1 = 0;         /*primeiro operando*/
	float operando2 = 0;         /*segundo operando*/
	float resposta = 0;              /*variavel de resposta*/
	inicializa_pilha(&pilha);
	printf("Pressiona q para sair\n");
	printf("Digite os operandos e operações separadas por espaços: ");
	scanf("%s", Entrada);
	while (Entrada[0] != 'q') { 
		if (valida_numero(Entrada)) {                                       
			empilha(atof(Entrada), &pilha);                     /*empilha o valor da entrada validado*/
		} 
		else if (valida_operacao(Entrada) && strlen(Entrada) == 1) {   /*condição feita para evitar entradas do tipo +5 -- consideradas ambíguas --, sem espaço*/
			if (pilha_vazia(pilha)) 
				printf("Erro. Faltam operandos.\n");
			else {
				topo(&operando2, pilha);							   /*operando2 recebe o topo*/
				desempilha(&pilha);		
				if (pilha_vazia(pilha)) {
					printf("Erro. Faltam operandos.\n");
					break;
				}
				topo(&operando1, pilha);                               /*operando1 recebe o topo*/
				desempilha(&pilha);
				empilha(faz_operacao(Entrada, operando1, operando2), &pilha); /*verifica a operação digitada e a empilha após ser realizada*/
			}                                                                   /*consideração: a utilização de topo() e depois desempilha() somente*/	
		}																		/*para reduzir o tamanho da pilha foi necessária para corrigir bugs*/
		else 
			printf("Erro. digito inválido\n");
		scanf(" %s", Entrada);
	}
	topo(&resposta, pilha);
	printf("%f\n", resposta);	
	return 0;
} 
