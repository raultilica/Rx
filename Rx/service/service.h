#ifndef SERVICE_H
#define SERVICE_H
#include "../repo/lista.h"
/*
typedef struct {
    lista_med* repo;
}service;

service* creeaza_service(lista_med* repo);
*/

int adauga_medicament(lista_med* repo, int cod, char* nume, double concentratie, int stoc);
/*
 * Functia adauga un medicament in repo-ul repo
 * Intrare:
 *    - repo - pointer catre o structura lista_med
 *    - cod - int, codul medicamentului
 *    - nume - pointer la char, numele medicamentului
 *    - concentratie - double, concentratiea medicamentului
 *    - stoc - int, stocul med9camentului
 * Return:
 *    - returneaza 0 daca adaugarea s-a realizat cu succes
 *    - returneaza [1-4] daca a avut loc eroare de validare
 *    - returneaza [5-6] daca a avut loc eroare de repo (repo plin / id deja existent)
 */

int modificare_medicament(lista_med* repo, int cod, char* nume, double concentratie);
/*
* Functia modifica un medicament existent in repository pe baza codului.
* Intrare:
*  - repo: pointer catre o structura lista_med
*  - cod: codul medicamentului de modificat
*  - nume: pointer, noul nume al medicamentului.
*  - concentratie: double, noua concentratie a medicamentului.
* Return:
*  - returneaza 0 daca modificarea a avut succes.
*  - returneaza [0-4] - daca apare vreo eroare de validare,
*                   7 - nu exista medicament cu acest id
*/

int stergere_stoc(lista_med*, int cod);
/*
 * Functia sterge un medicament.
 * Intrare:
 *  - repo: pointer catre o structura lista_med.
 *  - med: id medicamentului pe care dorim sa-l stergem
 * Return:
 *  - returneaza 0 daca stergerea a avut succes.
 *  - returneaza 7 daca id-ul medicamentului nu a fost gasit in repo;
 */

int sortare_crescator(medicament* a, medicament* b);
/*
 * Functia compara stocurile a doua medicamente
 * Intrare:
 *   - a, b- pointer la un medicament
 * return: 1 - daca stocul primului medicament este mai mare decat celui de-al doilea
 *         0 - in caz contrar
 */

int sortare_descrescator(medicament* a, medicament* b);
/*
 * Functia compara stocurile a doua medicamente
 * Intrare:
 *   - a, b- pointer la un medicament
 * return: 1 - daca stocul primului medicament este mai mic decat celui de-al doilea
 *         0 - in caz contrar
 */

int sortare_alfabetic(medicament* a, medicament* b);
/*
 * Functia compara numele a doua medicamente
 * Intrare:
 *   - a, b- pointer la un medicament
 * return: 1 - daca prima litera diferita din cele 2 cuvinte este mai mare dpdv ascii pentru primul medicament
 *         0 - in caz contrar
 */

lista_med* sortare_medicament(lista_med* repo, int(*compare)(medicament*, medicament*));
/*
 * Functia sorteaza o lista de medicamente in functie de o functie de sortare definita anterior
 * Intrare:
 *   - repo - pointer la o lista_med
 *   - compare - functie
 * return: o lista noua cu medicamentele sortate corespunzator
 */

lista_med* filtrare_stoc(lista_med* repo, int valoare);
/*
 * Functia filtreaza o lista in functie de stoc
 * Intrare:
 *   - repo - pointer la o lista_med
 *   - valoare - int
 * return: o lista noua cu medicamente filtrate
 */

lista_med* filtrare_nume(lista_med* repo, char litera);
/*
 * Functia filtreaza o lista in functie de nume
 * Intrare:
 *   - repo - pointer la o lista_med
 *   - litera - char
 * return: o lista noua cu medicamente filtrate
 */


#endif //SERVICE_H
