#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

medicament* creeaza(int cod, char* nume, double concentratie, int stoc) {
    medicament* med = malloc(sizeof(medicament));
    med->cod = cod;
    med->nume = malloc((strlen(nume) + 1) * sizeof(char));
    strcpy(med->nume, nume);
    med->concentratie = concentratie;
    med->stoc = stoc;
    return med;
}

int get_cod(medicament* m) {
    return m->cod;
}

char* get_nume(medicament* m) {
    static char nume[100];
    strcpy(nume, m->nume);
    return nume;
}

double get_concentratie(medicament* m) {
    return m->concentratie;
}

int get_stoc(medicament* m) {
    return m->stoc;
}

void set_nume(medicament* m, char* nume) {
    free(m->nume);
    m->nume = malloc(sizeof(char) * (strlen(nume) + 1));
    strcpy(m->nume, nume);
}

void set_concentratie(medicament* m, double concentratie) {
    m->concentratie = concentratie;
}

void set_stoc(medicament* m, int stoc) {
    m->stoc = stoc;
}

void medicament_to_string(medicament* m, char* rezultat) {
    sprintf(rezultat, "ID: %d Nume: %s Concentratie: %f Stoc: %d", get_cod(m), get_nume(m), get_concentratie(m), get_stoc(m));
}

void distruge_medicament(medicament* m) {
    free(m->nume);
    free(m);
}


