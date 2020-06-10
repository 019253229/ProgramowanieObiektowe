#pragma once

#include "Tablica.h"
#include "Komorka.h"

class Kolumna
{

public:
    Kolumna()
    {
        rozmiarKolumnaa = 10;
        komorki = new Komorka[100];
    }

    int pobierzRozmiarKolumnaa()
    {
        return rozmiarKolumnaa;
    }

    void ustawKomorke(int indeks, Komorka komorka)
    {
        komorki[indeks] = komorka;
    }

    Komorka *pobierzKomorke(int indeks)
    {
        return &komorki[indeks];
    }

    int pobierzTyp()
    {
        return typ;
    }

    void ustawRozmiar(int nowyRozmiar)
    {
        rozmiarKolumnaa = nowyRozmiar;
    }

protected:
    Komorka *komorki;
    int rozmiarKolumnaa;
    int typ;

    virtual void ustawTyp() = 0;
    virtual void ustawTypyKomorek() = 0;
};