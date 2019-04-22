#ifndef Stos_hpp
#define Stos_hpp

#include <iostream>
#include <string>

class Stos
{
public:
    Stos();
    Stos(int Pojemnosc);
    Stos(const std::initializer_list<std::string> &Lis );
    Stos(const Stos &S);
    Stos(Stos &&S);
    ~Stos();

    Stos &operator=( const Stos &S);
    Stos &operator=( Stos &&S);
    const std::string &operator[] (int i);

    void wloz( const std::string &str);

    std::string sciagnij();

    const std::string& sprawdz() const;

    int rozmiar() const;
private:
    int m_maxPojemnosc;
    int m_ile;
    std::string *m_elementy;

};


#endif // Stos_hpp
