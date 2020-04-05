#include <iostream>

void wyswietl_tablice(int tablica[], int rozmiar)
{
for(int i = 0; i < rozmiar; i++)
{
std::cout << "tablica[" << i << "] = " << tablica[i] << std::endl;
}
}
