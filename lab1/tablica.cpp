#include <iostream>
#include "funkcje.h"

int* zmien_rozmiar(int tablica[], int &stary_rozmiar)
{
int nowy_rozmiar;

std::cout << "Podaj nowy rozmiar (>0): ";
std::cin >> nowy_rozmiar;

if(nowy_rozmiar <= 0)
{

}

int* nowa_tablica = new int[nowy_rozmiar];

kopiuj_zawartosc(tablica, stary_rozmiar, nowa_tablica, nowy_rozmiar);

delete[] tablica;
    
stary_rozmiar = nowy_rozmiar;
return nowa_tablica;
}

void kopiuj_zawartosc(int tab1[], int rozmiar1, int tab2[], int rozmiar2)
{
for(int i = 0; i < rozmiar1; i++)
{
if(i < rozmiar2) //kopiujemy dopoki rozmiar2 na to pozwoli(moze byc mniejsza)
{
tab2[i] = tab1[i];
}
else //jesli tab2 sie skonczyla to konczymy
{
break;
}
}
}

void aktualizuj_zawartosc(int tab[], int rozmiar)
{
int indeks;
int nowa_wartosc;

std::cout << "Wybierz ktory element chcesz edytowac: (od 0 do " << rozmiar-1 << "): " << std::endl;

std::cin >> indeks;

if(indeks > rozmiar-1 || indeks < 0)
{
return;
}

std::cout << "Aktualna wartosc: " << tab[indeks] << std::endl;
std::cout << "Zmien na: ";

std::cin >> nowa_wartosc;

tab[indeks] = nowa_wartosc;

return;

}

