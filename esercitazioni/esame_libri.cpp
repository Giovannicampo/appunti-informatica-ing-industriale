#include <stdio.h>

#define MAX_NOME_AUTORE 19
#define MAX_COGNOME_AUTORE 19
#define MAX_TITOLO_LIBRO 29
#define MAX_DESCR_COLLEZIONE 29

typedef struct{
	char nome[MAX_NOME_AUTORE];
	char cognome[MAX_COGNOME_AUTORE];
}Autore;

typedef struct{
	char titolo[MAX_TITOLO_LIBRO];
	int anno_di_pubblicazione;
	int numero_di_autori_del_libro;
	Autore autori[4];
}Libro;

typedef struct{
	char descrizione_della_collezione[MAX_DESCR_COLLEZIONE];
	int nr_libri;
	Libro libri[20];
}Collezione;

void inserisci_libri(Collezione* collezione){
	for(unsigned int i=0; i<collezione->nr_libri; i++){
		printf("inserisci il titolo del libro %d:\n",i+1);
		scanf("%s",collezione->libri[i].titolo);
		printf("inserisci anno di pubblicazione del libro:\n");
		scanf("%d",&collezione->libri[i].anno_di_pubblicazione);
		while(1){
			printf("inserisci il numero di autori del libro:\n");
			scanf("%d",&collezione->libri[i].numero_di_autori_del_libro);
			if(collezione->libri[i].numero_di_autori_del_libro >= 1 && collezione->libri[i].numero_di_autori_del_libro <= 4){
				break;
			}
		}
		for(unsigned int j=0; j<collezione->libri[i].numero_di_autori_del_libro; j++){
			printf("inserisci il nome autore:\n");
			scanf("%s",collezione->libri[i].autori[j].nome);
			printf("inserisci il cognome autore:\n");
			scanf("%s",collezione->libri[i].autori[j].cognome);
		}
	}
}

void stampa_libri(Collezione collezione){
	printf("%s\n numero di libri:%d\n",collezione.descrizione_della_collezione, collezione.nr_libri);
	for(unsigned int i=0; i<collezione.nr_libri; i++){
		printf("%s, numero autori:%d, anno di pubblicazione:%d\n",collezione.libri[i].titolo, collezione.libri[i].numero_di_autori_del_libro, collezione.libri[i].anno_di_pubblicazione);
		for(unsigned int j=0; j<collezione.libri[i].numero_di_autori_del_libro; j++){
			printf("%s %s",collezione.libri[i].autori[j].nome, collezione.libri[i].autori[j].cognome);
		}
	}
}

int main(){
	Collezione collezione;
	printf("fornisci una descrizione per la collezione di libri:");
	scanf("%s",collezione.descrizione_della_collezione);
	while(1){
		printf("inserisci i libri della collezione (maggiore o uguale a 1 e minore o uguale a 20):");
		scanf("%d",&collezione.nr_libri);
		if(collezione.nr_libri>=1 && collezione.nr_libri<=20){
			break;
		}
	}
	
inserisci_libri(&collezione);

stampa_libri(collezione);
	
}
