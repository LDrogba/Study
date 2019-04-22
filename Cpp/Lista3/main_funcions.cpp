#include "main_funcions.hpp"

void Dodaj(Stos &S)
{
    std::string slowo;
    std::cout << "Podaj slowo: ";
    std::cin >> slowo;
    S.wloz(slowo);
    std::cout << "------------------" << std::endl;
}

void Sprawdz(Stos &S)
{
    std::cout << S.sprawdz() << std::endl << "------------------" << std::endl;
}

void Ilosc(Stos &S)
{
   std::cout << S.rozmiar() << std::endl << "------------------" << std::endl;
}

void Maks()
{
    std::cout << ROZMIAR_STOSU << std::endl << "------------------" << std::endl;
}

void Wypisz(Stos &S)
{
    for( int i=0 ; i<S.rozmiar(); i++)
        std::cout<< S.operator[](i) << std::endl;
    std::cout << "------------------" << std::endl;
}

void Usun(Stos &S)
{
    std::cout << "usunieto: " << S.sciagnij() << std::endl << "------------------" << std::endl;
}

