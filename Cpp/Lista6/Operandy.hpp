#ifndef Operandy_hpp
#define Operandy_hpp

#include <vector>
#include "Wyrazenie.hpp"

class Liczba : public Wyrazenie
{
    double num;
public:
    Liczba(double l);
    virtual std::string Opis();
    virtual double Oblicz();
};

class Zmienna : public Wyrazenie
{
    static std::vector<std::pair<std::string, double> > zmienne;

    std::string Name;

public:
    Zmienna(std::string name);
    Zmienna(std::string name, double val);
    static double Read(std::string name);
    static void Set(std::string name, double val);
    virtual std::string Opis();
    virtual double Oblicz();
};

class Stala : public Wyrazenie
{
public:
    virtual std::string Opis();
    virtual double Oblicz();
private:
    std::string Name;
    double Val;
protected:
    Stala(std::string name, double val);
};

class Pi : public Stala
{
public:
    Pi();
};

class Fi : public Stala
{
public:
    Fi();
};

class e : public Stala
{
public:
    e();
};
#endif // Operandy_hpp
