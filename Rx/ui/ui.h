#ifndef UI_H
#define UI_H
#include "../repo/lista.h"


void ui();
void afisare(lista_med* repo);
int citeste_int(char *mesaj);
float citeste_float(char* mesaj);
void citeste_string(char* str, char* mesaj, const int len);
void adaugare(lista_med* repo, char erori[][50]);
void modificare(lista_med* repo, char erori[][50]);
void stergere(lista_med* repo, char erori[][50]);
void sortare(lista_med* repo);
void filtrare(lista_med* repo);
void sterge_buffer();

#endif //UI_H
