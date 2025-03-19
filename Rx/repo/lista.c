#include "../repo/lista.h"
#include <stdlib.h>
#include "../domain/domain.h"

lista_med* creeaza_lista() {
    lista_med* repo = malloc(sizeof(lista_med));
    repo->lg = 0;
    repo->capacitate = 1;
    repo->list = malloc(sizeof(medicament*) * repo->capacitate);
    return repo;
}

void resize(lista_med* repo) {
    medicament** temp = malloc(sizeof(medicament*) * (repo->capacitate * 2));
    for (int i = 0; i < repo->lg; i++)
        temp[i] = repo->list[i];
    free(repo->list);
    repo->list = temp;
    repo->capacitate = repo->capacitate * 2;
}

lista_med* copie_lista(lista_med* repo) {
    lista_med* lista_noua = creeaza_lista();
    for (int i = 0; i < repo->lg; i++) {
        medicament* elem_vechi = repo->list[i];
        medicament* med_temp = creeaza(elem_vechi->cod, elem_vechi->nume, elem_vechi->concentratie, elem_vechi->stoc);
        if (lista_noua->lg == i)
            resize(lista_noua);
        lista_noua->list[i] = med_temp;
        lista_noua->lg++;
    }
    return lista_noua;
}

void distruge_repo(lista_med* repo) {
    for (int i = 0; i < repo->lg; i++)
        distruge_medicament(repo->list[i]);
    repo->lg = 0;
    free(repo->list);
    free(repo);
}

void distruge_repo_partial(lista_med* repo) {
    free(repo -> list);
    free(repo);
}