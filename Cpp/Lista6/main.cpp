#include <iostream>

#include "Wyrazenie.hpp"
#include "Operandy.hpp"
#include "Operatory.hpp"
using namespace std;

int main()
{
    Wyrazenie *t1 = new Op_odejmij(
        new Pi(),
        new Op_dodaj(
            new Liczba(2),
            new Op_mnoz(new Zmienna("x"),new Liczba(7))
                    )
            );
    Wyrazenie *t2 = new Op_dziel(
                         new Op_dodaj(
                            new Liczba(3),
                            new Liczba(5)),
                        new Op_dodaj(
                            new Liczba(2),
                            new Op_mnoz(
                                new Zmienna("x"),
                                new Liczba(7))));

    Wyrazenie *t3 = new Op_odejmij(
                        new Op_dodaj(
                            new Liczba(2),
                            new Op_mnoz(
                                new Zmienna("x"),
                                new Liczba(7))),
                        new Op_dodaj(
                            new Op_mnoz(
                                new Zmienna("y"),
                                new Liczba(3)),
                            new Liczba(5)));

    Wyrazenie *t4 = new Op_dziel(
                        new Op_cos(
                            new Op_mnoz(
                                new Op_dodaj(
                                    new Zmienna("x"),
                                    new Liczba(1)),
                                new Zmienna("x"))),
                        new Op_potega(
                            new e(),
                            new Op_potega(
                                new Zmienna("x"),
                                new Liczba(2))));

    cout << "t1: " << t1->Opis() << endl;
    cout << "t2: " << t2->Opis() << endl;
    cout << "t3: " << t3->Opis() << endl;
    cout << "t4: " << t4->Opis() << endl << "----------------" << endl;

    for(double i = 0; i<=1.01; i+=0.01){
        Zmienna::Set("x", i);
        cout << " dla x = " << i << ":" << endl << endl;
        cout << " t1 = " << t1->Oblicz() << endl;
        cout << " t2 = " << t2->Oblicz() << endl;
        cout << " t3 = " << t3->Oblicz() << endl;
        cout << " t4 = " << t4->Oblicz() << endl;
        cout << "===========================" << endl;
    }

    return 0;
}
