#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM_1 10
#define DIM_2 20

    /*
    ** FUNZIONI
    ** In linguaggi procedurali come il C, le funzioni ricoprono grande importanza
    ** e vengono utilizzate per rendere il codice più leggibile e funzionale e aiutare
    ** a rendere manutenibile il software
    **
    ** Le funzioni (o procedure o routine) sono gruppi di istruzioni aventi un loro stack
    ** (una loro porzione di memoria) e sono indicate da:
    ** - un nome
    ** - una lista di parametri che possono avere in input (parametri formali)
    ** - una serie di istruzioni (corpo della funzione)
    ** - un valore da restituire in output (ritorno della funzione)
    **
    ** le funzioni vengono dichiarate e definite all'esterno del main, in quanto il main stesso
    ** è una funzione
    */

   // ecco un esempio di funzione
   
   // int indica il tipo di ritorno di una funzione; in questo caso è un valore intero
   // somma indica il nome della funzione; può essere un nome qualsiasi, ma spesso si decide un nome che spieghi lo scopo della funzione
   // all'interno di parentesi tonde ci sono i parametri formali; in questo caso sono due interi da sommare
   // return lx+dx; è l'istruzione che da fine alla funzione e ritorna il valore

   int somma(int lx, int dx){
    return lx+dx;
   }


   // esistono funzioni che non ritornano alcun valore, in questo caso il ritorno è void (vuoto)

   // in questo caso passiamo un puntatore (o un array) come input alla funzione
   // se passassimo per valore e non per riferimento, i cambiamenti che facciamo non si manterrebbero (chiusura dello scope della funzione)

   void initialize_vet(int* vet, int dim){
    for(unsigned short i=0; i<dim; i++){
        vet[i] = i*2;
    }
   }
   
   void print_values_int(int* vet, int dim){
    for(unsigned short i=0; i<dim; i++){
        printf("%d\n", vet[i]);
    }
   }

   void print_values_float(float* vet, int dim){
    for(unsigned short i=0; i<dim; i++){
        printf("%.2f\n", vet[i]);
    }
   }

   // altri esempi di funzione

   // funzione che restituisce 1 se la stringa in input è palindroma, altrimenti 0
   int is_palindroma(char* str){
    for(unsigned short i=0; i<strlen(str); i++){
        if(str[i] != str[strlen(str)-1-i]){
            return 0;
        }
    }
    return 1; // ricorda che se la funziona ha un tipo di ritorno diverso da void, devi sempre ritornare qualcosa
   }

   // dichiarazione funzione divide
   float divide_float(float lx, float dx);
   float divide_int(int lx, int dx);

   // funzione che crea un array di float di N elementi con valori randomici
   float* create_array(int N){
    float* arr = (float*) malloc(sizeof(float)*N);
    for(unsigned short i=0; i<N; i++){
        arr[i] = (float)(rand()%11)/100;
    }
    return arr;
   }

   int max(int a, int b)
   {
    return a > b ? a : b;
   }

int main()
{
    srand(time(NULL));
    // le funzioni si richiamano all'interno del main, o all'interno di altre funzioni

    // il ritorno della funzione somma deve essere depositato all'interno di una variabile deposito
    int a = 10;
    int b = 20;
    int result = somma(a,b);
    printf("result = %d\n",result);

    // utilizziamo la funzione print_values
    int* numeri = (int*)malloc(sizeof(int)*DIM_1);
    initialize_vet(numeri,DIM_1);
    print_values_int(numeri, DIM_1);

    printf("\n");

    // grazie alle funzioni è possibile ripetere parti di codice senza ridondanza, ma a discapito di maggiore overhead (complessità computazionale)
    result = somma(result,10);
    printf("result after sum = %d\n",result);

    result = divide_int(result,2);
    printf("result after division = %d\n",result);

    printf("\n");

    char parola[4] = "anna";
    printf("anna è palindroma? %s\n", is_palindroma(parola) == 1 ? "sì" : "no");
    char parola_1[8] = "orologio";
    printf("orologio è palindroma? %s\n", is_palindroma(parola_1) == 1 ? "sì" : "no");

    // nella riga precedente ho usato l'operatore ternario -> condizione ? yes : no
    // se la condizione è vera viene restituito il primo valore dopo ?, altrimenti il secondo valore
    printf("\n");

    // l'esigenza dell'allocazione dinamica viene adesso
    // se dovessimo avere bisogno di restituire come output da una funzione un array o un puntatore (ovvero locazioni di memoria)
    // è necessario che esse siano allocate nell'HEAP e non nello stack della funzione, altrimenti verrebbero cancellate alla chiusura del suo scope

    float* vet_f = create_array(DIM_2);
    print_values_float(vet_f,DIM_2);

    // richiamiamo max
    printf("il massimo tra 10 e 11 è %d, %d\n", max(10,11));
    
}

// le funzioni possono essere implementate anche dopo il main, l'importante è che vengano dichiarate prima

float divide_float(float lx, float dx){
    return lx/dx;
}

float divide_int(int lx, int dx){
    return (float)lx/dx;
}