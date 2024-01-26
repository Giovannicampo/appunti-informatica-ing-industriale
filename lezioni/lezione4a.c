#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
** Le STRUCT sono tipi strutturati simili agli array, ma che non richiedono che i dati al loro interno siano dello stesso tipo
** e in ordine. E' possibile aggiungere dati di tipo primitivo o struct a loro volta all'interno di nuove struct.
**
** Si usa la parola chiave typedef e la parola chiave struct, Persona è il nome del nuovo tipo di struttura disponibile nel codice
*/
typedef struct{
    char* nome;
    char* cognome;
    int eta;
    char* professione;
} Persona;

typedef struct{
    Persona persone[10];
    char* nome;
    int anni_XP;
} Team;

void print_ID(Persona p)
{
    printf("Nome: %s, Cognome: %s, eta': %d, professione: %s\n", p.nome, p.cognome, p.eta, p.professione);
}

void print_team_info(Team t)
{
    printf("Team: %s, years of experience: %d\n", t.nome, t.anni_XP);
    for(unsigned short i=0; i<10; i++){
        if(t.persone[i].nome != NULL){
            print_ID(t.persone[i]);
        }
    }
}

int main()
{
    // se un elemento è allocato staticamente ci si può accedere con la notazione puntata
    Persona p1;
    p1.nome = "Giovanni";
    p1.cognome = "Campo";
    p1.eta = 21;
    p1.professione = "Studente";

    print_ID(p1);
    printf("\n");

    Team t;
    t.persone[0] = p1;
    t.nome = "TEAM";
    t.anni_XP = 2;
    print_team_info(t);
    printf("\n");

    Persona* p2 = (Persona*) malloc(sizeof(char)+sizeof(int));

    // se un elemento è allocato dinamicamente e quindi è un puntatore, ci si può accedere attraverso l'operatore freccia ->
    p2->nome = "Melo";
    p2->cognome = "Meluccio";
    p2->eta = 50;
    p2->professione = "Mercante";

    print_ID(*p2);
    printf("\n");

    Team* t2 = &t;
    t2->nome = "A-Team";
    t2->persone[0] = p1;
    t2->persone[1] = *p2;
    t2->anni_XP = 10;

    print_team_info(*t2);
}