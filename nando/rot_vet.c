#include <stdio.h>
#define N 5

int main() 
{
    int vet[N] = {1,2,3,4,5};
    int new_vet[N] = {0};
    int shift = 0;
    int direction;

    do{
        printf("Di quanto vuoi ruotare il vettore?\n");
        scanf("%d", &shift);
    } while (shift < 0);

    printf("verso sinistra (inserisci 0) o destra (inserisci 1 o)?\n");
    scanf("%d", &direction);

    // modulo dello shift serve a evitare di ripetere la rotazione quando non necessario 
    // -> esempio: N = 5, 22 rotazioni sono uguali a 2 rotazioni comev effetto finale
    shift = shift % N;

    // si decide il verso di rotazione
    shift = direction == 1 ? shift : -shift;

    for(unsigned short i=0; i<N; i++)
    {
        // first condition: i + shift higher than maximum position available
        if(i + shift > N - 1) {
            // printf("overshot %d\n", -1 + ((i+shift-(N-1))%5));
            new_vet[-1 + ((i+shift-(N-1)))] = vet[i];
            continue;
        }

        // second condition: i + shift < 0
        if(i + shift < 0) {
            // printf("under %d\n", N + (shift + i));
            new_vet[N + (shift + i)] = vet[i];
            continue;
        }

        new_vet[i + shift] = vet[i];
    }

    for(unsigned short i=0; i<N; i++)
    {
        printf("%d ", new_vet[i]);
    }
}