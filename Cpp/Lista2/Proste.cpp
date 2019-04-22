#include "Proste.hpp"

//===== Wektor =====
Wektor::Wektor(const double a,const double b)
        : dx(a)
        , dy(b)
        {}

Wektor::Wektor(Wektor& a)
    : dx(a.dx)
    , dy(a.dy)
    {}

//===== Punkt =====
Punkt::Punkt(const double a, const double b)
    :x(a)
    ,y(b)
    {}

Punkt::Punkt(Punkt a, Wektor v)
    :x(a.x + v.dx)
    ,y(a.y + v.dy)
    {}

Punkt::Punkt(Punkt& a)
    :x(a.x)
    ,y(a.y)
    {}

//====== Prosta ======

bool Prosta::rown(const Wektor &v)
    {
        return (this->a == v.dy && 1 == v.dx);
    }

bool Prosta::pros(const Wektor &v)
    {
        return ( this->a == v.dx && this->b == v.dy);
    }

bool Prosta::nalezy(const Punkt &p)
    {
        return (this->b*p.y == this->a*p.x + this->c);
    }

Prosta::Prosta(Punkt &a, Punkt &b)
        :a(a.y - b.y)
        ,b(b.x - a.x)
        ,c(-a.y * (b.x - a.x) + a.x * (b.y - b.y))
    {
        if(a.y == b.y && a.x == b.x)
            throw std::invalid_argument("Nie mozna utworzyc jednoznacznej prostej");
    }

Prosta::Prosta(Wektor v) // not sure
        :a(-1/-(v.dy))
        ,b(1)
        ,c(v.dy - (a * v.dx))
        {}

Prosta::Prosta(double a, double b, double c)
        :a(a)
        ,b(b)
        ,c(c)
    {
        if(a == 0 && b == 0)
            throw std::invalid_argument("Nie mozna utworzyc jednoznacznej prostej");
    }

Prosta::Prosta(Prosta &k, Wektor &v)
        :a(k.a)
        ,b(k.b)
        ,c(k.c - v.dy + v.dx)
    {}

double Prosta::get_a() const
    {
        return a;
    }

double Prosta::get_b() const
    {
        return b;
    }

double Prosta::get_c() const
    {
        return c;
    }

// ====== Global ======

Wektor* Comp(Wektor &v1, Wektor &v2)
{
    Wektor* v3 = new Wektor( v1.dx + v2.dx, v1.dy + v2.dy);
    return v3;
 }

bool czy_proste_pros(Prosta &l, Prosta &k)
{
    return (l.get_a() == (-1/k.get_a()));
}

bool czy_proste_rown(Prosta &l, Prosta &k)
{
    return (l.get_a() == k.get_a());
}

Punkt* przeciecie(Prosta &k, Prosta &l)
{
    double a1 = k.get_a();
    double b1 = k.get_b();
    double c1 = k.get_c();
    double a2 = l.get_a();
    double b2 = l.get_b();
    double c2 = l.get_c();
    double x = (((c2/b2) - (c1/b1))/((a1/b1) - (a2/b2)));
    double y = ( ((a1/b1) * x) + (c1/b1));
    Punkt* pt = new Punkt (x, -y);

    return pt;
}
