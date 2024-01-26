#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define ever (;;)

typedef struct
{
    char targa[6];
    char* modello;
    float prezzo;
    int kmPercorsi;
} Veicolo;

typedef struct
{
    Veicolo veicolo;
    struct Node* next;
} Node;

void inserisciVeicolo (Node** head)
{
    Veicolo v;

    // inserimento targa con controllo
    printf("Inserisci targa del veicolo: ");
    scanf("%s",v.targa);
    if(strlen(v.targa) > 6 || strlen(v.targa) < 1){
        printf("Error! Wrong plate inserted\n");
        return;
    }

    // inserimento modello
    printf("Inserisci modello del veicolo: ");
    v.modello = (char *) malloc(sizeof(char));
    scanf("%s",v.modello);

    // inserimento prezzo
    printf("Inserisci prezzo del veicolo: ");
    scanf("%f",&v.prezzo);

    // inserimento kmPercorsi
    printf("Inserisci kmPercorsi del veicolo: ");
    scanf("%d",&v.kmPercorsi);

    printf("\n");

    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->veicolo = v;
    new_node->next = (struct Node*) *head;
    *head = new_node;
}

void printVeicolo(Node* n)
{
    printf("\n");
    printf("VEICOLO %s\n", n->veicolo.targa);
    printf("Modello: %s\n", n->veicolo.modello);
    printf("Prezzo: %.2f\n", n->veicolo.prezzo);
    printf("Km Percorsi: %d\n", n->veicolo.kmPercorsi);
    printf("\n");
}

void visualizzaVeicoli(Node* head)
{
    if(head == NULL){
        printf("IMPOSSIBILE ESEGUIRE IL COMANDO!\n");
        return;
    }

    printf("LISTA TOTALE DEI VEICOLI PRESENTI\n");
    Node* currentNode = head;
    while(currentNode != NULL)
    {
        printVeicolo(currentNode);
        currentNode = (Node*) currentNode->next;
    }
}

void visualizzaSe(Node* head)
{
    if(head == NULL){
        printf("IMPOSSIBILE ESEGUIRE IL COMANDO!\n");
        return;
    }

    char* modello_cercato = (char *) malloc(sizeof(char));
    printf("Inserisci il modello del veicolo: ");
    scanf("%s", modello_cercato);

    printf("Lista dei veicoli col modello indicato dal prezzo minore di 4000 euro\n\n");

    Node* currentNode = head;
    while(currentNode != NULL)
    {
        if( strcmp(currentNode->veicolo.modello, modello_cercato) == 0 &&
            currentNode->veicolo.prezzo < 4000){
                printVeicolo(currentNode);
        }
        currentNode = (Node*) currentNode->next;
    }
}

void minPrezzo(Node* head)
{
    if(head == NULL){
        printf("IMPOSSIBILE ESEGUIRE IL COMANDO!\n");
        return;
    }

    Node* v_min = head;
    Node* currentNode = head;
    int temp_min = currentNode->veicolo.prezzo;

    while(currentNode != NULL)
    {
        int current_prezzo = currentNode->veicolo.prezzo;
        if(current_prezzo < temp_min){
            temp_min = current_prezzo;
            v_min = currentNode;
        }
        currentNode = (Node*) currentNode->next;
    }

    if(v_min != NULL){
        printf("VEICOLO COL PREZZO MINORE\n");
        printVeicolo(v_min);
    }
}

void helper () 
{
    printf("Seleziona uno dei seguenti comandi: \n");
    printf("insert [Inserisci un veicolo in lista]\n");
    printf("showAll [Visualizza tutti i veicoli presenti nella lista]\n");
    printf("showIf [Visualizza, di un modello indicato dall'utente, i veicoli con prezzo minore di 4000 euro]\n");
    printf("minPrice [Visualizza il veicolo col costo minore]\n");
    printf("\n");
}

int main()
{
    Node* head = NULL;
    
    printf("VEHICLE HANDLER\n\n");
    helper();

    for ever 
    {
        printf("$ ");
        char* command = (char*) malloc(sizeof(char));
        scanf("%s", command);

        if( strcmp(command, "insert") == 0 ) {
            inserisciVeicolo(&head);
        }
        else if ( strcmp(command, "showAll") == 0 ) {
            visualizzaVeicoli(head);
        }
        else if ( strcmp(command, "showIf") == 0 ) {
            visualizzaSe(head);
        }
        else if ( strcmp(command, "minPrice") == 0 ) {
            minPrezzo(head);
        }
        else if ( strcmp(command, "help") == 0 ) {
            helper();
        }
        else {
            printf("COMMAND NOT FOUND!\n");
        }
    }
}


