#include <stdio.h>

#define MAX 9999

void readvector (int v[], int len) {
    int x;
    int i;
    for (i = 1;i <= len;i++) {
        scanf("%d", &x);
        v[i] = x;
    }
}
int arvorebin (int v[], int beg, int size, int x) { 
	if ((2 * beg) >= size) 
		return 0;
	if (x == v[beg]) 
		return beg;
	if (x < v[beg]) 
		if (x == v[2*beg])
			return (2*beg);
	if (x > v[beg])
		if (x == v[2*beg+1])
			return (2*beg+1);
	return arvorebin(v, beg+1, size, x);
} 


int main () {
	int v[MAX];
	int sizev;
	int element;
	int test;
	scanf("%d", &sizev);
	readvector(v, sizev);
	scanf("%d", &element);
	test = (arvorebin(v, 1, sizev, element)); 
	if (test != 0) 
		printf("Element found\n");
	else
		printf("Element not found\n");
	return 0;
}

	
	
