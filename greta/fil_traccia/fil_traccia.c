#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define DIM_FILM 30

typedef struct
{
    char* titolo;
    char* genere;
    unsigned int durata;
} Film;

unsigned int _index = 0;

void insert (Film* videoteca)
{
    if(_index >= DIM_FILM){
        printf("La videoteca è piena! Non è possibile aggiungere ulteriori film!\n");
        return;
    }

    Film film;
    film.titolo = (char *) malloc(sizeof(char));
    film.genere = (char *) malloc(sizeof(char));
    printf("inserisci titolo: ");
    scanf("%s", film.titolo);
    printf("inserisci genere: ");
    scanf("%s", film.genere);
    printf("inserisci durata: ");
    scanf("%d", &film.durata);

    videoteca[_index] = film;
    _index++;
}

void printFilm(Film f) 
{
    printf("%s - %s - %d minuti\n", f.titolo, f.genere, f.durata);
}

void showAll (Film* videoteca)
{
    printf("TUTTI I FILM DELLA VIDEOTECA\n");
    for(unsigned short i=0; i<_index; i++)
    {
        printFilm(videoteca[i]);
    }
}

void showIf (Film* videoteca, char* genere)
{
    printf("Film del genere %s con durata minore di 120 minuti\n", genere);
    for(unsigned short i=0; i<_index; i++)
    {
        if( strcmp (videoteca[i].genere, genere) == 0 && videoteca[i].durata < 120) {
            printf("%s - %s - %d minuti\n", videoteca[i].titolo, videoteca[i].genere, videoteca[i].durata);
        }
    }
}

Film minFilm (Film* videoteca)
{
    if(_index < 1) {
        printf("Non ci sono film nella videoteca\n");
    }
    Film minF = videoteca[0];
    for(unsigned short i=1; i<_index; i++)
    {
        if(videoteca[i].durata < minF.durata) {
            minF = videoteca[i];
        }
    }
    return minF;
}

void helper () 
{
    printf("insert - [Inserisce un film in videoteca]\n");
    printf("showAll - [Visualizza tutti i film della videoteca]\n");
    printf("showIf - [Visualizza i film del genere selezionato con durata < 120 minuti]\n");
    printf("minFilm - [Restituisce il film con durata minore]\n");
    printf("help - [Suggerimenti]\n");
    printf("clear - [Pulisce lo schermo]\n");
    printf("exit - [Termina il programma]\n");
}

void clear () 
{
    #ifdef UNIX
        system("clear");
    #else
        system("CLS");
    #endif

}

int main () 
{
    printf("Seleziona un comando\n");
    helper ();
    char* command = (char *) malloc(sizeof(char));
    Film* videoteca = (Film *) malloc(sizeof(Film));

    while(1)
    {
        printf("> ");
        scanf("%s", command);

        if( !strcmp(command, "insert") ) {
            insert(videoteca);
            printf("\n");
        }
        else if ( !strcmp(command, "showAll") ) {
            showAll(videoteca);
            printf("\n");
        }
        else if ( !strcmp(command, "showIf") ) {
            char* genere = (char *) malloc(sizeof(char));
            printf("Inserisci il genere: ");
            scanf("%s",genere);
            if(genere != NULL) {
                showIf(videoteca,genere);
                printf("\n");
                continue;
            }
            printf("Error!\n");
            printf("\n");
        }
        else if ( !strcmp(command, "minFilm") ) {
            printf("Film con durata minore\n");
            printFilm( minFilm(videoteca) );
            printf("\n");
        }
        else if ( !strcmp(command, "help") ) {
            helper();
            printf("\n");
        }
        else if ( !strcmp(command, "clear") ) {
            clear();
        }
        else if ( !strcmp(command, "exit") ) {
            break;
        }
    }
}

