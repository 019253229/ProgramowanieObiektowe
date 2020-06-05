#include <iostream>
#include "Klasa.h"
#include "Klasa_komorka.h"


int Tablica::zmien_rozmiar(Tablica* arr, int nowy_rozmiarX, int nowy_rozmiarY)
{
	if(nowy_rozmiarX <= 0 || nowy_rozmiarY <= 0)
	{
        return ERR_INVALID_SIZE;
	}
	Tablica nowy_arr;
	int** nowa_tablica = new int*[MAX_Y];

    for(int i = 0; i < MAX_Y; i++)
        {
        nowa_tablica[i] = new int[nowy_rozmiarX];
        }


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


int Tablica::kopiuj_zawartosc(Tablica tab1, Tablica tab2)
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



int Tablica::aktualizuj_zawartosc(Tablica arr, int indeksX, int indeksY, int nowa_wartosc)
{
    if(indeksX >= 0 && indeksX < arr.rozmiarX && indeksY >= 0 && indeksY < arr.rozmiarY)
    {
        arr.tablica[indeksX][indeksY] =  nowa_wartosc;
        return SUCCESS;
    }

    return ERR_INVALID_SIZE;
}



int Tablica::suma_kolumna(Tablica arr, int kolumna, int* sumaY)
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



int Tablica::suma_wiersz(Tablica arr, int wiersz, int* sumaX)
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




int Tablica::minimumX(Tablica arr,int wiersz, int* najmniejszaX)
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




int Tablica::minimumY(Tablica arr,int kolumna, int* najmniejszaY)
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




int Tablica::maximumX(Tablica arr,int wiersz, int* najwiekszaX)
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




int Tablica::maximumY(Tablica arr,int kolumna, int* najwiekszaY)
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




int Tablica::srednia_wiersz(Tablica arr, int wiersz, double* sredniaX, int* sumaX)
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




int Tablica::srednia_kolumna(Tablica arr, int kolumna,double* sredniaY, int* sumaY)
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



