#include <stdio.h>
#define MAX_MESE 14
#define MAX_NOME_AUTORE 29
#define MAX_NOME_INGREDIENTE 19
#define MAX_UNITA_DI_MISURA 14
#define MAX_NOME_RICETTA 29

typedef struct{
	int giorno;
	char mese[MAX_MESE];
	int anno;
}Data;

typedef struct{
	char nome[MAX_NOME_AUTORE];
	char cognome[MAX_NOME_AUTORE];
	Data data_di_nascita;
}Autore;

typedef struct{
	char nome[MAX_NOME_INGREDIENTE];
	int quantita;
	char unita_di_misura[MAX_UNITA_DI_MISURA];
}Ingrediente;

typedef struct{
	Autore autore;
	char nome_ricetta[MAX_NOME_RICETTA];
	int tempo_realizzazione;
	int numero_ingredienti;
	Ingrediente ingredienti[30];
}Ricetta;

void inserisci_ricette(Ricetta ricette[], int nr_ricette){
	for(unsigned int i = 0; i<nr_ricette;i++){
		printf("inserisci nome autore:\n");
		scanf("%s",&ricette[i].autore.nome);
		printf("inserisci cognome autore:\n");
		scanf("%s",&ricette[i].autore.cognome);
		printf("inserisci la data di nascita autore:\n");
		printf("inserisci il giorno di nascita autore:\n");
		scanf("%d",&ricette[i].autore.data_di_nascita.giorno);
		printf("inserisci il mese di nascita autore:\n");
		scanf("%s",&ricette[i].autore.data_di_nascita.mese);
		printf("inserisci anno di nascita autore:\n");
		scanf("%d",&ricette[i].autore.data_di_nascita.anno);
		printf("inserisci nome ricetta:\n");
		scanf("%s",&ricette[i].nome_ricetta);
		printf("inserisci tempo di realizzazione in minuti:\n");
		scanf("%d",&ricette[i].tempo_realizzazione);
		while(1){
			printf("inserisci numero ingredienti:\n");
		    scanf("%d",&ricette[i].numero_ingredienti);
			if(ricette[i].numero_ingredienti >= 1 && ricette[i].numero_ingredienti <= 30){
				break;
			}
		}
		for(unsigned int j = 0; j<ricette[i].numero_ingredienti; j++){
			printf("inserisci nome ingrediente %d:\n", j+1);
			scanf("%s",&ricette[i].ingredienti[j].nome);
			printf("inserisci quantita:\n");
			scanf("%d",&ricette[i].ingredienti[j].quantita);
			printf("inserisci unita di misura:\n");
			scanf("%s",&ricette[i].ingredienti[j].unita_di_misura);
		}
	}
}

void stampa_ricette(Ricetta ricette[],int nr_ricette){
	for(unsigned int i = 0; i<nr_ricette;i++){
		printf("%s %s, %d/%s/%d\n",ricette[i].autore.nome, ricette[i].autore.cognome, ricette[i].autore.data_di_nascita.giorno, ricette[i].autore.data_di_nascita.mese, ricette[i].autore.data_di_nascita.anno);
		printf("%s,tempo: %d minuti, ingredienti %d\n",ricette[i].nome_ricetta, ricette[i].tempo_realizzazione, ricette[i].numero_ingredienti);
		for(unsigned int j = 0; j<ricette[i].numero_ingredienti; j++){
			printf("%s: %d %s\n",ricette[i].ingredienti[j].nome , ricette[i].ingredienti[j].quantita, ricette[i].ingredienti[j].unita_di_misura);
		}
	}
}


int main(){
	Ricetta ricette[15];
	int nr_ricette;
	while(1){
		printf("inserisci un numero di ricette (maggiore o uguale a 1 e minore o uguale a 15): ");
		scanf("%d",&nr_ricette);
		if(nr_ricette >=1 && nr_ricette <=15){
			break;
		}
	}
	
	inserisci_ricette(ricette,nr_ricette);
	
	stampa_ricette(ricette,nr_ricette);
	
	
	
}

