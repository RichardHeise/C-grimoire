#include <stdio.h>


int abre (int matrix, int i, int j) {
	int c;
	if (topo(matrix[i,j]) == -1)  
		desempilha(matrix[i,j]);
	else
		return;
	if (topo.matrix[i,j] != 10){  
		if (matrix[i,j--] == 10)
			c++;
		if (matrix[i,j++] == 10)
			c++;
		if (matrix[i++,j--] == 10)
			c++;
		if (matrix[i++,j] == 10)
			c++;
		if (matrix[i++,j++] == 10)
			c++;
		if (matrix[i--,j--] == 10)
			c++;
		if (matrix[i--,j] == 10)
			c++;
		if (matrix[i--,j++] == 10)
			c++;
		topo.matrix[i,j] = c;
		if (c == 0) {
			abre(matrix, i, j--);
			abre(matrix, i, j++);
			abre(matrix, i++, j);
			abre(matrix, i++, j++);
			abre(matrix, i++, j--);
			abre(matrix, i--, j);
			abre(matrix, i--, j--);
			abre(matrix, i--, j++);
			}
		}
	return 1;
} 

