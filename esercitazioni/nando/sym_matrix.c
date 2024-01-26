/*
scrivere un programma in linguaggio C, legga una matrice quadrata di interi
controlli se è simmetrica (nota si definisca la dimensione N della matrice
come costante all'interno del programma)
*/
#define N 4
#include <stdio.h>
int main(){
    int mat[N][N];
    int simmetrica=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            printf("inserisci gli elementi della matrice: ");
            scanf("%d", &mat[i][j]);
        }
    }

    int index=1;
    while(index<N-1){
        for(int i=0;i<N-index;i++){
            if(mat[i+index][i] != mat[i][i+index]){
                printf("[%d,%d] is different than [%d,%d]\n",i+index, i, i, i+index);
                simmetrica=0;
                break;
            }
        }
        if(simmetrica==0)
        {
            printf("la matrice non e' simmetrica\n");
            return 0;
        }
        index++;
    }
    printf("la matrice e' simmetrica");
}