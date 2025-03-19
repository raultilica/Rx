#ifndef REPO_H
#define REPO_H

int adaugare_repo(lista_med* repo, medicament* med);
/*
 * Functia adauga un medicament med in repository
 * repo - pointer catre o structura lista_med
 * med - medicament de adaugat
 * return: 0 - daca adaugarea s-a realizat cu succes, 5 in caz contrar
 */

int modificare_repo(lista_med* repo, medicament* med);
/*
 * Functia modifica un medicament existent in repository.
 * Intrare:
 *  - repo: pointer catre o structura lista_med.
 *  - med: medicamentul cu noile valori pentru modificare.
 * Return:
 *  - returneaza 0 daca modificarea a avut succes.
 *  - returneaza 7 daca medicamentul nu a fost gasit in repo;
 */

int stergere_repo(lista_med* repo, int id);
/*
 * Functia sterge un medicament existent in repository.
 * Intrare:
 *  - repo: pointer catre o structura lista_med.
 *  - med: id medicamentului pe care dorim sa-l stergem
 * Return:
 *  - returneaza 0 daca stergerea a avut succes.
 *  - returneaza 7 daca id-ul medicamentului nu a fost gasit in repo;
 */


lista_med* get_lista(lista_med* repo);
/*
 * Functia obtine adresa structurii repo
 * repo - pointer catre o structura lista_med
 */

#endif //REPO_H
