#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define T 6
#define M 42
#define P 50
#define UNIX
// #define WINDOWS

typedef struct{
	char targa[T];
	char modello [M];
	float prezzo;
	int km_percorsi;
	
}VEICOLO;


int inserisci_veicolo (VEICOLO *v, int nr)
{
	if (nr<P)
	{
		printf("Inserisci targa del veicolo:\n");
		fgets(v[nr].targa,T,stdin);
		if(strlen(v[nr].targa)==T-1) while (getchar()!='\n');
		else v[nr].targa [strlen(v[nr].targa)-1]='\0';
		printf("Inserisci il modello del veicolo:\n");
		fgets(v[nr].modello,M,stdin);
		if(strlen(v[nr].modello)==M-1) while (getchar()!='\n');
		else v[nr].modello [strlen(v[nr].modello)-1]='\0';
		printf("Inserisci prezzo del veicolo:\n");
		scanf("%f",&v[nr].prezzo);
		printf("Inserisci km percorsi dal veicolo:\n");
		scanf("%d%*c",&v[nr].km_percorsi);
		nr++;
		
	}
	else printf("Vettore pieno\n");
	return nr;
	
}

void visualizza_veicoli (VEICOLO *v, int nr)
{
	int i;
	for (i=0;i<nr;i++)
	{
		printf("%d) %s %s %.2f %d\n",i+1,v[i].targa,v[nr].modello,v[nr].prezzo,v[nr].km_percorsi);
	}
}

void visualizza_se (VEICOLO *v, int nr, char *modello)
{
	int i;
	printf("Visualizza %s modello con prezzo inferiore a 4000 euro",modello);
	for (i=0;i<nr;i++){
		if( (strcmp(v[i].modello,modello)==0) && v[i].prezzo<4000 ) 
		{
			printf("ecco i %s modello, %f prezzo", v[i].modello, v[i].prezzo);
		}
		
	}
}

void min_prezzo (VEICOLO *v, int nr, float prezzo)
{
	int i, indice_minimo=0;
	printf("Visulizza veicolo con prezzo pi� basso tra quelli presenti in lista\n");
	for(i=1;i<nr;i++){
		if(v[i].prezzo<v[indice_minimo].prezzo){
			indice_minimo=i;
		}
	} printf ("Ecco il modello %s che ha %f piu' basso", v[indice_minimo].modello, v[indice_minimo].prezzo);
	
}

int main (void)
{
	VEICOLO* veicoli = (VEICOLO *) malloc(sizeof(VEICOLO)*P);
	float prezzo;
	int nr_veicoli=0;
	int opzione;
	do{
		printf("1) Inserisci veicolo\n");
	    printf("2) Visualizza veicolo\n");
		printf("3) Visualizza se\n");
		printf("4) Visualizza Minor prezzo disponibile\n");
		printf("5) EXIT\n");	
		printf("Inserisci opzione\n");
		scanf("%d",&opzione);
		switch(opzione)
		{
			case 1:
				printf("inserisci veicolo:\n");
				nr_veicoli=inserisci_veicolo (veicoli, nr_veicoli);
				printf("nr = %d\n", nr_veicoli);
				break;
				
			case 2:
				printf("Visualizza veicoli:\n");
				if(!nr_veicoli)
			
					printf("Vettore vuoto\n");
				else 
				visualizza_veicoli(veicoli,nr_veicoli);
				break;
			case 3:
				printf("visualizza se:\n");
				if(!nr_veicoli)
				{
				printf("vettore vuoto\n");
				}
				else 
				printf("Inserisci il modello del veicolo:\n");
				char* modello = (char *) malloc(sizeof(char)*M);
				fgets(modello,M,stdin);
				if(strlen(modello)==M-1) while (getchar()!='\n');
				else {
					modello [strlen(modello)-1]='\0';
					visualizza_se (veicoli, nr_veicoli, modello);
					}
				break;
			case 4:
				printf("Visualizza il minor prezzo disponibile nella lista\n");
				if(!nr_veicoli)
				printf("vettore vuoto:\n");
				else min_prezzo (veicoli,nr_veicoli,prezzo);
			break;
					
			}
			printf("Premi invio per continuare\n");
			getchar();	

			#ifdef WINDOWS
			system("CLS");
			#endif

			// #ifdef UNIX
			// system("clear"); 
			// #endif
	}while(opzione!=5);
}
