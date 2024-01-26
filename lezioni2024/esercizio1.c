#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define DEST_NUM 5

struct Date
{
    int day;
    int month;
    int year;
};

struct Destination
{
    char *name;
    struct Date departure;
    struct Date arrival;
    unsigned int price;
    unsigned int availability;
};

char *destinazione_con_maggiori_posti(struct Destination *destinations, unsigned int num_destinations)
{
    // num_of_max_available_dest ci servirà per capire se tutte le destinazioni hanno la stessa disponibilità
    unsigned int num_of_max_available_dest = 1;

    // temp_dest è la variabile temporanea che viene aggiornata se nell'array destinations sono presenti
    // destinazioni con disponibilità maggiore
    struct Destination temp_dest = destinations[0];

    // variabile che se vale zero dopo la fine del ciclo, fa ritornare la stringa vuota alla funzione
    unsigned int max_availability = temp_dest.availability;

    for (unsigned short i = 1; i < num_destinations; i++)
    {

        // aggiorniamo la destinazione temporanea se la dest corrente nell'array ha disponibilità maggiore
        // e non aggiorniamo il numero di destinazioni che hanno la stessa disponibilità
        if (temp_dest.availability < destinations[i].availability)
        {
            max_availability = destinations[i].availability;
            temp_dest = destinations[i];
            continue;
        }

        // se la destinazione temporanea è comunque maggiore della dest corrente,
        // evitiamo di aggiornare num_of_max_available_dest
        if (temp_dest.availability > destinations[i].availability)
            continue;

        num_of_max_available_dest++;
    }

    // controlli richiesti dal problema
    if (num_of_max_available_dest == num_destinations || max_availability == 0)
        return "";

    return temp_dest.name;
}

int prezzo_totale(struct Destination *destinations, unsigned int num_destinations, char **locs, unsigned int num_locs, unsigned int num_ospiti)
{
    unsigned int matching_dests = 0;
    unsigned int total_price = 0;
    for (unsigned short i = 0; i < num_destinations; i++)
    {
        for (unsigned short j = 0; j < num_locs; j++)
        {
            // si confrontano il nome della destinazione i-esima e il nome della località j-esima
            // se il ritorno di strcmp è uguale a zero, le stringhe sono uguali
            if (strcmp(destinations[i].name, locs[j]) == 0)
            {
                // si controlla che la destinazione abbia disponibilità almeno per num_ospiti
                if (destinations[i].availability >= num_ospiti)
                {
                    total_price += destinations[i].price;
                    matching_dests++;
                    break;
                }
            }
        }
    }

    // se matching_dests non è uguale a num_destinations, non tutte le destinazioni hanno disponibilità per num_ospiti ospiti
    if (matching_dests != num_destinations)
        return -1;
    return total_price;
}

int main()
{
    // allocazione dinamica
    // struct Destination *destinations = (struct Destination *)malloc(sizeof(struct Destination) * DEST_NUM);

    // allocazione statica
    struct Destination destinations[DEST_NUM] = {
        {"Miami", {12, 05, 2024}, {25, 05, 2024}, 1000, 16},
        {"Paris", {12, 05, 2024}, {25, 05, 2024}, 1500, 10},
        {"London", {12, 05, 2024}, {25, 05, 2024}, 1000, 17},
        {"Barcelona", {12, 05, 2024}, {25, 05, 2024}, 1000, 10},
        {"Catania", {12, 05, 2024}, {25, 05, 2024}, 1000, 18}};

    printf("The destination with max availability is: %s\n", destinazione_con_maggiori_posti(destinations, DEST_NUM));

    char *Locs[5] = {"Miami", "Paris", "London", "Barcelona", "Catania"};
    unsigned int ospiti = 10;

    int prezzo_totalee = prezzo_totale(destinations, DEST_NUM, Locs, DEST_NUM, ospiti);
    printf("Total price: %d \n", prezzo_totalee);
}
