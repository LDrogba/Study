#include "ulamki.h"
#include <stdlib.h>
#include <stdio.h>

void Change_sign(Ulamek* x){
    x->licznik *= -1;
    x->mianownik *= -1;
}

Ulamek* Add_1(Ulamek* x, Ulamek* y)
{
    Ulamek* new_ulamek = (Ulamek*)malloc(sizeof(Ulamek));
    new_ulamek->licznik = (x->licznik * y->mianownik) + (y->licznik * x->mianownik);
    new_ulamek->mianownik = x->mianownik * y->mianownik;
    if(new_ulamek->mianownik < 0)
        Change_sign(new_ulamek);

    Skroc(new_ulamek);

    return new_ulamek;
}

void Add_2(Ulamek* x, Ulamek* y)
{
    y->licznik = (y->licznik * x->mianownik) + (x->licznik * y->mianownik);
    y->mianownik *= x->mianownik;

    if(y->mianownik < 0)
        Change_sign(y);

    Skroc(y);
}

Ulamek* Multiply_1(Ulamek* x, Ulamek* y)
{
    Ulamek* new_ulamek = (Ulamek*)malloc(sizeof(Ulamek));
    new_ulamek->licznik = (x->licznik * y->licznik);
    new_ulamek->mianownik = (x->mianownik * y->mianownik);

    if(new_ulamek->mianownik < 0)
        Change_sign(new_ulamek);

    Skroc(new_ulamek);

    return new_ulamek;
}

void Multiply_2(Ulamek* x, Ulamek* y)
{
    y->licznik *= x->licznik;
    y->mianownik *= x->mianownik;

    if(y->mianownik < 0)
        Change_sign(y);

    Skroc(y);
}

Ulamek* Divide_1(Ulamek* x, Ulamek* y)
{
    Ulamek* new_ulamek = (Ulamek*)malloc(sizeof(Ulamek));
    new_ulamek->licznik = x->licznik * y->mianownik;
    new_ulamek->mianownik = x->mianownik * y->licznik;

    if(new_ulamek->mianownik < 0)
        Change_sign(new_ulamek);

    Skroc(new_ulamek);
    return new_ulamek;
}

void Divide_2(Ulamek* x, Ulamek* y)
{
    int pom = y->licznik;
    y->licznik = x->licznik * y->mianownik;
    y->mianownik = x->mianownik * pom;

    if(y->mianownik < 0)
        Change_sign(y);

    Skroc(y);
}

Ulamek* Substitution_1(Ulamek* x, Ulamek *y)
{
    Ulamek* new_ulamek = (Ulamek*)malloc(sizeof(Ulamek));
    new_ulamek->licznik = (x->licznik * y->mianownik) - (y->licznik * x->mianownik);
    new_ulamek->mianownik = x->mianownik * y->mianownik;

    if(new_ulamek->mianownik < 0)
        Change_sign(new_ulamek);

    Skroc(new_ulamek);

    return new_ulamek;
}

void Substitution_2(Ulamek* x, Ulamek* y)
{
    y->licznik = (x->licznik * y->mianownik) - (y->licznik * x->mianownik);
    y->mianownik *= x->mianownik;
    Skroc(y);
}

int NWD(int a, int b)
{
    int sign = 1;
    if( a < 0 ){
        sign *= -1;
        a *= -1;
    }
    if( b < 0){
        sign *= -1;
        b *= -1;
    }

    while(a!=b){
       if(a>b)
           a-=b;
       else
           b-=a;
    }
    return a*sign;
}

void Skroc(Ulamek* a){
    int x = NWD(a->licznik, a->mianownik);

    if(x > 1){
        a->licznik /= x;
        a->mianownik /= x;
    }

    if((a->licznik < 0) && (a->mianownik < 0)){
        a->licznik *= -1;
        a->mianownik *= -1;
    }

}
