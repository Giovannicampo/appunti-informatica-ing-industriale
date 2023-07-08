#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int giorno;
    char mese[14];
    int anno;
} Data;

typedef struct
{
    char codice[5];
    char titolo[30];
    Data data_di_pubblicazione;
} Libro;

typedef struct
{
    char nome[29];
    char cognome[29];
    int num_libri;
    Libro libri[3];
} Autore;

int riempi_autori_da_file(Autore autori[], int max_autori)
{
    int nr_autori = 0;
    FILE* fp1;
    fp1 = fopen("elenco_autori.txt","r");
    if(fp1 == NULL){
        printf("Errore nell'apertura del file\n");
        return 0;
    }

    for(unsigned int i=0; i<max_autori; i++)
    {
        if(fscanf(fp1,"%s %s %d", autori[i].nome, autori[i].cognome, &autori[i].num_libri) == 3)
        {
            nr_autori++;

            if(autori[i].num_libri > 3){
                autori[i].num_libri = 3;
            }
            for(unsigned int j=0; j<autori[i].num_libri; j++)
            {
                fscanf(fp1,"%s %s %d %s %d", autori[i].libri[j].codice, autori[i].libri[j].titolo, &autori[i].libri[j].data_di_pubblicazione.giorno, autori[i].libri[j].data_di_pubblicazione.mese, &autori[i].libri[j].data_di_pubblicazione.anno);
            }
        }
    }

    fclose(fp1);

    if(nr_autori > max_autori){
        return max_autori;
    }
    return nr_autori;
}

void stampa_autori(Autore autori[], int num_autori)
{
    for(unsigned int i=0; i<num_autori; i++)
    {
        printf("%s %s %d\n",autori[i].nome, autori[i].cognome, autori[i].num_libri);
        for(unsigned int j=0; j<autori[i].num_libri; j++)
        {
                printf("\t%s %s %d %s %d\n", autori[i].libri[j].codice, autori[i].libri[j].titolo, autori[i].libri[j].data_di_pubblicazione.giorno, autori[i].libri[j].data_di_pubblicazione.mese, autori[i].libri[j].data_di_pubblicazione.anno);
        }
    }
}

Libro* restituisci_elenco_libri(Autore autori[], int num_autori, char nome[], char cognome[], int* nr_libri)
{
    Libro* libro = NULL;
    for(unsigned int i=0; i<num_autori; i++)
    {
        if((!strcmp(autori[i].nome,nome)) && (!strcmp(autori[i].cognome,cognome)) && (autori[i].num_libri > 0))
        {
            *nr_libri = autori[i].num_libri;
            libro = (Libro*) malloc(sizeof(Libro)*(*nr_libri));
            if(libro == NULL){
                *nr_libri = 0;
                return NULL;
            }
            for(unsigned short j=0; j<autori[i].num_libri; j++)
            {
                libro[i] = autori[i].libri[j];
                printf("%s\n",libro[i].titolo);
            }
            break;
        }
    }
return libro;
}

int main()
{
    Autore autori[5];
    int nr_autori;
    nr_autori = riempi_autori_da_file(autori,5);
    printf("Numero di autori = %d\n", nr_autori);
    stampa_autori(autori, nr_autori);

    Libro* libri;
    int nr_libri;
    char nome[29];
    char cognome[29];
    printf("\nInserisci nome e cognome dell'autore che cerchi:");
    scanf("%s %s",nome, cognome);

    libri = restituisci_elenco_libri(autori, nr_autori, nome, cognome, &nr_libri);
    
    if(libri != NULL){
        for(unsigned short i=0; i<nr_libri; i++)
        {
            printf("%s %s %d %s %d\n",libri[i].codice, libri[i].titolo, libri[i].data_di_pubblicazione.giorno, libri[i].data_di_pubblicazione.mese, libri[i].data_di_pubblicazione.anno);
        }
    }

}


