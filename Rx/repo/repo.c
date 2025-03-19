#include "../repo/lista.h"
#include "../repo/repo.h"

#include "../domain/domain.h"


int adaugare_repo(lista_med* repo, medicament* med) {
    for (int i = 0; i < repo->lg; i++)
        if (get_cod(repo->list[i]) == get_cod(med)) {
            set_stoc(repo->list[i], get_stoc(med));
            return 5;   // warning id deja existent
        }
    if (repo->capacitate == repo->lg)
        resize(repo);
    repo->list[repo->lg] = med;
    repo->lg++;
    return 0;   //succes
}

int modificare_repo(lista_med* repo, medicament* med) {
    for (int i = 0; i < repo->lg; i++)
        if (get_cod(repo->list[i]) == get_cod(med)) {
            set_nume(repo->list[i], get_nume(med));
            set_concentratie(repo->list[i], get_concentratie(med));
            return 0;   //succes
        }
    return 7;   //eroare id inexistent
}

int stergere_repo(lista_med* repo, int id) {
    for (int i = 0; i < repo->lg; i++) {
        if (get_cod(repo->list[i]) == id) {
            distruge_medicament(repo->list[i]);
            for (int j = i; j < repo->lg-1; j++)
                repo->list[j] = repo->list[j+1];
            repo->lg--;
            return 0;
        }
    }
    return 7;
}

lista_med* get_lista(lista_med* repo) {
    return repo;
}
