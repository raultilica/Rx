#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct {
    int cod;
    char* nume;
    double concentratie;
    int stoc;
}medicament;

medicament* creeaza(int cod, char* nume, double concentratie, int stoc);
/*Functia creeaza un medicament
 *cod - int
 *nume - pointer la char
 *concentratie - double
 *stoc -int
 *return: medicament
 */

int get_cod(medicament* m);
/*
 *Functia returneaza codul unui medicament m
 */
char* get_nume(medicament* m);
/*
 *Functia returneaza adresa numelui unui medicament m
 */
double get_concentratie(medicament* m);
/*
 *Functia returneaza concentratia unui medicament m
 */

int get_stoc(medicament* m);
/*
 *Functia returneaza stocul unui medicament m
 */

void set_nume(medicament* m, char* nume);
/*
 * Functia seteaza numele unui medicament m.
 */

void set_concentratie(medicament* m, double concentratie);
/*
 * Functia seteaza concentratia unui medicament m.
 */

void set_stoc(medicament* m, int stoc);
/*
 * Functia seteaza stocul unui medicament m.
 */

void medicament_to_string(medicament* m, char* rezultat);
/*
 * Functia transforma informatiile unui medicament m intr-un string
 * m - un pointer la un medicament m
 * rezultat - poiter la char
 * return -
 */

void distruge_medicament(medicament* m);
/*
 * Functia elibereaza memoria ocupata de un medicament m, inclusiv campurile sale alocate dinamic
 */

#endif //DOMAIN_H
