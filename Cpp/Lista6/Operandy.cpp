#include "Operandy.hpp"
#include <sstream>
#include <string>

std::vector<std::pair<std::string, double> > Zmienna::zmienne;

Liczba::Liczba(double l)
: Wyrazenie()
{
    prior = 10;
    num = l;
}

std::string Liczba::Opis()
{
    return std::to_string(num);
}

double Liczba::Oblicz()
{
    return num;
}

Zmienna::Zmienna(std::string name)
    : Wyrazenie()
    , Name(name)
{
    std::pair<std::string, double> tmp;

    tmp.first = name;

    zmienne.push_back(tmp);
    prior = 10;
}

Zmienna::Zmienna(std::string name, double val)
    : Wyrazenie()
    , Name(name)
{
    std::pair<std::string, double> tmp;

    tmp.first = name;
    tmp.second = val;

    zmienne.push_back(tmp);
}

double Zmienna::Read(std::string name)
{
    for( auto &k : zmienne ){
        if (k.first == name)
            return k.second;
    }

    return 0;
}

void Zmienna::Set(std::string name, double val)
{
    for( auto &k : zmienne)
        if(k.first == name)
            k.second = val;
}

std::string Zmienna::Opis()
{
    return Name;
}

double Zmienna::Oblicz()
{
    return Read(Name);
}

Stala::Stala(std::string name, double val)
    : Wyrazenie()
    , Name(name)
    , Val(val)
{
    prior = 10;
}

std::string Stala::Opis()
{
    return Name;
}

double Stala::Oblicz()
{
    return Val;
}

Pi::Pi()
    :Stala("Pi", 3.141592)
{
}

Fi::Fi()
:Stala("Fi", 1.618033)
{
}

e::e()
:Stala("e", 2.728281)

{
}
