#include <stdio.h>

#define MAX 9999

void InsertionSort (int v[], int len) {
	int i;
	int j;
	int key;
	for (i=1;i<=len;i++) {
		key = v[i];
		j = i - 1;
		while ((key < v[j]) && (j > -1)) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
}
void readvector (int v[], int len) {
    int x;
	int i;
    for (i = 0;i < len;i++) {
        scanf("%d", &x);
        v[i] = x;
    }
}
void printvector (int v[], int len) {
    int j;
    for (j = 0; j < len; j++)
        printf("%d", v[j]);
    printf("\n");
}
int BuscaBinRecur (int v[], int x, int beg, int end) {
	int mid;
	if (end < beg) 
		return 0;
	mid = ((beg + end) / 2);
	if (x == v[mid])
		return mid; 
	if (x > v[mid]) 
		return BuscaBinRecur(v, x, mid + 1, end);
	if (x < v[mid])
		return BuscaBinRecur(v, x, beg, mid - 1);
	return 1;
}
int main () {
	int v[MAX];
	int size;
	int digit;
	int test;
	printf("Enter the vector size: ");
	scanf("%d", &size);
	printf("Enter the %d vector elements: ", size);
	readvector(v, size);
	InsertionSort(v, size);
	printf("Vector is now sorted\n");
	/*printvector(v, size);*/
	printf("Enter the wanted digit: ");
	scanf("%d", &digit);
	test = BuscaBinRecur(v, digit, 0, size);
	if (test != 0) 
		printf("Digit found. Position in sorted vector is: %d\n", test);
	else
		printf("Digit not found\n");
	return 0;
}
