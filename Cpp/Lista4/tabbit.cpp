#include "tabbit.hpp"
#include <limits>
#include <stdexcept>
#include <stdlib.h>

const int tab_bit::rozmiarSlowa = sizeof(tab_bit::slowo);

tab_bit::tab_bit( int rozm )
    :dl(rozm)
{
    const int roz = (rozm + sizeof(slowo)-1) / sizeof(slowo);
    tab = new slowo[roz];
    for(int i = 0; i < roz; i++)
        tab[i] = 0;

} // wyzerowana tablica bitow [0...rozm]

tab_bit::tab_bit( slowo tb )
    :dl(sizeof(tab_bit::slowo)*8)
{
    slowo *tablica = new slowo[1];

    *tablica = tb;
}

tab_bit::tab_bit( const tab_bit &tb )
    :tab_bit(tb.rozmiar())
{
    const int roz = (tb.rozmiar() + sizeof(slowo)-1) / sizeof(slowo);
    tab = new slowo[roz];

    for(int i = 0; i < roz; i++)
        tab[i] = tb.tab[i];
}

tab_bit::tab_bit( tab_bit &&tb )
    :tab_bit(tb.rozmiar())
{
    tab = tb.tab;
    tb.tab = nullptr;
    tb.dl = 0;
}

tab_bit::tab_bit(const std::initializer_list<bool> &lis)
    :tab_bit((int)lis.size())
{
    int i = 0;

    for(int elem : lis)
        {
            pisz(i, elem);
            i++;
        }
}

tab_bit::~tab_bit()
{
    delete[] tab;
}


bool tab_bit::czytaj(int i) const
{
    int nr_slowa = i/sizeof(slowo);
    int bit = i%sizeof(slowo);
    slowo mask = 1<<bit;

    return (tab[nr_slowa] & mask); //tylko dla 0 zwraca falsz
}

void tab_bit::pisz(int i, bool b)
{
    tab_bit::operator[](i) = b;
}

tab_bit::slowo* tab_bit::Powieksz(int i)
{
    dl = i;
    tab_bit::slowo* new_tab =(tab_bit::slowo*) realloc(tab, sizeof(slowo)*(i/sizeof(slowo)));
    return new_tab;
}

int tab_bit::rozmiar() const
{
    return dl;
}

tab_bit &tab_bit::operator = ( const tab_bit &tb )
{
    if (this != &tb)
    {
        const int roz = (tb.rozmiar() + sizeof(slowo)-1) / sizeof(slowo);
        dl = tb.rozmiar();
        delete[] tab;
        tab = new slowo[roz];

        for( int i = 0; i < roz; i++)
            tab[i] = tb.tab[i];
    }

    return *this;
}

tab_bit &tab_bit::operator = ( tab_bit &&tb )
{
    if (this != &tb)
    {
        dl = tb.rozmiar();
        delete[] tab;
        tab = tb.tab;
        tb.tab = nullptr;
        tb.dl = 0;
    }

    return *this;
}

bool tab_bit::operator[] (int i) const
{
    return czytaj(i);
}

tab_bit::ref tab_bit::operator[] (int i)
{
    ref *new_ref = new ref;
    new_ref->numBit = i;
    new_ref->ptrSl = tab;

    return *new_ref;
}

bool tab_bit::ref::operator = (bool flag)
{
    int set_bit = numBit%sizeof(tab_bit::slowo);
    int nr_slowa =  numBit/sizeof(tab_bit::slowo);

    ptrSl[nr_slowa] = (ptrSl[nr_slowa] & ~(1<<set_bit)) | (flag<<set_bit);

    return flag;
}

tab_bit &tab_bit::operator | (const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    tab_bit* new_tab = new tab_bit(dl);

    for(unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++)
        new_tab->tab[i] = tab[i] | tb.tab[i];

    return *new_tab;
}

tab_bit & tab_bit::operator |= (const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    for(unsigned int i=0; i<=dl/sizeof(tab_bit::slowo); i++)
        tab[i] |= tb.tab[i];

    return *this;
}

tab_bit & tab_bit::operator & ( const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    tab_bit *new_tab = new tab_bit(dl);

    for(unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++)
        new_tab ->tab[i] = tab[i] & tb.tab[i];

    return *new_tab;
}

tab_bit & tab_bit::operator &= (const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    for(unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++)
        tab[i] &= tb.tab[i];

    return *this;
}

tab_bit & tab_bit::operator ^ (const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    tab_bit *new_tab = new tab_bit ( dl );

    for (unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++ )
        new_tab -> tab[i] = tab[i] ^ tb.tab[i];

    return *new_tab;
}

tab_bit & tab_bit::operator ^= (const tab_bit &tb)
{
    if (tb.dl != dl)
        throw std::invalid_argument("Operator nie dziala na tablicach o roznej ilosci slow");

    for(unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++)
        tab[i] ^= tb.tab[i];

    return *this;
}

tab_bit & tab_bit::operator ! ()
{
    for(unsigned int i = 0; i <= dl/sizeof(tab_bit::slowo); i++)
        tab[i] = ~tab[i];

    return *this;
}

std::istream & operator >> (std::istream &wejscie, tab_bit &tb)
{
    int i=0;
    while(i<3)
    {
        int x;
        wejscie >> x;

        if(x != 1 && x!= 0)
            break;

        tb.pisz(i, x);

        i++;
        if(tb.dl < i)
            tb.dl++;
    }

    return wejscie;
}

std::ostream & operator << (std::ostream &wyjscie, tab_bit &tb)
{
    for(int i=0; i<tb.dl; i++)
        wyjscie << tb.czytaj(i);

    return wyjscie;
}
