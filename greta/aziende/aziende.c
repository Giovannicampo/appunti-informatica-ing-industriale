#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define P 50
#define A 16
#define B 3

typedef struct{
	char denominazione[A];
	char provincia_sede [B];
	int nr_dipendenti;
	int anno_di_fondazione;
	
}AZIENDA;

int inserisci_azienda (AZIENDA *a, int nr)
{
	if (nr<P)
	{
		printf("Inserisci nome azienda:\n");
		scanf("%s",a[nr].denominazione);
		printf("Inserisci provincia sede dell' azienda:\n");
		scanf("%s",a[nr].provincia_sede);
		printf("Inserisci numero dei dipendenti:\n");
		scanf("%d", &a[nr].nr_dipendenti);
		printf("Inserisci anno di fondazione dell'azienda:\n");
		scanf("%d", &a[nr].anno_di_fondazione);
		nr++;
	}else printf("Vettore vuoto\n");
	return nr;
}


void visualizza_azienda (AZIENDA *a, int nr)
{
	int i;
	for (i=0;i<nr;i++)
	{
		printf("%d) %s %s %d %d\n", i+1, a[i].denominazione, a[i].provincia_sede, a[i].nr_dipendenti, a[i].anno_di_fondazione);
	}
}

void salva_se (AZIENDA *a, int nr)
{
	FILE *fp;
	int i, nr_dipendenti=0;
	fp=fopen("elenco_aziende_con_nr_particolari.txt", "w");
	if (fp == NULL)
	{
		printf ("Errore apertura file\n");
	}

	printf("Inserisci il numero di dipendenti\n");
	scanf("%d",&nr_dipendenti);
	for(i=0;i<nr;i++)
	{
		if(a[i].nr_dipendenti>=nr_dipendenti)
		{
			fprintf(fp, "NOME %s, nr_dipendenti %d", a[i].denominazione, a[i].nr_dipendenti);
		}
	}
	fclose(fp);
	printf("Salvataggio riuscito\n");
	
}

int mediaDipendentiAziendeAnni80 (AZIENDA *a, int nr)
{
	int i=0;
	int somma=0;
	int media;
	int count=0; //numero delle aziende che rispettano il criterio
	
	
	for (i=0;i<nr;i++)
	{
		if(a[i].anno_di_fondazione>1980 && a[i].anno_di_fondazione<1989)   
		{
			somma+=a[i].nr_dipendenti;
			count ++;
		}
	}
	
	if(count>0)
	{ 
		media=somma/count;
		return media;
	}
	
	return -1;
	

	
}


int main (void)
{
	AZIENDA aziende [P];
	int i, nr_aziende=0;
	int opzione;
	do{
		
		printf("1) Inserisci aziende\n");
		printf("2) Visualizza aziende\n");
		printf("3) Salva nel file se\n");
		printf("4) Fai la media dei dipendenti\n");
		printf("5) EXIT\n");
		printf("Inserisci un'opzione\n");
		scanf("%d",&opzione);
		switch (opzione)
		{
			case 1:
				{
				printf("Inserisci un'azienda\n");
				nr_aziende=inserisci_azienda (aziende, nr_aziende);
				break;
				}
				
			case 2:
				printf("Visualizza aziende\n");
				if(!nr_aziende)
				printf("Vettore vuoto\n");
				else visualizza_azienda (aziende, nr_aziende);
				break;
					
			case 3:
				printf("Salva sul file se\n");
				salva_se (aziende, nr_aziende);
				break;
					
			case 4:
				printf("Fai la media dei dipendenti\n");
				int media = mediaDipendentiAziendeAnni80 (aziende, nr_aziende);
				if(media >= 0) {
					printf("la media è %d\n", media);
					break;
				}
				printf("non è possibile calcolare la media\n");
				break;

			case 5:
				printf("EXIT\n");
				break;
								
			default:
				printf ("Per favore, inserisci un valore valido\n");
				break;
		}
		printf("Premi invio per continuare:\n");
		getchar();
		system("CLS");
	}while (1);
	
}
