#include "teste.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../domain/domain.h"
#include "../service/service.h"
#include "../repo/lista.h"
#include "../repo/repo.h"
#include "../validator/validator.h"

void teste_domain() {
    medicament med1;
    med1.cod = 100;
    med1.nume = malloc(sizeof(char) * (strlen("Paracetamol") + 1));
    strcpy(med1.nume, "Paracetamol");
    med1.concentratie = 10.1;
    med1.stoc = 1;
    assert(get_cod(&med1) == 100);
    assert(get_stoc(&med1) == 1);
    assert(get_concentratie(&med1) == 10.1);
    assert(strcmp(get_nume(&med1), "Paracetamol") == 0);
    free(med1.nume);
    medicament* med2 = creeaza(50, "Decasept", 15.1, 3);
    assert(get_cod(med2) == 50);
    assert(get_concentratie(med2) == 15.1);
    assert(get_stoc(med2) == 3);
    assert(strcmp(get_nume(med2), "Decasept") == 0);
    char afis[300] = "";
    medicament_to_string(med2, afis);
    distruge_medicament(med2);
    assert(strcmp("ID: 50 Nume: Decasept Concentratie: 15.100000 Stoc: 3", afis) == 0);
}

void teste_repo() {
    lista_med* test = creeaza_lista();
    medicament* med1 = creeaza(1, "Strepsils", 123.123, 500);
    adaugare_repo(test, med1);
    assert(test->lg == 1);
    assert(strcmp(get_nume(test->list[0]), "Strepsils") == 0);
    assert(get_cod(test->list[0]) == 1);
    medicament* med2 = creeaza(1, "Neuromax", 1.23, 500);
    int err = adaugare_repo(test, med2);
    distruge_medicament(med2);
    medicament* med3 = creeaza(3, "Ibuprofen", 1.50, 100);
    adaugare_repo(test, med3);
    medicament* med10 = creeaza(10, "Amoxicilina", 5.00, 60);
    adaugare_repo(test, med10);
    assert(err == 5);
    //printf("%d", test->list[0].cod);
    distruge_repo(test);
    //printf("%d", test->list[0].cod);
}
void teste_validator() {
    medicament med1 = {-1, "Theraflu", 123.2, 2};
    assert(valideaza(&med1) == 1);
    medicament med2 = {1, "", 123.2, 2};
    assert(valideaza(&med2) == 2);
    medicament med3 = {1, "Bun", -1.2, 2};
    assert(valideaza(&med3) == 3);
    medicament med4 = {1, "Bun", 2, -4};
    assert(valideaza(&med4) == 4);
    medicament valid = {2, "Paracetamol", 1.1, 3};
    assert(valideaza(&valid) == 0);
}

void teste_service() {
    lista_med* test = creeaza_lista();
    adauga_medicament(test, 1, "Theraflu", 12.12, 5);
    adauga_medicament(test, 2, "Z-A vitamine", 2.12, 6);
    int err1 = adauga_medicament(test, -1, "Norofen", 1, 1);
    assert(err1 == 1);
    int err5 = adauga_medicament(test, 1, "Aspocardin", 123.123, 10);
    assert(err5 == 5);
    assert(get_lista(test)->lg == 2);
    assert(get_cod(get_lista(test)->list[0]) == 1);
    int err0_1 = adauga_medicament(test, 3, "Coldrax", 1.12, 3);
    assert(err0_1 == 0);
    int err5_2 = adauga_medicament(test, 2, "Parasinus", 2.12, 7);
    assert(get_stoc(get_lista(test)->list[1]) == 7);
    assert(err5_2 == 5);
    assert(strcmp(get_nume(get_lista(test)->list[1]), "Z-A vitamine")== 0);
    int err2 = modificare_medicament(test, 1, "", 50);
    assert(err2 == 2);
    int err7 = modificare_medicament(test, 100, "Calma", 5);
    assert(err7 == 7);
    int err0 = modificare_medicament(test, 1, "aspacardin", 90.3);
    assert(err0 == 0);
    assert(get_concentratie(get_lista(test)->list[0]) == 90.3);
    assert(test->lg == 3);
    int err0_d = stergere_stoc(test, 1);
    assert(err0_d == 0);
    int err7_d = stergere_stoc(test, 12333);
    assert(err7_d == 7);
    adauga_medicament(test, 4, "A-Z vitamine", 2.12, 6);
    assert(test->capacitate == 4);
    lista_med* copie = sortare_medicament(test, sortare_crescator);
    assert(get_stoc(copie->list[0]) == 3);
    assert(get_stoc(copie->list[1]) == 6);
    distruge_repo(copie);
    lista_med* copie2 = sortare_medicament(test, sortare_descrescator);
    assert(get_stoc(copie2->list[0]) == 7);
    assert(get_stoc(copie2->list[1]) == 6);
    distruge_repo(copie2);
    assert(strcmp(get_nume(test->list[0]), "A-Z vitamine") != 0);
    lista_med* copie3 = sortare_medicament(test, sortare_alfabetic);
    assert(strcmp(get_nume(copie3->list[0]), "A-Z vitamine") == 0);
    assert(strcmp(get_nume(copie3->list[1]), "Coldrax") == 0);
    assert(strcmp(get_nume(copie3->list[2]), "Z-A vitamine") == 0);
    distruge_repo(copie3);
    lista_med* lista_filtrare1 = filtrare_stoc(test, 7);
    assert(lista_filtrare1->lg == 2);
    lista_med* lista_filtrare2 = filtrare_nume(test, 'C');
    assert(lista_filtrare2->lg == 1);
    assert(lista_filtrare2->list[0]->stoc == 3);
    distruge_repo_partial(lista_filtrare1);
    distruge_repo_partial(lista_filtrare2);
    distruge_repo(test);
}

void ruleaza_teste() {
    teste_domain();
    teste_repo();
    teste_validator();
    teste_service();
}
