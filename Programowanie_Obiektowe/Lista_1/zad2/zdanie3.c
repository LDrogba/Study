#include <stdio.h>
#include <math.h>
#include "ulamki.h"


int main()
{
    Ulamek x, y, c;
    Ulamek* z;

    x.licznik = 1;
    x.mianownik = 2;
    y.licznik = 2;
    y.mianownik = -5;

    c=y;

    printf("x: %d %d y: %d %d\n", x.licznik, x.mianownik, y.licznik, y.mianownik);

    z =Add_1(&x, &y);
    Add_2(&x, &c);
    printf("Dodawanie: %d/%d : %d/%d\n", z->licznik, z->mianownik, c.licznik, c.mianownik);
    c=y;

    z = Multiply_1(&x, &y);
    Multiply_2(&x, &c);
    printf("Mnozenie: %d/%d : %d/%d\n", z->licznik, z->mianownik, c.licznik, c.mianownik);
    c=y;

    z = Divide_1(&x, &y);
    Divide_2(&x, &c);
    printf("Dzielenie: %d/%d : %d/%d\n", z->licznik, z->mianownik, c.licznik, c.mianownik);
    c=y;

    z = Substitution_1(&x, &y);
    Substitution_2(&x, &c);
    printf("Odejmowanie: %d/%d : %d/%d\n", z->licznik, z->mianownik, c.licznik, c.mianownik);
    c=y;

}
