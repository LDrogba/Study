#include <iostream>
#include <conio.h>
#include "Stos.hpp"
#include "main_funcions.hpp"

using namespace std;
int main()
{
    char klawisz = -1;
    Stos stos(ROZMIAR_STOSU);
    cout << "Witaj" << endl;
    cout << "Stos jest pusty. Aby dodac element do stosu wcisnij 'd'" << endl;

    while(klawisz != 'd')
        klawisz = getch();

    Dodaj(stos);
    int t = 1;
    while(t){
        klawisz = -1;
        cout << "D - dodaj kolejne slowo" << endl << "S - sprawdz ostatnie slowo" << endl
             << "I - sprawdz ilosc elementow" << endl << "M - sprawdz maksymalna ilosc elementow " << endl
             << "W - wypisz cala zawartosc stosu" << endl << "U - usun ostatnie slowo ze stosu" << endl
             << "ESC - zakoncz" << endl << "------------------" << endl;

        while(klawisz != 'd' && klawisz != 's' && klawisz!= 'i' && klawisz!= 'm' && klawisz!= 'w' && klawisz!= 'u' && klawisz !=27)
            klawisz = getch();
        switch(klawisz)
        {
            case 'd':
                Dodaj(stos);
                break;
            case 's':
                Sprawdz(stos);
                break;
            case 'i':
                Ilosc(stos);
                break;
            case 'm':
                Maks();
                break;
            case 'w':
                Wypisz(stos);
                break;
            case 'u':
                Usun(stos);
                break;
            case 27:
                t = 0;
                break;
            default:
                break;
        }

    }
    return 0;
}
