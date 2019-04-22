#ifndef Proste
#define Proste

#include <iostream>
#include <stdexcept>

class Wektor
{
public:
    const double dx;
    const double dy;

    Wektor() = default;
    Wektor( const Wektor & ) = delete;
    Wektor & operator = (const Wektor &) = delete;

    Wektor(const double a,const double b);
    Wektor(Wektor& a);
};

class Punkt
{
public:
    const double x;
    const double y;

    Punkt( const Punkt & ) = delete;
    Punkt & operator = (const Punkt &) = delete;
    Punkt() = default;

    Punkt(const double a, const double b);
    Punkt(Punkt a, Wektor v);
    Punkt(Punkt& a);

};

class Prosta
{
public:

    Prosta(Punkt &a, Punkt &b);
    Prosta(Wektor v);
    Prosta(double a, double b, double c);
    Prosta(Prosta &k, Wektor &v);
    Prosta() = default;

    bool rown(const Wektor &v);
    bool pros(const Wektor &v);
    bool nalezy(const Punkt &p);
    double get_a() const;
    double get_b() const;
    double get_c() const;

private:
    double a;
    double b;
    double c;

};

Wektor* Comp(Wektor &v1, Wektor &v2);
bool czy_proste_pros(Prosta &l, Prosta &k);
bool czy_proste_rown(Prosta &l, Prosta &k);
Punkt* przeciecie(Prosta &l, Prosta &k);

#endif // Proste
