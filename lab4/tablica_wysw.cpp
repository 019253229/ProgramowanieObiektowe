#include <iostream>
#include "Klasa.h"

#define SUCCESS 0

using namespace std;

int Tablica::wyswietl_tablice(Tablica arr)
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
