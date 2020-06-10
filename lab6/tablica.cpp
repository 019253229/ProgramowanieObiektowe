#include <iostream>
#include "Tablica.h"
#include "Komorka.h"

int Tablica::zmien_rozmiar(Tablica *arr, int nowy_rozmiarX, int nowy_rozmiarY)
{
    if (nowy_rozmiarX <= 0 || nowy_rozmiarY <= 0)
    {
        return ERR_INVALID_SIZE;
    }

    Tablica nowy_arr(nowy_rozmiarX);
    nowy_arr.rozmiarY = nowy_rozmiarY;

    kopiuj_zawartosc(*arr, nowy_arr);

    delete[](*arr).tablica;

    arr->tablica = nowy_arr.tablica;
    arr->rozmiarX = nowy_arr.rozmiarX;
    arr->rozmiarY = nowy_arr.rozmiarY;

    return SUCCESS;
}

int Tablica::kopiuj_zawartosc(Tablica tab1, Tablica tab2)
{
    for (int i = 0; i < tab1.rozmiarX; i++)
    {
        if (i >= tab2.rozmiarX)
        {
            break;
        }

        for (int j = 0; j < tab1.rozmiarY; j++)
        {
            if (j < tab2.rozmiarY)
            {
                tab2.tablica[i].ustawKomorke(j, *(tab1.tablica[i].pobierzKomorke(j)));
            }
            else
            {
                break;
            }
        }
    }

    return SUCCESS;
}

int Tablica::aktualizuj_zawartoscINT(Tablica arr, int indeksX, int indeksY, int nowa_wartosc)
{
    if (arr.tablica[indeksX].pobierzKomorke(indeksY)->pobierzTyp() != INT)
    {
        return ERR_INVALID_SIZE;
    }

    if (indeksX >= 0 && indeksX < arr.rozmiarX && indeksY >= 0 && indeksY < arr.rozmiarY)
    {
        arr.tablica[indeksX].pobierzKomorke(indeksY)->ustawWartoscInt(nowa_wartosc);
        return SUCCESS;
    }

    return ERR_INVALID_SIZE;
}

int Tablica::aktualizuj_zawartoscSTR(Tablica arr, int indeksX, int indeksY, std::string nowa_wartosc)
{
    if (arr.tablica[indeksX].pobierzKomorke(indeksY)->pobierzTyp() != STRING)
    {
        return ERR_INVALID_SIZE;
    }

    if (indeksX >= 0 && indeksX < arr.rozmiarX && indeksY >= 0 && indeksY < arr.rozmiarY)
    {
        arr.tablica[indeksX].pobierzKomorke(indeksY)->ustawWartoscStr(nowa_wartosc);
        return SUCCESS;
    }

    return ERR_INVALID_SIZE;
}

int Tablica::suma_kolumna(Tablica arr, int kolumna, int *sumaY)
{
    if (kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        if (arr.tablica[kolumna].pobierzTyp() != INT)
            return ERR_INVALID_SIZE;

        *sumaY = 0;

        for (int i = 0; i < arr.rozmiarY; i++)
        {
            *sumaY += arr.tablica[kolumna].pobierzKomorke(i)->pobierzWartoscInt();
        }
    }
    else
        return ERR_INVALID_SIZE;

    return SUCCESS;
}

int Tablica::suma_wiersz(Tablica arr, int wiersz, int *sumaX)
{
    if (wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *sumaX = 0;

        for (int j = 0; j < arr.rozmiarX; j++)
        {
            if (arr.tablica[j].pobierzKomorke(wiersz)->pobierzTyp() != INT)
            {
                continue;
            }

            *sumaX += arr.tablica[j].pobierzKomorke(wiersz)->pobierzWartoscInt();
        }
    }
    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::minimumY(Tablica arr, int wiersz, int *najmniejszaX)
{
    if (wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *najmniejszaX = 0;

        for (int i = 0; i < arr.rozmiarX; i++)
        {
            if (arr.tablica[i].pobierzKomorke(wiersz)->pobierzTyp() != INT)
            {
                continue;
            }

            *najmniejszaX = arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt();

            if (arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt() < *najmniejszaX)
            {
                *najmniejszaX = arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt();
            }
        }
    }
    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::minimumX(Tablica arr, int kolumna, int *najmniejszaY)
{
    if (kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        if (arr.tablica[kolumna].pobierzTyp() != INT)
            return ERR_INVALID_SIZE;

        *najmniejszaY = 0;

        for (int j = 0; j < arr.rozmiarY; j++)
        {

            *najmniejszaY = arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt();

            if (arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt() < *najmniejszaY)
            {

                *najmniejszaY = arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt();
            }
        }
    }
    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::maximumX(Tablica arr, int kolumna, int *najwiekszaX)
{
    if (kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        if (arr.tablica[kolumna].pobierzTyp() != INT)
            return ERR_INVALID_SIZE;

        *najwiekszaX = 0;

        for (int j = 0; j < arr.rozmiarY; j++)
        {

            *najwiekszaX = arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt();

            if (arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt() > *najwiekszaX)
            {
                *najwiekszaX = arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt();
            }
        }
    }
    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::maximumY(Tablica arr, int wiersz, int *najwiekszaY)
{
    if (wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *najwiekszaY = 0;

        for (int i = 0; i < arr.rozmiarX; i++)
        {
            if (arr.tablica[i].pobierzKomorke(wiersz)->pobierzTyp() != INT)
            {
                continue;
            }

            *najwiekszaY = arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt();

            if (arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt() > *najwiekszaY)
            {
                *najwiekszaY = arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt();
            }
        }
    }
    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::srednia_wiersz(Tablica arr, int wiersz, double *sredniaX, int *sumaX)
{
    if (wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *sredniaX = 0;
        *sumaX = 0;
        
        for (int i = 0; i < arr.rozmiarX; i++)
        {
            if (arr.tablica[i].pobierzKomorke(wiersz)->pobierzTyp() != INT)
            {
                continue;
            }

            *sumaX += arr.tablica[i].pobierzKomorke(wiersz)->pobierzWartoscInt();
        }
        *sredniaX = ((double)*sumaX / arr.rozmiarX);
    }

    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::srednia_kolumna(Tablica arr, int kolumna, double *sredniaY, int *sumaY)
{
    if (kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        if (arr.tablica[kolumna].pobierzTyp() != INT)
            return ERR_INVALID_SIZE;

        *sredniaY = 0;
        *sumaY = 0;
        for (int j = 0; j < arr.rozmiarY; j++)
        {
            *sumaY += arr.tablica[kolumna].pobierzKomorke(j)->pobierzWartoscInt();
        }

        *sredniaY = ((double)*sumaY / arr.rozmiarY);
    }

    else
        return ERR_INVALID_SIZE;
    return SUCCESS;
}

int Tablica::zmienTyp(int typ, int zmienianaKolumna)
{
    if (zmienianaKolumna >= 0 && zmienianaKolumna < rozmiarX)
    {
        if (typ == INT && tablica[zmienianaKolumna].pobierzTyp() != INT)
        {
            KolumnaInt *nowaKolumna = new KolumnaInt();
            tablica[zmienianaKolumna] = *nowaKolumna;
        }
        else if (typ == STRING && tablica[zmienianaKolumna].pobierzTyp() != STRING)
        {
            KolumnaStr *nowaKolumna = new KolumnaStr();
            tablica[zmienianaKolumna] = *nowaKolumna;
        }
        else
        {
            return ERR_INVALID_SIZE;
        }
    }
    else
    {
        return ERR_INVALID_SIZE;
    }

    return SUCCESS;
}