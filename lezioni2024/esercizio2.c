/*
** RILEVAZIONE DI ERRORI - MATRICE CIRCOLANTE
*/

#include <stdio.h>

#define MAX_SIZE 5

int controlla_riga(int A[MAX_SIZE], int B[], int i)
{
    int j, k, stop = 0;
    for (j = 0; j < MAX_SIZE && stop == 0; j++)
    {
        k = (j + i);
        k %= 5;
        // printf("A[%d] - B[%d]\n", j, k);
        if (A[j] != B[k])
        {
            printf("Riga %d, A[%d] = %d è diversa di B[%d] = %d\n", i, j, k, A[j], B[k]);
            stop = 1;
            break;
        }
    }
    return 1 - stop;
}

int verifica_matrice(int mat[][MAX_SIZE], int i)
{
    if (i == MAX_SIZE)
        return 1;

    int res = controlla_riga(mat[0], mat[i], i);

    if (res == 0)
        return 0;

    return verifica_matrice(mat, ++i);
}

// perché ++i e non i++?
// l'ordine con cui vengono richiamate la chiamata ricorsiva a verifica_matrice()
// e l'istruzione di aggiornamento della variabile i dipendono dalla posizione
// dell'operatore unario ++, che se preposto, fa eseguire precedente l'operazione di incremento
// e successivamente la chiamata a funzione, mentre se postposto, dà precedenza alla chiamata a funzione.
//
// quali sono le conseguenze?
// verifica_matrice() essendo chiamata ricorsivamente, nel caso in cui nella prima riga non ci siano eccezioni
// che diano come ritorno zero della funzione, verrà richiamata continuamente, creerà uno stack nuovo e lascerà
// l'istruzione di incremento allo stack precedente senza mai ritornarci. Conseguentemente il programma andrà
// in segmentation fault.
// Per ulteriori informazioni, cerca cosa sono le routine, le subroutine, lo stack pointer e il program counter,
// e come il processore gestisce l'allocazione dei parametri nello stack.

int main()
{
    int mat[MAX_SIZE][MAX_SIZE], i, j, res;

    printf("Inserisci gli elementi della matrice:\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("riga %d\n", i);
        for (j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    res = verifica_matrice(mat, 1);

    if (res == 1)
        printf("La matrice è circolante\n");
    else
        printf("La matrice non è circolante");

    return 0;
}