#include <iostream>
#include "tablica.h"
#include "Struktura_tablicy.h"

using namespace std;

int menu()
{

    Tablica arr;
    arr.tablica = new int*[MAX_Y];

	arr.rozmiarX = 10;
    arr.rozmiarY = 10;



    for(int i = 0; i < MAX_Y; i++)
        arr.tablica[i] = new int[arr.rozmiarX];

	while(true)
    {

        int wybor;
        cout << endl;
        cout << "Wybierz opcje:" "\n";
        cout << "1) Wyswietl tablice" "\n" ;
        cout << "2) Zmien wartosc komorki" "\n";
        cout << "3) Zmien rozmiar tablicy" "\n";
        cout << "4) Suma wg kolumn" "\n";
        cout << "5) Suma wg wierszy" "\n";
        cout << "6) Najmniejsza wartosc w wierszach" "\n";
        cout << "7) Najmniejsza wartosc w kolumnach" "\n";
        cout << "8) Najwieksza wartosc w wierszach" "\n";
        cout << "9) Najwieksza wartosc w kolumnach" "\n";
        cout << "10) Srednia wartosc w wierszach" "\n";
        cout << "11) Srednia wartosc w kolumnach" "\n";
        cin  >>  wybor;
        cout << endl;

        switch(wybor)
        {
        case 1:
        {
            if(wyswietl_tablice(arr) != SUCCESS)
            {
                cout << "Blad! - wyswietlanie nie dziala." << endl;
            }

            break;
        }
        case 2:
        {
            int indeksX;
            int indeksY;

            int nowa_wartosc;

            cout << "Wybierz numer wiersza w ktorym chcesz edytowac element: (od 0 do " << arr.rozmiarX-1 << "): " << endl;

            cin >> indeksX;

            cout << "Wybierz numer kolumny w ktorej chcesz edytowac element: (od 0 do " << arr.rozmiarY-1 << "): " << endl;

            cin >> indeksY;

            cout << "Zmien na: ";

            cin >> nowa_wartosc;

            if(aktualizuj_zawartosc(arr, indeksX, indeksY, nowa_wartosc) != SUCCESS)
            {
                cout << "Wystapil blad! - zmieniles wartosc komorki ktorej nie ma." << endl;
            }


            break;

        }
        case 3:
        {
            int nowy_rozmiarX;
            int nowy_rozmiarY;

            cout << "Podaj nowy rozmiarX (>0): ";
            cin >> nowy_rozmiarX;

            cout << "Podaj nowy rozmiarY (>0): ";
            cin >> nowy_rozmiarY;

            if(zmien_rozmiar(&arr, nowy_rozmiarX, nowy_rozmiarY) != SUCCESS)
            {
                cout << "Wysapil blad!" << endl;
            }
            break;
        }
        case 4:
        {

            int sumaY, kolumna;

            cout << "Wybierz kolumne ktora chcesz zsumowac: (od 0 do " << arr.rozmiarY-1 << "): " << endl;

            cin >> kolumna;

            if(suma_kolumna( arr, kolumna, &sumaY) == SUCCESS)
            {
                cout << "Suma " << kolumna << "-tej kolumny to " << sumaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 5:
        {


            int sumaX, wiersz;

            cout << "Wybierz wiersz ktory chcesz zsumowac: (od 0 do " << arr.rozmiarX-1 << "): " << endl;

            cin >> wiersz;

            if(suma_wiersz( arr, wiersz, &sumaX) == SUCCESS)
            {
                cout << "Suma " << wiersz << "-tego wiersza to " << sumaX << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 6:
        {

            int najmniejszaX, wiersz;

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie najmniejsza wartosc: (od 0 do " << arr.rozmiarY-1 << "): " << endl;

            cin >> wiersz;

            if(minimumX( arr, wiersz, &najmniejszaX) == SUCCESS)
            {
                cout << "Najmniejsza wartosc  " << wiersz << "-tego wiersza to " << najmniejszaX << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 7:
        {

            int najmniejszaY, kolumna;



            cout << "Wybierz kolumne w ktorej ma wyswietlic sie najmniejsza wartosc: (od 0 do " << arr.rozmiarX-1 << "): " << endl;

            cin >> kolumna;

            if(minimumY(arr, kolumna, &najmniejszaY) == SUCCESS)
            {
                cout << "Najmniejsza wartosc  " << kolumna << "-tej kolumny to " << najmniejszaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 8:
         {

            int najwiekszaX, wiersz;

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie najwieksza wartosc: (od 0 do " << arr.rozmiarY-1 << "): " << endl;

            cin >> wiersz;

            if(maximumX( arr, wiersz, &najwiekszaX) == SUCCESS)
            {
                cout << "Najwieksza wartosc  " << wiersz << "-tego wiersza to " << najwiekszaX << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 9:
        {

            int najwiekszaY, kolumna;

            cout << "Wybierz kolumne w ktorej ma wyswietlic sie najwieksza wartosc: (od 0 do " << arr.rozmiarX-1 << "): " << endl;

            cin >> kolumna;

            if(maximumY( arr, kolumna, &najwiekszaY) == SUCCESS)
            {
                cout << "Najwieksza wartosc  " << kolumna << "-tej kolumny to " << najwiekszaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
        case 10:
        {

            double sredniaX;
            int wiersz, sumaX;

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie srednia wartosc: (od 0 do " << arr.rozmiarY-1 << "): " << endl;

            cin >> wiersz;

            if(srednia_wiersz( arr, wiersz, &sredniaX, &sumaX) == SUCCESS)
            {
                cout << "Srednia wartosc  " << wiersz << "-tego wiersza to " << sredniaX << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }
         case 11:
        {

            double sredniaY;
            int kolumna, sumaY;

            cout << "Wybierz kolumne w ktorej ma wyswietlic sie srednia wartosc: (od 0 do " << arr.rozmiarX-1 << "): " << endl;

            cin >> kolumna;

            if(srednia_kolumna(arr, kolumna, &sredniaY, &sumaY) == SUCCESS)
            {
                cout << "Srednia wartosc  " << kolumna << "-tej kolumny to " << sredniaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
        break;
        }


        }
    }
}

