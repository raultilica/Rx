#include "ui/ui.h"
#include "teste/teste.h"
#include "repo/lista.h"
#include "repo/repo.h"

int main() {
    ruleaza_teste();
    lista_med* repo = creeaza_lista();
    ui(repo);
    distruge_repo(repo);
    return 0;
}
