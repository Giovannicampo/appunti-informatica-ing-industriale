#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// variabile allocata globalmente (nel DATA)
int var = 10;


// parametri del main argc argv
int main(int argc, char* argv[])
{   
    srand(time(NULL));
    for(__uint8_t i=0; i<argc; i++){
        printf("%s\n", argv[i]);
    }

    // puntatori
    int var_1 = 10;
    int var_2 = 5;

    // dichiarazione e definizione di un puntatore a interi
    int* ptr = &var_1;
    
    // dereferenziazione con l'operatore * e aggiornamento del valore
    *ptr += 10;

    printf("var1 = %d,ptr = %d\n",var_1,*ptr);

    // cambio di riferimento del puntatore
    ptr = &var_2;

    printf("var2 = %d,ptr = %d\n",var_2,(*ptr));
    printf("var2 = %d,ptr = %d\n",var_2,*ptr);

    // sizeof() restituisce il numero di byte necessari per allocare un tipo primitivo
    printf("%ld\n",sizeof(int));

    float ciao = 4.2f;
    printf("ciao = %d\n", (int) ciao);

    // funzione malloc utilizzata per allocare dinamicamente un puntatore a interi (HEAP)
    int* var_nuova = (int*) malloc(sizeof(int));    
    (*var_nuova) = 10;
    printf("%d\n",*var_nuova);

    // funzione malloc utilizzare per allocare dinamicamente una stringa
    char* parola = (char*) malloc(sizeof(char));
    parola = "ciao";
    printf("%c\n",*(parola + 2));
    

    // allocazione dinamica di un array
    int* vet = (int*) malloc(sizeof(int)*10);
    for(unsigned int i=0; i<10; i++)
    {
        vet[i] = rand()%11;
        printf("vet[%d] = %d\n", i, vet[i]);
    }
}