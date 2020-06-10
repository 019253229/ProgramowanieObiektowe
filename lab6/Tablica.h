#pragma once
#include "Kolumna.h"
#include "KolumnaInt.h"
#include "KolumnaStr.h"

#define MAX_Y 100
#define SUCCESS 0
#define ERR_INVALID_SIZE 1

class Tablica
{
private:
    Kolumna *tablica;
    int rozmiarX;
    int rozmiarY;

public:
    Tablica()
    {
        rozmiarX = 10;
        rozmiarY = 10;

        tablica = new KolumnaInt[rozmiarX];
    }

    Tablica(int nrozmiarX)
    {
        rozmiarX = nrozmiarX;
        rozmiarY = 10;

        tablica = new KolumnaInt[rozmiarX];
    }

    int pobierzRozmiarX()
    {
        return rozmiarX;
    }

    int pobierzRozmiarY()
    {
        return rozmiarY;
    }

    int pobierzTypKomorki(int x, int y)
    {
        return tablica[x].pobierzKomorke(y)->pobierzTyp();
    }
    /**
 * Kopiujemy zawartosc z tablicy 1 do 2
 * @param[in] tab1 - tablica z której kopiowane są elementy
 * @param[in,out] tab2 - tablica do której kopiowane są elementy
 */
    int kopiuj_zawartosc(Tablica tab1, Tablica tab2);

    /**
 * @param[in,out] arr- tablica której rozmiar chcemy zmienić
 * @param[in] nowy_rozmiarX - nowy rozmiar X
 * @param[in] nowy_rozmiarY - nowy rozmiar Y
 */
    int zmien_rozmiar(Tablica *arr, int nowy_rozmiarX, int nowy_rozmiarY);

    int wyswietl_tablice(Tablica arr);
    int zmienTyp(int typ, int zmienianyKolumna);

    /**
 *@param[in,out] arr - tablica w której chcemy zmienić wartosc
 *@param[in] indeksX - miejsce komorki na X
 *@param[in] indeksY - miejsce komorki na Y
 *@param[in] nowa_wartosc - wartosc na jaka zmieniamy
 */
    int aktualizuj_zawartoscINT(Tablica arr, int indeksX, int indeksY, int nowa_wartosc);
    int aktualizuj_zawartoscSTR(Tablica arr, int indeksX, int indeksY, std::string nowa_wartosc);

    /**
*@param[in,out] arr - tablica w której chcemy policzyc sume w kolumnie
*@param[in] kolumna - ilosc kolumn
*@param[in,out] sumaY - suma w danej kolumnie
*/
    int suma_kolumna(Tablica arr, int kolumna, int *sumaY);

    /**
*@param[in,out] arr - tablica w której chcemy policzyc sume w kolumnie
*@param[in] wiersz - nr wiersza
*@param[in,out] sumaX- suma w danym wierszu
*/
    int suma_wiersz(Tablica arr, int wiersz, int *sumaX);

    /**
*@param[in,out] arr - tablica w której chcemy podac najmniejsza wartosc w wierszu
*@param[in] wiersz - nr wiersza
*@param[in,out] najmniejszaX - najmniejsza wartosc
*/
    int minimumX(Tablica arr, int wiersz, int *najmniejszaX);

    /**
*@param[in,out] arr - tablica w której chcemy podac najmniejsza wartosc w kolumnie
*@param[in] kolumna - nr kolumny
*@param[in,out] najmniejszaY - najmniejsza wartosc
*/
    int minimumY(Tablica arr, int kolumna, int *najmniejszaY);

    /**
*@param[in,out] arr - tablica w której chcemy podac najwieksza wartosc w wierszu
*@param[in] wiersz - nr wiersza
*@param[in,out] najwiekszaX - najwieksza wartosc
* !!!Nie wiem czemu wyswietla najmniejsza wartosc!!!
*/
    int maximumX(Tablica arr, int wiersz, int *najwiekszaX);

    /**
*@param[in,out] arr - tablica w której chcemy podac najwieksza wartosc w kolumnie
*@param[in] kolumna - nr kolumn
*@param[in,out] najwiekszaY - najwieksza wartosc
* !!!Nie wiem czemu wyswietla najmniejsza wartosc!!!
*/
    int maximumY(Tablica arr, int kolumna, int *najwiekszaY);

    /**
*@param[in,out] arr - tablica w której chcemy podac srednia wartosc w wiarszu
*@param[in] wiersz - nr wiersza
*@param[in,out] sredniaX - srednia wartosc w wierszu (suma podzielona przez ilosc)
*@param[in,out] sumaX - suma w danym wierszu
*/
    int srednia_wiersz(Tablica arr, int wiersz, double *sredniaX, int *sumaX);

    /**
*@param[in,out] arr - tablica w której chcemy podac srednia wartosc w kolumnie
*@param[in] kolumna - nr kolumn
*@param[in,out] sredniaY - srednia wartosc w kolumnie (suma podzielona przez ilosc)
*@param[in,out] sumaY - suma w danej kolumnie
*/
    int srednia_kolumna(Tablica arr, int kolumna, double *sredniaY, int *sumaY);
};
