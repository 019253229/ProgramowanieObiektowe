#pragma once
#include <string>

#define STRING 0
#define INT 1

class Komorka
{
private:
    int danaInt = 0;
    std::string danaStr = " ";
    int typ;

public:
    Komorka()
    {
        ustawTyp(INT);
    }

    Komorka(int typ)
    {
        ustawTyp(typ);
    }

    void ustawTyp(int nowyTyp)
    {
        typ = nowyTyp;
    }

    int pobierzTyp()
    {
        return typ;
    }

    int pobierzWartoscInt()
    {
        return danaInt;
    }

    void ustawWartoscInt(int nowaWartoscInt)
    {
        danaInt = nowaWartoscInt;
    }

    std::string pobierzWartoscStr()
    {
        return danaStr;
    }

    void ustawWartoscStr(std::string nowaWartoscStr)
    {
        danaStr = nowaWartoscStr;
    }
};
