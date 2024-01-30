#include <stdio.h>

#define N 4

void trasponi(int Matrice[][N])
{
    int i, j, temp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            temp = Matrice[i][j];
            Matrice[i][j] = Matrice[j][i];
            Matrice[j][i] = temp;
        }
    }
}

void stampa_matrice(int Matrice[][N])
{
    for (unsigned short i = 0; i < N; i++)
    {
        for (unsigned short j = 0; j < N; j++)
        {
            printf("%4d", Matrice[i][j]);
        }
        printf("\n");
    }
}

void popola_matrice(int Matrice[][N])
{
    for (unsigned short i = 0; i < N; i++)
    {
        for (unsigned short j = 0; j < N; j++)
        {
            printf("Inserisci numero nella pos %d %d\n", i, j);
            scanf("%d", &Matrice[i][j]);
            // Matrice[i][j] = i*N+j+1;
        }
    }
}

int main()
{
    int Matrice[N][N];

    popola_matrice(Matrice);
    printf("Prima della trasposizione: \n");
    stampa_matrice(Matrice);

    trasponi(Matrice);

    printf("\n\nDopo la trasposizione: \n");
    stampa_matrice(Matrice);

    char parola[100] = "Ciao mi chiamo Giovanni";

    char a = '1';

    char *str = "ciao";

    return 0;
}