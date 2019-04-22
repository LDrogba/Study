#include <iostream>
#include "Macierz.hpp"
using namespace Obliczenia;

int main()
{
    Macierz m1(4);
    Macierz m2(2,5);
    Macierz m3(5,2);
    Macierz m4(2,5);
    Macierz m5(0,0);
    int z = -3;

    for(int i=0; i<m2.a; i++)
        for(int j=0; j<m2.b; j++){
            m2.macierz[i][j] = z;
            z++;
        }


    std::cout << "macierz 1: " << std::endl << m1
         << "macierz 2: " << std::endl << m2;

    m4 += m2+m2;
    std::cout << "macierz 1 pomnozona razy 4: " << std::endl << m4;

    ~m4;
    std::cout << "transpozycja macierzy 1 pomnozonej razy 4: " << std::endl << m4;
    m1.Zmien_kolumne(2, 1);
    std::cout << "zamiana kolumny 1 z 2 w macierzy 1" << std::endl<< m1;
    m1.Zmien_wiersz(0, 1);
    std::cout << "zamiana wierszu 0 z 1 w macierzy 1" << std::endl << m1;
    m1.Dodaj_kolumna(0,1,2);
    std::cout << "dodaj do kolumny 0 kolumne 1 pomnozona razy 2" << std::endl << m1;
    std::cout << "podaj wymiary macierzy a nastepnie jej elementy" << std::endl;

    std::cin >> m5;
    std::cout << m5;

    m3 = m5.Usun_wiersz(2);
    std::cout << m3;
    m3 = m5.Usun_kolumne(2);
    std::cout << m3;
    return 0;
}
