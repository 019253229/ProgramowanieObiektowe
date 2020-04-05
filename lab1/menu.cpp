#include <iostream>
#include "funkcje.h"

int menu(){

int rozmiar=10;
int* tablica = new int [rozmiar];

while(true)
{
    
int wybor;
std::cout<<"Wybierz opcje:" "\n";
std::cout<<"1 Wyswietl tablice" "\n" ;
std::cout<<"2 Zmien wartosc" "\n";
std::cout<<"3 Zmien rozmiar" "\n";
std::cin >> wybor;

switch(wybor)
{
case 1:
{
wyswietl_tablice(tablica, rozmiar);
break;
}
case 2:
{
aktualizuj_zawartosc(tablica, rozmiar);
break;
}
case 3:
{
tablica = zmien_rozmiar(tablica, rozmiar);
break;
}
default:
{             
return 0; 
break;
}
}
}   
}
