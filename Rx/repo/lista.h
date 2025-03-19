#ifndef LISTA_H
#define LISTA_H
#include "../domain/domain.h"

typedef struct {
    medicament** list;
    int lg;
    int capacitate;
}lista_med;

lista_med* creeaza_lista();
/*
 * Functia creeaza o lista dinamica
 * return: adresa de inceput a listei
 */

void resize(lista_med* repo);
/*
 * Functia redimensioneaza lista.
 * return: repo Pointer la lista de medicamente.
 */

lista_med* copie_lista(lista_med* repo);
/*
 * Functia creeaza un deepcopy pentru lista.
 * return: un pointer spre lista noua
 */

void distruge_repo(lista_med* repo);
/*
 * Functia distruge o lista dinamica, inclusiv obiectele aflate la adresele din lista
 */

void distruge_repo_partial(lista_med* repo);
/*
 * Functia distruge o lista dinamica, fara obiectele aflate la adresele din lista
 */

#endif //LISTA_H
