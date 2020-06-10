#include <iostream>
#include "Tablica.h"
#include "Komorka.h"

#define SUCCESS 0

using namespace std;

int Tablica::wyswietl_tablice(Tablica arr)
{
    for (int i = 0; i < arr.rozmiarX; i++)
    {
        if (arr.tablica[i].pobierzTyp() == INT)
            cout << " I ";
        else if (arr.tablica[i].pobierzTyp() == STRING)
            cout << " S ";
    }

    cout << endl;

    for (int j = 0; j < arr.rozmiarY; j++)
    {
        for (int i = 0; i < arr.rozmiarX; i++)
        {
            cout << "|";
            if (arr.tablica[i].pobierzKomorke(j)->pobierzTyp() == INT)
                cout << arr.tablica[i].pobierzKomorke(j)->pobierzWartoscInt();
            else
                cout << arr.tablica[i].pobierzKomorke(j)->pobierzWartoscStr();

            cout << "|";
        }

        cout << endl;
    }

    return SUCCESS;
}
