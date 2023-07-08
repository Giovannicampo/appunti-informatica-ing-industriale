#include <stdio.h>

int main()
{
    int var = 15;
    int var_2 = 30;

    float pippo = 3.5;
    char melo = 'd';

    if(var == 10)
    {
        // codice se la condizione dell'if è vera
        printf("var è uguale a 10\n");
    }

    // var_2 viene decrementata se è maggiore di var
    if(var_2 > var)
    {
        var_2--;
    }
    printf("%d",var_2);

    printf("\n\n");

    // stampo il risultato di una espressione booleana
    printf("il valore di var è uguale a quello di var_2? Risposta = %d\n", var == var_2);

    // stampo un carattere
    printf("%d\n\n", 'd');

    melo = 'b';

    // switch // non ti scordare il break
    switch(melo){
        case 'a':{
            printf("melo\n");
            break;
        }

        case 'b':{
            printf("ture\n");
            break;
        }

        case 'c':{
            printf("ciccio\n");
            break;
        }

        case 'd':{
            printf("saro\n");
            break;
        }

        default:{
            break;
        }

    }

    // stampo il valore e poi l'indirizzo di una variabile
    char var_3 = 'o';
    printf("%d\n",var_3);
    // printf("%n\n",&var_3);

    // scanf
    printf("Inserisci un valore\n");
    scanf("%c",&var_3);
    printf("valore inserito è: %c\n", var_3);



    // scope

    // a si trova nello scope del main
    int a = 10;

    {
        int b = 10;
        printf("%d\n",a); // nessun problema posso stampare
    }
    // printf("%d",b); // non funziona b dichiarato in un altro scope

    if(a == 10){
        int c = 10;
        printf("%d\n\n",c);
    }
    int c = 5;





    // iterazioni

    int counter = 0;

    // do while
    do{
        printf("%d\t",counter);
        counter++;
    }
    while(counter < 10);
    printf("\n");

    // while
    int i = 1;
    while(i < 10)
    {
        printf("%d\t",i);
        i*=2;
    }
    printf("\n");

    //for
    for(int i=0; i<20; i++){
        printf("%d\t",i*5);
    }
    


    
}