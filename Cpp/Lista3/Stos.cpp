#include "Stos.hpp"
#include <exception>

Stos::Stos()
     : Stos(1)
{
}

Stos::Stos(int Pojemnosc)
    : m_maxPojemnosc(Pojemnosc)
    , m_ile(0)
    , m_elementy(new std::string[Pojemnosc])
{
}

Stos::Stos(const std::initializer_list<std::string> &Lis)
    : Stos( Lis.size())
{
    for(const std::string &slowo : Lis)
            wloz(slowo);
}

Stos::Stos(const Stos &S)
    : Stos(S.rozmiar())
{
    for(int i=0; i<S.rozmiar(); i++)
        wloz(S.m_elementy[i]);
}

Stos::Stos(Stos &&S)
    :Stos(S.rozmiar())
{
    m_elementy = S.m_elementy;
    S.m_elementy = nullptr;
}

Stos::~Stos()
{
    delete[] m_elementy;
}

Stos &Stos::operator=( const Stos &S)
{
    if(this != &S)
    {
        delete[] m_elementy;
        m_elementy = new std::string[S.m_maxPojemnosc];

        m_maxPojemnosc = S.m_maxPojemnosc;
        for(int i=0; i<S.rozmiar(); i++)
            wloz(S.m_elementy[i]);
    }

    return *this;
}

Stos &Stos::operator=( Stos &&S)
{
    if(this != &S){
        m_maxPojemnosc = S.m_maxPojemnosc;
        m_ile = S.m_ile;
        delete[] m_elementy;
        m_elementy = S.m_elementy;
        S.m_elementy = nullptr;
        S.m_maxPojemnosc = S.m_ile = 0;
    }

    return *this;
}

const std::string &Stos::operator[] (int i)
{
    return m_elementy[i];
}

void Stos::wloz(const std::string &slowo)
{
    if(m_ile==m_maxPojemnosc)
        throw std::invalid_argument("Stos jest juz pelny");

    m_elementy[m_ile] = slowo;
    m_ile++;
}

int Stos::rozmiar() const
{
    return m_ile;
}

const std::string &Stos::sprawdz() const
{
    return m_elementy[m_ile-1];
}

std::string Stos::sciagnij()
{
    if(m_ile == 0)
        throw std::invalid_argument("Stos jest pusty");

    std::string slowo = sprawdz();

    m_elementy[m_ile-1] = "";
    m_ile--;

    return slowo;
}
