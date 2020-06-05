#pragma once

class Komorka_String : public Komorka
{
private:
    std::string wartosc;
    
public:
    std::string pobierzWartosc();
    void ustawWartosc(std::string nowaWartosc);
        
        
};
