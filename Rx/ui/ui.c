#include <stdio.h>
#include <string.h>
#include "ui.h"

#include "../repo/lista.h"
#include "../service/service.h"
#include "../domain/domain.h"

void afisare(lista_med* repo) {
    for (int i = 0; i < repo->lg; i++) {
        char rez[500];
        medicament_to_string(repo->list[i], rez);
        printf("%s\n", rez);
        //printf("ID: %d Nume: %s Concentratie: %f Stoc: %d\n", get_cod(&repo->list[i]), get_nume(&repo->list[i]), get_concentratie(&repo->list[i]), get_stoc(&repo->list[i]));
    }
}

void sterge_buffer() {
    while (getchar() != '\n');
}

char citeste_char(char* mesaj) {
    char val;
    printf("%s", mesaj);
    while (scanf("%c", &val) != 1) {
        sterge_buffer();
        printf("Input valid.\n%s", mesaj);
    }
    sterge_buffer();
    return val;
}

float citeste_float(char* mesaj) {
    float val;
    printf("%s", mesaj);
    while (scanf("%f", &val) != 1) {
        sterge_buffer();
        printf("Input valid.\n%s", mesaj);
    }
    sterge_buffer();
    return val;
}

int citeste_int(char *mesaj) {
    int val;
    printf("%s", mesaj);
    while (scanf("%d", &val) != 1) {
        sterge_buffer();
        printf("Input invalid.\n%s", mesaj);
    }
    sterge_buffer();
    return val;
}

void citeste_string(char* str, char* mesaj, const int len) {
    printf("%s", mesaj);
    fgets(str, len, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void adaugare(lista_med* repo, char erori[][50]) {
    //cod, nume, concentratie, cantitate
    int cod = citeste_int("Introdu codul:\n");
    char nume[100];
    citeste_string(nume, "Introdu numele medicamentului:\n", sizeof(nume));
    double concentratie = citeste_float("Introdu concentratia:\n");
    int stoc = citeste_int("Introdu cantitatea disponibila in stoc:\n");
    int eroare = adauga_medicament(repo, cod, nume, concentratie, stoc);
    if (eroare)
        printf("%s", erori[eroare]);
    else
        printf("Adaugarea s-a realizat cu succes!\n");
}

void modificare(lista_med* repo, char erori[][50]) {
    if (repo->lg == 0) {
        printf("Nu exista medicamente!\n");
        return;
    }
    printf("Selecteaza un medicament din cele de mai jos:\n");
    afisare(repo);
    int cod = citeste_int("Introdu un cod din cele de mai sus:\n");
    char nume_nou[100];
    citeste_string(nume_nou, "Introdu numele nou al medicamentului:\n", sizeof(nume_nou));
    double concentratie_noua = citeste_float("Introdu noua concentraie:\n");
    int eroare = modificare_medicament(repo, cod, nume_nou, concentratie_noua);
    if (eroare)
        printf("%s", erori[eroare]);
    else
        printf("Modificarea s-a realizat cu succes!\n");
}

void stergere(lista_med* repo, char erori[][50]) {
    if (repo->lg == 0) {
        printf("Nu exista medicamente!\n");
        return;
    }
    printf("Selecteaza un medicament din cele de mai jos:\n");
    afisare(repo);
    int cod = citeste_int("Introdu un cod din cele de mai sus:\n");
    int eroare = stergere_stoc(repo, cod);
    if (eroare)
        printf("%s", erori[eroare]);
    else
        printf("Stergea s-a reliazat cu succes!\n");
}

void sortare(lista_med* repo) {
    if (repo->lg == 0) {
        printf("Nu exista medicamente!\n");
        return;
    }
    lista_med* sortat;
    int optiune = citeste_int("Criteriu de sortare:\n1 - sortare dupa cantitatea din stoc, crescator\n2 - sortare dupa cantitatea din stoc, descrescator\n3 - sortare aflfabetic dupa nume\nIntrodu o optiune:\n");
    if (optiune == 1)
        sortat = sortare_medicament(repo, sortare_crescator);
    else if (optiune == 2)
        sortat = sortare_medicament(repo, sortare_descrescator);
    else if (optiune == 3)
        sortat = sortare_medicament(repo, sortare_alfabetic);
    else {
        printf("optiune invalida\n");
        return;
    }
    afisare(sortat);
    distruge_repo(sortat);
}

void filtrare(lista_med* repo) {
    int optiune = citeste_int("Criterii de filtrare:\n1 - Stoc mai mic decat o valoare data\n2 - Medicamentele al caror nume incepe cu o anumita liera\n");
    lista_med* filtrat;
    if (optiune == 1) {
        int valoare = citeste_int("Introdu valoarea:\n");
        filtrat = filtrare_stoc(repo, valoare);
    }
    else if (optiune == 2) {
        char litera = citeste_char("Introdu litera:\n");
        filtrat = filtrare_nume(repo, litera);
    }
    else {
        printf("Optiune invalida\n");
        return;
    }
    afisare(filtrat);
    distruge_repo_partial(filtrat);
}

void ui(lista_med* repo) {
    char erori[][50] = {"", "ID-ul este invalid!\n", "Numele nu poate fi vid!\n", "Concentratia este invalid!\n", "Stocul este invalid!\n", "ID Deja existent, s-a modificat cantitatea!\n", "Lista este plina!\n", "Nu exista niciun medicament cu acest id!\n"};
    // adauga_medicament(repo, 1, "Theraflu", 12.12, 5);
    // adauga_medicament(repo, 2, "Coldrex", 2.12, 6);
    // adauga_medicament(repo, 3, "Paracetamol", 5.50, 10);
    // adauga_medicament(repo, 4, "Aspirina", 8.75, 7);
    // adauga_medicament(repo, 5, "Nurofen", 15.30, 4);
    // adauga_medicament(repo, 6, "Ibuprofen", 6.80, 12);
    // adauga_medicament(repo, 7, "Panadol", 9.99, 8);
    while (1) {
        printf("Introdu una dintre optiunile de mai jos:\n");
        printf("1 - Adaugare medicament\n2 - Modificare medicament\n3 - Stergere stoc\n4 - Vizualizare medicamente din stoc, ordonat\n5 - Filtrare medicamente\n6 - Afisare medicamente\n0 - Exit\n");
        int optiune = citeste_int("");
        if (optiune == 1)
            adaugare(repo, erori);
        else if (optiune == 2)
            modificare(repo, erori);
        else if (optiune == 3)
            stergere(repo, erori);
        else if (optiune == 4)
            sortare(repo);
        else if (optiune == 5)
            filtrare(repo);
        else if (optiune == 6) {
            if (repo->lg == 0) {
                printf("Nu exista medicamente!\n");
                continue;
            }
            afisare(repo);
        }
        else if (optiune == 0)
            break;
        else
            printf("comanda invalida\n");
    }
}