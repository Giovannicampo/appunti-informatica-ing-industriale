#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int giorno;
    int mese;
    int anno;
} data_t;

typedef struct
{
    char regione[100];
    data_t data;
    float millimetri;
} misurazione_t;

// passaggio per valore || passaggio per riferimento

misurazione_t *crea_misurazioni(unsigned int *dim)
{
    printf("Inserisci il numero di misurazioni\n");
    scanf("%d", dim);

    misurazione_t *misurazioni = (misurazione_t *)malloc(sizeof(misurazione_t) * (*dim));

    return misurazioni;
}

void inserisci_dati_misurazioni(misurazione_t *misurazioni, int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("Inserisci la regione della misurazione %d\n", i + 1);
        scanf("%s", misurazioni[i].regione);

        printf("Inserisci il giorno della misurazione\n");
        scanf("%d", &misurazioni[i].data.giorno);

        printf("Inserisci il mese della misurazione\n");
        scanf("%d", &misurazioni[i].data.mese);

        printf("Inserisci l'anno della misurazione\n");
        scanf("%d", &misurazioni[i].data.anno);

        printf("Inserisci i millimetri della misurazione\n");
        scanf("%f", &misurazioni[i].millimetri);
    }
}

float millimetri_per_regione_per_anno(misurazione_t *misurazioni, unsigned int dim, char regione[], int anno)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        if (strcmp(misurazioni[i].regione, regione) == 0)
            if (misurazioni[i].data.anno == anno)
                return misurazioni[i].millimetri;
    }
    return -1.0;
}

data_t giorno_piu_piovoso_lombardia(misurazione_t *vet, int dim)
{
    int i;
    float max_mill = -1.0;
    int temp_index = -1;
    for (i = 0; i < dim; i++)
    {
        if (!strcmp(vet[i].regione, "Lombardia") && max_mill < vet[i].millimetri)
        {
            max_mill = vet[i].millimetri;
            temp_index = i;
        }
    }

    if (temp_index == -1)
        return (data_t){0, 0, 0};

    return vet[temp_index].data;
}

int main()
{
    unsigned int dim = 0;
    misurazione_t *misurazioni = NULL;
    misurazioni = crea_misurazioni(&dim);
    inserisci_dati_misurazioni(misurazioni, dim);

    /*
        Richiedi all'utente anno e regione di cui restituire i millimetri.
    */

    // millimetri per regione per anno
    float mill_max = millimetri_per_regione_per_anno(misurazioni, dim, "Sicilia", 2010);
    mill_max == -1.0 ? printf("Non ci sono dati sulle precipitazioni in Sicilia nel 2010\n")
                     : printf("In Sicilia nel 2010 ci sono stati %.2f millimetri di pioggia\n", mill_max);

    // giorno più piovoso in lombardia
    data_t data = giorno_piu_piovoso_lombardia(misurazioni, dim);
    data.anno == 0 ? printf("Non ci sono dati sulle precipitazioni in Lombardia\n")
                   : printf("Giorno più piovoso in lombardia: %d/%d/%d\n", data.giorno, data.mese, data.anno);
}
