#include <iostream>
#include "Tablica.h"

using namespace std;

int menu()
{

    Tablica arr;

    while (true)
    {

        int wybor;
        cout << endl;
        cout << "Wybierz opcje:"
                "\n";
        cout << "1) Wyswietl tablice"
                "\n";
        cout << "2) Zmien wartosc komorki"
                "\n";
        cout << "3) Zmien rozmiar tablicy"
                "\n";
        cout << "4) Suma wg kolumn"
                "\n";
        cout << "5) Suma wg wierszy"
                "\n";
        cout << "6) Najmniejsza wartosc w wierszach"
                "\n";
        cout << "7) Najmniejsza wartosc w kolumnach"
                "\n";
        cout << "8) Najwieksza wartosc w wierszach"
                "\n";
        cout << "9) Najwieksza wartosc w kolumnach"
                "\n";
        cout << "10) Srednia wartosc w wierszach"
                "\n";
        cout << "11) Srednia wartosc w kolumnach"
                "\n";
        cout << "12) Zmien typ kolumny"
                "\n";
        cin >> wybor;
        cout << endl;

        switch (wybor)
        {
        case 1:
        {
            if (arr.wyswietl_tablice(arr) != SUCCESS)
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

            cout << "Wybierz numer kolumny w ktorej chcesz edytowac element: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;

            cin >> indeksX;

            cout << "Wybierz numer wiersza w ktorym chcesz edytowac element: (od 0 do " << arr.pobierzRozmiarY() - 1 << "): " << endl;

            cin >> indeksY;

            if (arr.pobierzTypKomorki(indeksX, indeksY) == INT)
            {

                int nowa_wartosc;
                cout << "Zmien na (int): ";

                cin >> nowa_wartosc;

                if (arr.aktualizuj_zawartoscINT(arr, indeksX, indeksY, nowa_wartosc) != SUCCESS)
                {
                    cout << "Wystapil blad! - zmieniles wartosc komorki ktorej nie ma." << endl;
                }
            }
            else if (arr.pobierzTypKomorki(indeksX, indeksY) == STRING)
            {
                std::string nowa_wartosc;
                cout << "Zmien na (string): ";

                cin >> nowa_wartosc;

                if (arr.aktualizuj_zawartoscSTR(arr, indeksX, indeksY, nowa_wartosc) != SUCCESS)
                {
                    cout << "Wystapil blad! - zmieniles wartosc komorki ktorej nie ma." << endl;
                }
            }

            break;
        }
        case 3:
        {
            int nowy_rozmiarX;
            int nowy_rozmiarY;

            cout << "Podaj nowy rozmiarX (>0): ";
            cin >> nowy_rozmiarX;

            cout << "Podaj nowy rozmiarY(>0): ";
            cin >> nowy_rozmiarY;

            if (arr.zmien_rozmiar(&arr, nowy_rozmiarX, nowy_rozmiarY) != SUCCESS)
            {
                cout << "Wysapil blad!" << endl;
            }
            break;
        }
        case 4:
        {

            int sumaY, kolumna;

            cout << "Wybierz kolumne ktora chcesz zsumowac: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;

            cin >> kolumna;

            if (arr.suma_kolumna(arr, kolumna, &sumaY) == SUCCESS)
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

            cout << "Wybierz wiersz ktory chcesz zsumowac: (od 0 do " << arr.pobierzRozmiarY() - 1 << "): " << endl;

            cin >> wiersz;

            if (arr.suma_wiersz(arr, wiersz, &sumaX) == SUCCESS)
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

            int najmniejszaY, wiersz;

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie najmniejsza wartosc: (od 0 do " << arr.pobierzRozmiarY() - 1 << "): " << endl;

            cin >> wiersz;

            if (arr.minimumY(arr, wiersz, &najmniejszaY) == SUCCESS)
            {
                cout << "Najmniejsza wartosc  " << wiersz << "-tego wiersza to " << najmniejszaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
            break;
        }
        case 7:
        {

            int najmniejszaX, kolumna;

            cout << "Wybierz kolumne w ktorej ma wyswietlic sie najmniejsza wartosc: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;

            cin >> kolumna;

            if (arr.minimumX(arr, kolumna, &najmniejszaX) == SUCCESS)
            {
                cout << "Najmniejsza wartosc  " << kolumna << "-tej kolumny to " << najmniejszaX << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
            break;
        }
        case 8:
        {

            int najwiekszaY, wiersz;

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie najwieksza wartosc: (od 0 do " << arr.pobierzRozmiarY() - 1 << "): " << endl;

            cin >> wiersz;

            if (arr.maximumY(arr, wiersz, &najwiekszaY) == SUCCESS)
            {
                cout << "Najwieksza wartosc  " << wiersz << "-tego wiersza to " << najwiekszaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
            break;
        }
        case 9:
        {

            int najwiekszaX, kolumna;

            cout << "Wybierz kolumne w ktorej ma wyswietlic sie najwieksza wartosc: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;

            cin >> kolumna;

            if (arr.maximumX(arr, kolumna, &najwiekszaX) == SUCCESS)
            {
                cout << "Najwieksza wartosc  " << kolumna << "-tej kolumny to " << najwiekszaX << endl;
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

            cout << "Wybierz wiersz w ktorym ma wyswietlic sie srednia wartosc: (od 0 do " << arr.pobierzRozmiarY() - 1 << "): " << endl;

            cin >> wiersz;

            if (arr.srednia_wiersz(arr, wiersz, &sredniaX, &sumaX) == SUCCESS)
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

            cout << "Wybierz kolumne w ktorej ma wyswietlic sie srednia wartosc: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;

            cin >> kolumna;

            if (arr.srednia_kolumna(arr, kolumna, &sredniaY, &sumaY) == SUCCESS)
            {
                cout << "Srednia wartosc  " << kolumna << "-tej kolumny to " << sredniaY << endl;
            }
            else
            {
                cout << "Wystapil blad!" << endl;
            }
            break;
        }

        case 12:
        {
            int typ;
            int zmienianaKolumna;
            cout << "Wybierz typ: (0 -> STRING / 1 -> INT)";
            cin >> typ;
            cout << "Wybierz kolumne ktorej typ chcesz zmienić: (od 0 do " << arr.pobierzRozmiarX() - 1 << "): " << endl;
            cin >> zmienianaKolumna;

            if (arr.zmienTyp(typ, zmienianaKolumna) == SUCCESS)
            {
                cout << "Zmieniono typ!" << endl;
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
