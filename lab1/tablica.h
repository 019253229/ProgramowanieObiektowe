#pragma once
#include "Struktura_tablicy.h"
#define SUCCESS 0
#define ERR_INVALID_SIZE 20
#define MAX_Y 100

int kopiuj_zawartosc(Tablica tab1, Tablica tab2);
int zmien_rozmiar(Tablica* arr, int nowy_rozmiarX, int nowy_rozmiarY);
int wyswietl_tablice(Tablica arr);
int aktualizuj_zawartosc(Tablica arr, int indeksX, int indeksY, int nowa_wartosc);
int suma_kolumna(Tablica arr, int kolumna, int* sumaY);
int suma_wiersz(Tablica arr, int wiersz, int* sumaX);
int minimumX(Tablica arr,int wiersz, int* najmniejszaX);
int minimumY(Tablica arr,int kolumna, int* najmniejszaY);
int maximumX(Tablica arr,int wiersz, int* najwiekszaX);
int maximumY(Tablica arr,int kolumna, int* najwiekszaY);
int srednia_wiersz(Tablica arr, int wiersz, double* sredniaX, int* sumaX);
int srednia_kolumna(Tablica arr, int kolumna, double* sredniaY, int* sumaY);
