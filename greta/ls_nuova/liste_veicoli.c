#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define T 6
#define M 16

struct VEICOLO{
	char targa [T];
	char modello[M];
	float prezzo;
	int km_percorsi;
};

struct Nodo{
	struct VEICOLO info;
	struct Nodo* next;	
};

struct VEICOLO crea_veicolo ()
{
	struct VEICOLO v;
	printf("Inserisci targa:\n");
	scanf("%s",v.targa );
	printf("Inserisci modello:\n");
	scanf("%s", v.modello);
	printf("Inserisci prezzo:\n");
	scanf("%f", &v.prezzo);
	printf("Inserisci km_percorsi\n");
	scanf("%d", &v.km_percorsi);
	return v;
}


struct Nodo* inserisci_in_testa (struct Nodo *lista)
{
	struct Nodo* head=NULL;
	head=(struct Nodo*)malloc(sizeof(struct Nodo));
	if (head!=NULL)
	{
		head->info = crea_veicolo ();
		head->next = (struct Nodo *) lista;
		return head;	
	}
	printf("Errore allocazione\n");
	return lista;
	

}

void print_veicolo (struct VEICOLO v)
{
	printf("Targa %s, modello %s, prezzo %f, km_percorsi %d\n", v.targa, v.modello, v.prezzo, v.km_percorsi);
}

void visualizza_veicoli (struct Nodo* lista)
{
	struct Nodo* current=lista;
	while (current!=NULL)
	{
		print_veicolo(current->info);
		current = current->next;
	}
}

void visualizza_se (struct Nodo* lista)
{
	char modello[M];
	printf("Inserisci gentilmente il modello desiderato:\n");
	scanf("%s",modello);
	struct Nodo* current=lista;
	while (current!=NULL)
	{
		struct VEICOLO v= current->info;
		if (strcmp (v.modello,modello )==0 && v.prezzo<4000)
		{
			print_veicolo(v);
		}
		current = current->next;
	}
}


void visualizza_minPrezzo (struct Nodo* lista)
{
	struct VEICOLO min_v = lista->info;
	struct Nodo* current=lista;
	while (current!=NULL)
	{
		struct VEICOLO v = current->info;
		if(v.prezzo<min_v.prezzo)
		{
			min_v=v;
		}
		current =  current->next;
	}
		print_veicolo(min_v);
}

void scrivi_su_file (struct Nodo* lista)
{
	FILE *fp;
	int i;
	fp=fopen("elenco_veicoli.txt", "w");
	if(fp==NULL) 
	{ 
		printf("Errore apertura file\n");
		return;
	}	
	struct Nodo* current = lista;
	while (current!=NULL)
	{
		struct VEICOLO v = current->info;
		fprintf(fp, "Targa %s, Modello %s, Prezzo %f, km_percorsi %d\n",v.targa,v.modello,v.prezzo,v.km_percorsi);
		current =  current->next;
	}
	fclose(fp);
}

int main (void)
{
	struct Nodo* lista=NULL;
	int opzione;
	do{
		printf("1)Inserisci veicolo\n");
		printf("2) Visualizza veicolo\n");
		printf("3) Visualizza se\n");
		printf("4) Visualizza min prezzo\n");
		printf("5) Stampa su file\n");
		printf("Inserisci un'opzione\n");
		scanf("%d", &opzione);
		switch(opzione)
		{
			case 1:
				{
					printf("Inserisci veicolo\n");
					lista=inserisci_in_testa(lista);
					break;
				}
				
				case 2:
					{
						printf("Visualizza tutti i veicoli\n");
						visualizza_veicoli (lista);
						break;
					}
					
					case 3:
						{
							printf("Visualizza se:\n");
							visualizza_se (lista);
							break;
						}
						case 4:
							{
								printf("Visualizza min prezzo\n");
								visualizza_minPrezzo (lista);
								break;
							}
							
							case 5:
								{
									printf("Salva su file\n");
									scrivi_su_file (lista);
									break;
								}
								
								default: 
								printf("Inserisci un valore valido!!!!\n");
								break;
		}
		printf("Premi invio per continuare\n");
		getchar();
		// system ("clear");
		}
	while (1);
	
}
