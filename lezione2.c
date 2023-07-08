#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DIM_A 6
#define DIM_B 13

int main(){

    /*
    ** Generazione di numeri pseudo-casuali
    **
    ** Nelle macchine generare numeri casuali non è una cosa del tutto "naturale",
    ** in quanto non esiste il vero e proprio casuale, nel senso statistico del termine.
    ** Si cerca quindi di emulare il tutto attraverso algoritmi deterministici in grado di
    ** restituire una buona approssimazione di ciò che apparirebbe secondo un processo casuale.
    **
    ** In C, un primo modo per generare numeri casuali è utilizzare la funzione rand() offerta
    ** dalla libreria <stdlib.h> che utilizza come seme per la generazione di numeri pseudo-casuali
    ** il ritorno della funzione time(NULL).
    */

   /*
   ** inizializzazione del seme col ritorno della funzione time(NULL)
   ** la funzione time() se come parametro riceve NULL restituisce il numero di secondi passati
   ** dall'1 gennaio 1970 a oggi. Come puoi ben capire i secondi sono in costante aumento
   */
    printf("NUMERI PSEUDO-CASUALI\n\n");
    printf("Numeri di secondi passati dall'1 gennaio 1970: %ld\n", time(NULL));
    srand(time(NULL));

   // per selezionare un valore da 0 a max-1 seguire la regola rand()%max-1
    int random_number = rand()%10;
    printf("I firstly selected number = %d\n",random_number);

    // per selezionare un range di valore seguire la regola rand()%(max-min+1)+min
   random_number = rand()%(30-10+1)+10;
   printf("I secondly selected number = %d\n",random_number);

   // per generare un float casuale ad esempio da 0 a 1
   float random_float_number = (float)(rand()%10)/10;
   printf("I thirdly selected number = %.2f\n", (float)random_float_number);


   printf("------------------------------------------------\n\n");

   /*
   ** Casting statico
   **
   ** il casting è la conversione da un tipo di dati a un altro, quando questo è consentito.
   ** Ad esempio, vi può essere la necessità di usare in un programma solo numeri interi,
   ** ma noi disponiamo solo di numeri con la virgola. Può essere necessario arrotondare
   ** all'intero più vicino i numeri che abbiamo. Il C ci offre il casting statico, ma anche altre
   ** funzioni di libreria.
   **
   ** note: using math.h use -lm flag to compile
   */

    printf("CASTING IN C\n\n");

    float num_f = 4.5f;

    int num_i = (int)num_f;
    printf("After C casting: %d\n", num_i);

    char car_cas = (char)rand()%256;
    printf("After C casting, random char: %c\n", car_cas);

    int num_low = floor(num_f);
    printf("After floor function from math.h: %d\n", num_low);

    int num_high = ceil(num_f);
    printf("After ceil function from math.h: %d\n", num_high);
    printf("------------------------------------------------\n\n");


    /*
    ** Array
    ** 
    ** gli array sono la prima forma di struttura dati che incontriamo e sono anche
    ** tra le più semplici tra quelle esistenti e utilizzate nella programmazione.
    ** a differenza di dati "primitivi" come quelli studiati precedentemente, gli array
    ** si dicono dati strutturati, ovvero agiscono da contenitore ai dati che contengono
    ** e danno una struttura ben precisa di come essi debbano essere allocati in memoria
    **
    ** gli array devono essere tipizzati, ovvero è necessario che indichiamo loro il tipo di
    ** dato che contengono.
    ** ATTENZIONE -> non è possibile inserire elementi di tipo diverso all'interno di un'array
    ** ATTENZIONE -> non è possibile modificare la dimensione dell'array, quindi modificare il
    ** numero di elementi al suo interno (array statico)
    ** ATTENZIONE -> il primo elemento di ogni array è sempre indicato dall'indice 0
    ** 
    */

   printf("ARRAY\n\n");

   /*
   ** dichiarazione e inizializzazione di un array
   **
   ** è possibile aggiungere gli elementi all'interno di parentesi graffe solo in fase di dichiarazione
   ** dell'array
   */
   int ciao[5] = {5,4,3,2,1};

   // 5 è una dimensione fissa dell'array, non è più possibile modificarla

   // per accedere a un elemento dell'array utilizzare l'operatore [] di dereferenziazione con all'interno
   // un numero (indice) che corrisponde alla posizione dell'elemento all'interno dell'array

   // accedo al primo elemento e lo stampo
   printf("primo elemento dell'array ciao: %d\n",ciao[0]);

   // modifico il valore al terzo elemento e lo stampo
   ciao[2]++;
   printf("dopo la modifica al terzo elemento: %d\n", ciao[2]);

   // se provo ad accedere alla posizione 6 e a stamparla riceverò dati spazzatura
   // perchè ho allocato solo 5 locazioni di memoria

   printf("valore all'interno della sesta posizione: %d\n", ciao[5]);

   // mischiamo un pò le cose e utilizziamo un ciclo for
   // ad esempio
   float rand_numbers[10];

   for(unsigned short i=0; i<10; i++){
    rand_numbers[i] = (float)(rand()%100)/100;
    printf("%.2f \t",rand_numbers[i]);
   }
   printf("\n");

   /*
   ** nel codice di prima abbiamo eseguito 10 iterazioni. Abbiamo utilizzato la nostra variabile i
   ** come indice all'interno dell'array. In pratica a ogni ciclo abbiamo dereferenziato l'array,
   ** abbiamo assegnato a ogni sua locazione un valore float random e successivamente l'abbiamo stampato.
   */

    // -----------------------------------------------------------------------

    /*
    ** array di caratteri (stringhe)
    **
    ** in C è possibile costruire vere e proprie parole utilizzando quelle che vengono comunemente
    ** chiamate stringhe. In C, le stringhe vengono rappresentate principalmente attraverso l'array di caratteri.
    ** Ed effettivamente a pensarci, una stringa non è un contenitore di caratteri?
    ** 
    ** All'interno del linguaggio, quando allochiamo un array di caratteri come quella rappresentata
    ** qui di seguito, in modo celato viene allocata una locazione di memoria in più, oltre alle 4 
    ** della parola "melo", chiamata "terminatore di stringa", rappresentata dal carattere '\0' (NULL)
    **
    ** questa serve al compilatore per riconoscere che una stringa sia terminata arrivata al terminatore
    ** quindi nella realtà, l'array sottostante ha un quinto elemento successivo al carattere 'o'
    **
    ** la necessità sta nel fatto che gli elementi di un array sono allocati in memoria uno accanto all'altro,
    ** ognuno contiguo all'altro
    */
    char parola[4] = {'m','e','l','o'};
    printf("%s\n",parola);

    // conta quante volte la lettera t è contenuta all'interno delle seguenti parole

    char letter = 't';
    unsigned short count = 0;

    char parola_1[DIM_A] = {'a','l','b','e','r','o'};
    char parola_2[DIM_B] = "trotterellare";
    
    for(unsigned short j=0; j<DIM_A; j++)
    {
        if(parola_1[j] == letter){
            count++;
        }
    }

    printf("La lettera %c stava all'interno della parola %s, %d volte\n", letter, parola_1, count);

    count = 0;

    for(unsigned short k=0; k<DIM_B; k++)
    {
        if(parola_2[k] == letter){
            count++;
        }
    }

    printf("La lettera %c stava all'interno della parola %s, %d volte\n", letter, parola_2, count);

    printf("\n\n");



  /*
  ** matrici e for annidati
  **
  ** una matrice può essere pensata come quella a cui pensiamo in algebra, quindi una struttura in 
  ** cui è possibile determinare un numero di righe e di colonne e alla cui intersezione vi è posto un elemento.
  ** La stessa cosa accade nei linguaggi di programmazione: è possibile creare una matrice pensandola come 
  ** array di array, in cui andremo a viaggiare attraverso righe e colonne
  ** 
  */

    int matrice[10][5];

    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    for(unsigned short i=0; i<10; i++)
    {
        for(unsigned short j=0; j<5; j++)
        {
            if(j == 0){
                printf("|\t");
            }
            matrice[i][j] = rand()%50;
            printf("%d\t|\t",matrice[i][j]);
        }
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    }

    printf("------------------------------------------------\n\n");


    /*
    ** puntatori
    **
    **
    */


}