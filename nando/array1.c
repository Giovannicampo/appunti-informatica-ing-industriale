/*
scrivere un programma che legga da tastiera un vettore di 20 elementi e stampi sul video, su due righe differenti gli eelementi 
del vettore di posizione pari e gli elementi del vettore di posizione dispari
*/

#define N 20
#include <stdio.h>

int main(){
int i_pari,i_dispari=0;
int v[N];
int pari[N/2];
int dispari[N/2];
for(int i=0;i<N;i++)
{
    printf("inserisci numeri da confrontare: ");
    scanf("%d", &v[i]);
    if(i%2==0){
        pari[i_pari]=v[i];
        i_pari++;
        continue;
    }
    dispari[i_dispari]=v[i];
    i_dispari++;
}
printf("gli elementi di pos pari: ");
for(int i=0; i<N/2; i++)
{
    printf(" %d", pari[i]);
}
printf("\ngli elementi di pos dispari: ");
for (int i=0; i<N/2; i++){
    printf(" %d", dispari[i]);
} 


}