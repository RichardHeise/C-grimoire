#include <stdio.h>

#define MAX 999

void readvector (int v[], int len) {
    int x;
    int i;
    for (i = 0;i < len;i=i+1) {
        scanf("%d", &x);
        v[i] = x;
    }
}
int max (int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}
int calorias (int arrayT[], int arrayC[], int ind, int time, int matrix[ind][time]){
    int result;
    int tmp1;
    int tmp2;
    if (matrix[ind][time] != 0)
        return matrix[ind][time];
    if (ind < 0 || time == 0)
        result = 0;
    else if (arrayT[ind] >= time)
        result = calorias(arrayT,arrayC,ind-1,time,matrix);
    else {
        tmp1 = calorias(arrayT,arrayC,ind-1,time,matrix);
        tmp2 = arrayC[ind] + calorias(arrayT,arrayC,ind-1,time-arrayT[ind],matrix);
        result = max(tmp1, tmp2);
    }
	matrix[ind][time] = result;
    return result;
}
/*void inicializa_matrix (int matrix[MAX][MAX]) {
    int i;
    int j;
    for (i=MAX;i>0;i--) {
        for (j=MAX;j>0;j--)
            matrix[i][j] = 0;
    }
}*/
          

int main () {
    int globalmatrix[MAX][MAX];
    int T[MAX];
    int C[MAX];
    int size;
    int tempo;
    int Resposta;
   /* inicializa_matrix(globalmatrix);*/
    printf("Quantos exercicios voce pode fazer?:  ");
    scanf("%d",&size);
    printf("Quanto tempo leva cada um?: ");
    readvector(T, size);
    printf("Quantas calorias gasta cada um?: ");
    readvector(C, size);
    printf("Quanto tempo voce tem?: ");
    scanf("%d", &tempo);
    Resposta = calorias(T, C, size-1, tempo, globalmatrix);
    printf("O maximo de calorias que voce ira gastar vale %d\n", Resposta);
    return 0;
}
                                 
