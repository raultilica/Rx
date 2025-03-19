#include "../repo/lista.h"
#include "../domain/domain.h"
#include "../repo/repo.h"
#include "../validator/validator.h"
#include "../service/service.h"

#include <string.h>


int adauga_medicament(lista_med* repo, int cod, char* nume, double concentratie, int stoc) {
    medicament* med = creeaza(cod, nume, concentratie, stoc);
    int eroare_validare = valideaza(med);
    if (eroare_validare) {
        distruge_medicament(med);
        return eroare_validare;
    }
    int warning_repo = adaugare_repo(repo, med);
    if (warning_repo) {
        distruge_medicament(med);
        return warning_repo;
    }
    return 0;
}

int modificare_medicament(lista_med* repo, int cod, char* nume, double concentratie) {
    medicament* med = creeaza(cod, nume, concentratie, 1);
    int eroare_validare = valideaza(med);
    if (eroare_validare) {
        distruge_medicament(med);
        return eroare_validare;
    }
    int warning_repo = modificare_repo(repo, med);
    if (warning_repo) {
        distruge_medicament(med);
        return warning_repo;
    }
    distruge_medicament(med);
    return 0;
}

int sortare_crescator(medicament* a, medicament* b) {
    return a->stoc > b->stoc;
}

int sortare_descrescator(medicament* a, medicament* b) {
    return a->stoc < b->stoc;
}

int sortare_alfabetic(medicament* a, medicament* b) {
    return strcmp(a->nume, b->nume) > 0;
}

lista_med* sortare_medicament(lista_med* repo, int(*compare)(medicament*, medicament*)) {
    lista_med* lista_noua = copie_lista(repo);
    for (int i = 0; i<repo->lg; i++)
        for (int j = 0; j <repo->lg-1;j++)
            if (compare(lista_noua->list[j], lista_noua->list[j+1])) {
                medicament* temp = lista_noua->list[j+1];
                lista_noua->list[j+1] = lista_noua->list[j];
                lista_noua->list[j] = temp;
            }
    return lista_noua;
}

lista_med* filtrare_stoc(lista_med* repo, int valoare) {
    lista_med* lista_noua = creeaza_lista();
    for (int i = 0; i<repo->lg; i++) {
        if (repo->list[i]->stoc < valoare) {
            lista_noua->list[lista_noua->lg++] = repo->list[i];
            if (lista_noua->lg == lista_noua->capacitate)
                resize(lista_noua);
        }
    }
    return lista_noua;
}

lista_med* filtrare_nume(lista_med* repo, char litera) {
    lista_med* lista_noua = creeaza_lista();
    for (int i = 0; i < repo->lg; i++)
        if (repo->list[i]->nume[0] == litera) {
            lista_noua->list[lista_noua->lg++] = repo->list[i];
            if (lista_noua->lg == lista_noua->capacitate)
                resize(lista_noua);
        }
    return lista_noua;
}

int stergere_stoc(lista_med* repo, int cod) {
    int warning_repo = stergere_repo(repo, cod);
    if (warning_repo)
        return warning_repo;
    return 0;
}



