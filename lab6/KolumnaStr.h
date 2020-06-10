#pragma once
#include "Kolumna.h"
#include "Komorka.h"

class KolumnaStr : public Kolumna
{
public:
    KolumnaStr()
    {
        ustawTyp();
        ustawTypyKomorek();
    }

private:
    void ustawTyp()
    {
        typ = STRING;
    }

    void ustawTypyKomorek()
    {
        for (int i = 0; i < rozmiarKolumnaa; i++)
        {
            komorki[i].ustawTyp(typ);
        }
    }
};
