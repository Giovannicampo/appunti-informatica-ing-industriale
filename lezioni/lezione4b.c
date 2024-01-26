#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_W 30

typedef int euro;
typedef int months;

typedef struct{
    char* name;
    char* profession;
    months months_of_XP;
} Worker;

typedef struct{
    char* name;
    Worker workers[NUM_W];
    months num_of_months;
    euro money;
} Company;

char* names[20] = {
                    "Melo", "Giovanni", "Teo", "Franco", "Ciccio", 
                    "Saro", "Alessio", "Sara", "Ciccia", "Tiziana", 
                    "Gaia", "Alice", "Alexia", "Mela", "Maria", 
                    "Roberta", "Elena", "Ture", "Michele", "Antonio" 
                    };

char* professions[10] = {
                            "Programmer", "Analyst", "Frontender", "Backender", "IoT expert",
                            "Sales assistant", "Chief", "Roboticist", "Cyber Engineer", "Data Scientist"
                            };

void initialize_worker(Worker* w){
    int rand_name = rand()%20;
    int rand_prof = rand()%10;
    w->name = names[rand_name];
    w->profession = professions[rand_prof];
    w->months_of_XP = (rand()%73);
}

void initialize_company(Company* c){
    char* str = (char*) malloc(sizeof(char)*10);
    printf("Write the name of your company:");
    scanf("%s",str);
    c->name = str;
    for(unsigned short i=0; i<NUM_W; i++){
        initialize_worker(&c->workers[i]);
    }
    c->num_of_months = 0;
    c->money = 10000;
}

void print_worker(Worker w){
    printf("%s, %s, %d years of experience\n", w.name, w.profession, w.months_of_XP/12);
}

void print_company_info(Company c){
    printf("------- %s -------\n", c.name);
    for(unsigned short i=0; i<NUM_W; i++){
        print_worker(c.workers[i]);
    }
    printf("Months of life: %d\n", c.num_of_months);
    printf("Euros gained: %d\n", c.money);
}

euro avg_money_per_job_per_month(char* job)
{
    if(job == "Programmer" || job == "Backender"){
        return 1200;
    }
    else if(job == "Sales assistant"){
        return 2000;
    }
    else if(job == "Analyst" || job == "Frontender"){
        return 2600;
    }
    else if(job == "IoT expert" || job == "Roboticist"){
        return 3200;
    }
    return 3500;
}

void work(Company* c, months m){
    c->num_of_months += m;
    for(unsigned short i=0; i<NUM_W; i++){
        c->workers[i].months_of_XP += m;
        c->money += avg_money_per_job_per_month(c->workers[i].profession)*m;
    }
}

void print_money_report(Company c)
{
    printf("-------- Money Report --------\n");
    printf("Euros gained: %d\n", c.money);
    int total_money_per_month = 0;
    for(unsigned short i=0; i<NUM_W; i++){
        total_money_per_month += avg_money_per_job_per_month(c.workers[i].profession);
    }
    float avg_salary = (float)total_money_per_month/NUM_W;
    printf("Average salary: %.2f\n",avg_salary);
}

// Simulation of a company

int main()
{
    srand(time(NULL));
    Company GLG;
    initialize_company(&GLG);
    print_company_info(GLG);
    printf("\n");
    work(&GLG,6);
    print_money_report(GLG);
}