#include <iostream>
#include "tablica.h"
#include "Struktura_tablicy.h"

/**
 *
 * @param[in,out] arr- tablica której rozmiar chcemy zmienić
 * @param[in] nowy_rozmiarX - nowy rozmiar X
 * @param[in] nowy_rozmiarY - nowy rozmiar Y
 * @return - kod błędu lub 0 w przypadku powodzenia
 */
int zmien_rozmiar(Tablica* arr, int nowy_rozmiarX, int nowy_rozmiarY)
{
	if(nowy_rozmiarX <= 0 || nowy_rozmiarY <= 0)
	{
        return ERR_INVALID_SIZE;
	}
	Tablica nowy_arr;
	int** nowa_tablica = new int*[MAX_Y];

    for(int i = 0; i < MAX_Y; i++)
        nowa_tablica[i] = new int[nowy_rozmiarX];

    nowy_arr.tablica = nowa_tablica;
    nowy_arr.rozmiarX = nowy_rozmiarX;
    nowy_arr.rozmiarY = nowy_rozmiarY;

	kopiuj_zawartosc(*arr, nowy_arr);

	delete[] (*arr).tablica;

    arr -> tablica = nowy_arr.tablica;
    arr -> rozmiarX = nowy_arr.rozmiarX;
    arr -> rozmiarY = nowy_arr.rozmiarY;

    return SUCCESS;
}

/**
 * Kopiujemy zawartosc z tablicy 1 do 2
 * @param[in] tab1 - tablica z której kopiowane są elementy
 * @param[in,out] tab2 - tablica do której kopiowane są elementy
 */
int kopiuj_zawartosc(Tablica tab1, Tablica tab2)
{
    for(int i = 0; i < tab1.rozmiarX; i++)
    {
        if(i >= tab2.rozmiarX)
        {
            break;
        }

        for(int j = 0; j < tab1.rozmiarY; j++)
        {
            if(j < tab2.rozmiarY)
            {
                tab2.tablica[i][j] = tab1.tablica[i][j];
            }
            else
            {
                break;
            }
        }
	}

	return SUCCESS;
}

/**
 *@param[in,out] arr - tablica w której chcemy zmienić wartosc
 *@param[in] indeksX - miejsce komorki na X
 *@param[in] indeksY - miejsce komorki na Y
 *@param[in] nowa_wartosc - wartosc na jaka zmieniamy
 */

int aktualizuj_zawartosc(Tablica arr, int indeksX, int indeksY, int nowa_wartosc)
{
    if(indeksX >= 0 && indeksX < arr.rozmiarX && indeksY >= 0 && indeksY < arr.rozmiarY)
    {
        arr.tablica[indeksX][indeksY] =  nowa_wartosc;
        return SUCCESS;
    }

    return ERR_INVALID_SIZE;
}

/**
*@param[in,out] arr - tablica w której chcemy policzyc sume w kolumnie
*@param[in] kolumna - ilosc kolumn
*@param[in,out] sumaY - suma w danej kolumnie
*/


int suma_kolumna(Tablica arr, int kolumna, int* sumaY)
{
    if(kolumna >= 0 && kolumna < arr.rozmiarY)
    {
        *sumaY=0;
        for(int i=0; i<arr.rozmiarX; i++){


            *sumaY += arr.tablica[i][kolumna];


        }

    }
    else return ERR_INVALID_SIZE;
    return SUCCESS;
}

/**
*@param[in,out] arr - tablica w której chcemy policzyc sume w kolumnie
*@param[in] wiersz - ilosc wierszy
*@param[in,out] sumaX- suma w danym wierszu
*/



int suma_wiersz(Tablica arr, int wiersz, int* sumaX)
{
    if(wiersz >= 0 && wiersz< arr.rozmiarX)
    {
        *sumaX=0;
        for(int j=0; j<arr.rozmiarY; j++)
        {
            *sumaX += arr.tablica[wiersz][j];
        }

    }
    else return ERR_INVALID_SIZE;
    return SUCCESS;
}

/**
*@param[in,out] arr - tablica w której chcemy podac najmniejsza wartosc w wierszu
*@param[in] wiersz - ilosc wierszy
*@param[in,out] najmniejszaX - najmniejsza wartosc
*/


int minimumX(Tablica arr,int wiersz, int* najmniejszaX)
{
    if(wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *najmniejszaX=0;
        for(int i=0; i<arr.rozmiarX; i++)
        {
            *najmniejszaX = arr.tablica[wiersz][i];

                if(arr.tablica[wiersz][i] < *najmniejszaX)
                {

                *najmniejszaX = arr.tablica[wiersz][i];
                }
        }
    }
    else return ERR_INVALID_SIZE;
    return SUCCESS;


}

/**
*@param[in,out] arr - tablica w której chcemy podac najmniejsza wartosc w kolumnie
*@param[in] kolumna - ilosc kolumn
*@param[in,out] najmniejszaY - najmniejsza wartosc
*/


int minimumY(Tablica arr,int kolumna, int* najmniejszaY)
{
    if(kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        *najmniejszaY=0;
        for(int j=0; j<arr.rozmiarY; j++)
        {
            *najmniejszaY = arr.tablica[j][kolumna];

                if(arr.tablica[j][kolumna] < *najmniejszaY)
                {

                *najmniejszaY = arr.tablica[j][kolumna];
                }
        }
    }
    else return ERR_INVALID_SIZE;
    return SUCCESS;


}

/**
*@param[in,out] arr - tablica w której chcemy podac najwieksza wartosc w wierszu
*@param[in] wiersz - ilosc wierszy
*@param[in,out] najwiekszaX - najwieksza wartosc
* !!!Nie wiem czemu wyswietla najmniejsza wartosc!!!
*/


int maximumX(Tablica arr,int wiersz, int* najwiekszaX)
{
    if(wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *najwiekszaX=0;
        for(int i=0; i<arr.rozmiarX; i++)
        {
            *najwiekszaX = arr.tablica[wiersz][i];

                if(arr.tablica[wiersz][i] > *najwiekszaX)
                {

                *najwiekszaX = arr.tablica[wiersz][i];
                }
        }
    }
        else return ERR_INVALID_SIZE;
        return SUCCESS;


}

/**
*@param[in,out] arr - tablica w której chcemy podac najwieksza wartosc w kolumnie
*@param[in] kolumna - ilosc kolumn
*@param[in,out] najwiekszaY - najwieksza wartosc
* !!!Nie wiem czemu wyswietla najmniejsza wartosc!!!
*/


int maximumY(Tablica arr,int kolumna, int* najwiekszaY)
{
    if(kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        *najwiekszaY=0;
        for(int j=0; j<arr.rozmiarY; j++)
        {
            *najwiekszaY = arr.tablica[j][kolumna];

                if(arr.tablica[j][kolumna] > *najwiekszaY)
                {

                *najwiekszaY = arr.tablica[j][kolumna];
                }
        }
        }
        else return ERR_INVALID_SIZE;
        return SUCCESS;


}

/**
*@param[in,out] arr - tablica w której chcemy podac srednia wartosc w wierszu
*@param[in] wiersz - ilosc wierszy
*@param[in,out] sredniaX - srednia wartosc w wierszu (suma podzielona przez ilosc)
*@param[in,out] sumaX - suma w danym wierszu
*/


int srednia_wiersz(Tablica arr, int wiersz, double* sredniaX, int* sumaX)
{
    if(wiersz >= 0 && wiersz < arr.rozmiarY)
    {
        *sredniaX=0;
        *sumaX=0;
        for(int i=0; i<arr.rozmiarX; i++){

            *sumaX += arr.tablica[wiersz][i];

        }
        *sredniaX = ((double) *sumaX / arr.rozmiarX);
    }

    else return ERR_INVALID_SIZE;
    return SUCCESS;
}

/**
*@param[in,out] arr - tablica w której chcemy podac srednia wartosc w kolumnie
*@param[in] kolumna - ilosc kolumn
*@param[in,out] sredniaY - srednia wartosc w kolumnie (suma podzielona przez ilosc)
*@param[in,out] sumaY - suma w danej kolumnie
*/


int srednia_kolumna(Tablica arr, int kolumna,double* sredniaY, int* sumaY)
{
    if(kolumna >= 0 && kolumna < arr.rozmiarX)
    {
        *sredniaY=0;
        *sumaY=0;
        for(int j=0; j<arr.rozmiarY; j++)
        {
            *sumaY += arr.tablica[j][kolumna];
        }
    *sredniaY = ((double) *sumaY / arr.rozmiarY);
    }

    else return ERR_INVALID_SIZE;
    return SUCCESS;
}



