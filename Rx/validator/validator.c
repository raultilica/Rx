#include "../domain/domain.h"
#include <string.h>

int valideaza(medicament* med) {
    if (get_cod(med) < 0)
        return 1;               // cod de eroare pentru cod invalid
    if (strcmp(get_nume(med), "") == 0)
        return 2;               // cod de eroare pentru nume invalid
    if (get_concentratie(med) < 0)
        return 3;               // cod de eroare pentru concentratie invalida
    if (get_stoc(med) < 0)
        return 4;               // cod de eroare pentru stoc invalid
    return 0;                   // cod de iesire pentru nicio eroare
}
