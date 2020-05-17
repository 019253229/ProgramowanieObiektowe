#include <iostream>
#include "tablica.h"
#include "Struktura_tablicy.h"

#define SUCCESS 0

using namespace std;

int wyswietl_tablice(Tablica arr)
{
	for(int i = 0; i < arr.rozmiarX; i++)
	{
        for(int j = 0; j < arr.rozmiarY; j++)
        {

            cout << "|" << arr.tablica[i][j] << "|";
        }

        cout << endl;
	}

	return SUCCESS;
}
