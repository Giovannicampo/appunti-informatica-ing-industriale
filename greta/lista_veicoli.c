/*
Il programma deve gestire una lista a puntatori, i cui elementi sono strutture.
La struttura, che rappresenta in modo semplificato un veicolo, contiene i seguenti campi:
- targa (stringa di 6 caratteri)
- modello (stringa)
- prezzo (float)
- kmPercorsi (int)
Il programma deve prevedere:
- Una funzione “inserisciVeicolo” che permetta di inserire in lista un elemento letto da
tastiera (N.B. Deve essere inserito un solo elemento alla volta). L’inserimento deve
avvenire in testa alla lista.
- Una funzione “visualizzaVeicoli” che visualizzi tutti i veicoli presenti nella lista.
- Una funzione “visualizzaSe” che visualizzi tutti i veicoli presenti nella lista di un
determinato modello (inserito da testiera) con prezzo inferiore a 4000€.
- Una funzione “minPrezzo” in grado di trovare e visualizzare il veicolo con il prezzo più
basso tra quelli presenti in lista.
Il programma deve essere completo, funzionante e deve essere corredato da un apposito menù.
Non è ammesso l’uso di variabili globali.
*/
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 31
struct Veicolo{
	char targa[M];
    char modello[N];
	float prezzo;
	int km_percorsi;
};
struct Nodo{
	struct Veicolo info;
	struct Nodo *next;
};
void menu(int *pt_opzione)
{
	printf("1) inserisci elemento in testa\n");
	printf("2) Visualizza elementi lista\n");
	printf("3) Visualizza elementi lista se\n");
	printf("4) Visualizza elemento veicolo min prezzo\n");
	printf("5) exit\n");
	printf("Inserisci opzione: ");
	scanf("%d",pt_opzione);	
}
struct Veicolo retitiuisci_info(void)
{
	struct Veicolo veicolo;
	printf("Inserisci traga veicolo: ");
	scanf("%s",veicolo.targa);
	printf("Inserisci modello veicolo: ");
	scanf("%s",veicolo.modello);
	printf("Inserisci prezzo veicolo: ");
	scanf("%f",&veicolo.prezzo);
	printf("Inserisci km veicolo: ");
	scanf("%d",&veicolo.km_percorsi);
	return veicolo;
}
struct Nodo *inserisci_in_testa(struct Nodo *lista)
{
	struct Nodo *head=NULL;
	head=(struct Nodo *)malloc(sizeof(struct Nodo));
	if (head!=NULL)
	{
		printf("Inserisci targa: ");
		scanf("%s",head->info.targa);
		printf("Inserisci modello: ");
		scanf("%s",head->info.modello);
		printf("Inserisci prezzo: ");
		scanf("%f",&head->info.prezzo);
		printf("Inserisci km_percorsi: ");
		scanf("%d",&head->info.km_percorsi);
		// oppure head->info=retitiuisci_info();
		head->next=lista;
	} 
	else
	{
		printf("Errore allocazione dinamica\n");
		// se non sono riuscito ad aggiungere in testa un nodo
		// perchè l'allocazione non è andata a buon fine restituisco
		// la lista ricevuta 
		head=lista;
	} 
	return head;
}
struct Nodo *aggiungi_in_testa(struct Nodo *lista)
{
	struct Nodo *paux=NULL;
	paux=(struct Nodo *)malloc(sizeof(struct Nodo));
	if (paux!=NULL)
	{
		paux->info=retitiuisci_info();
		// oppure
		/*
		printf("Inserisci targa: ");
		scanf("%s",paux->info.targa);
		printf("Inserisci modello: ");
		scanf("%s",paux->info.modello);
		printf("Inserisci prezzo: ");
		scanf("%f",&paux->info.prezzo);
		printf("Inserisci km_percorsi: ");
		scanf("%d",&paux->info.km_percorsi);
		*/
		paux->next=lista;
		lista=paux;
	} 
	else printf("Errore allocazione dinamica\n");
	return lista;
	// se l'allocazione dinamica fallisce restituisco
	// lista che è la lista passata senza essere stata
	// modificata
}
void visualizza_lista(struct Nodo *lista)
{
	while(lista!=NULL){
		printf("[%s %s %.2f %d] -> ",lista->info.targa,
							lista->info.modello,lista->info.prezzo,
							lista->info.km_percorsi);
		lista=lista->next;
	}
	printf("NULL\n");
}

int main(void)
{
	struct Nodo *lista=NULL;
	int opzione;
	do{	
		menu(&opzione);
		switch(opzione)
		{
			case 1:
				lista=aggiungi_in_testa(lista);
				// oppure 
				//lista=inserisci_in_testa(lista);
				break;
			case 2:	
				visualizza_lista(lista);
				break;
			/* da continuare */
			default:
				printf("Operazione non valida\n");	
		}
		getchar();
		printf("Premi invio per continuare\n");
		getchar();
	} while(opzione!=5);
}

