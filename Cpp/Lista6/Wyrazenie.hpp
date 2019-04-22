#ifndef Wyrazenie_hpp
#define Wyrazenie_hpp

#include <string>

class Wyrazenie
{
public:
    int prior;
public:
    virtual double Oblicz() = 0;
    virtual std::string Opis() = 0;
    ~Wyrazenie() = default;
};


#endif // Wyrazenie_hpp
