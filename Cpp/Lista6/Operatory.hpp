#ifndef Operatory_hpp
#define Operatory_hpp

#include "Wyrazenie.hpp"

class Operator1arg : public Wyrazenie
{
protected:
    Wyrazenie* wyr1;
    Operator1arg(Wyrazenie *w);
    ~Operator1arg();
};

class Operator2arg : public Operator1arg
{
protected:
    Operator2arg(Wyrazenie *w1, Wyrazenie *w2);
    Wyrazenie* wyr2;
    ~Operator2arg();
};

class Op_sin : public Operator1arg
{
public:
    Op_sin(Wyrazenie *w);
    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_cos : public Operator1arg
{
public:
    Op_cos(Wyrazenie *w);
    int piror;
    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_ln : public Operator1arg
{
public:
    Op_ln(Wyrazenie *w);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_exp : public Operator1arg
{
public:
    Op_exp(Wyrazenie *w);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_przeciw : public Operator1arg
{
public:
    Op_przeciw(Wyrazenie *w);
    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_bezwzgl : public Operator1arg
{
public:
    Op_bezwzgl(Wyrazenie *w);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_odwrot : public Operator1arg
{
public:
    Op_odwrot(Wyrazenie *w);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_dodaj : public Operator2arg
{
public:
    Op_dodaj(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_odejmij : public Operator2arg
{
public:
    Op_odejmij(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_mnoz : public Operator2arg
{
public:
    Op_mnoz(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_dziel : public Operator2arg
{
public:
    Op_dziel(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_logarytm : public Operator2arg
{
public:
    Op_logarytm(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_potega : public Operator2arg
{
public:
    Op_potega(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};

class Op_modulo : public Operator2arg
{
public:
    Op_modulo(Wyrazenie *w1, Wyrazenie*w2);

    virtual std::string Opis();
    virtual double Oblicz();
};
#endif // Opertory_hpp
