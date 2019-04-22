#include "Macierz.hpp"
#include "bledy.hpp"
using namespace Obliczenia;

Macierz::Macierz(const int &a)
    :a(a)
    ,b(a)
{
    macierz = new float *[a];

    for(int i=0; i<a; i++){
        macierz[i] = new float [a];
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            if(i==j)
                macierz[i][j] = 1;
            else
                macierz[i][j] = 0;
        }
    }
}

Macierz::Macierz(const int &a, const int &b)
    :a(a)
    ,b(b)
{
    macierz = new float *[a];

    for(int i=0; i<a; i++)
        macierz[i] = new float[b];

    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] = 0;
}

Macierz::Macierz(Macierz &&m)
    :Macierz(m.a, m.b)
{
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] = m.macierz[i][j];

    delete m.macierz;
    m.a = 0;
    m.b = 0;
}

Macierz::Macierz(const Macierz &m)
    :Macierz(m.a, m.b)
{
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] = m.macierz[i][j];

}

Macierz& Macierz::operator=(const Macierz& m){
    if(this == &m)
        return *this;
    Macierz *tmp = new Macierz(m);

    a = m.a;
    b = m.b;
    macierz = tmp->macierz;
    return *tmp;
}

Macierz& Macierz::operator*=(const float &s)
{
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] *= s;
    return *this;
}

Macierz& Macierz::operator+=(const Macierz &m) throw (Zle_Wymiary)
{
    if(a!=m.a || b!=m.b)
        throw new Zle_Wymiary();

    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] += m.macierz[i][j];

    return *this;
}

Macierz& Macierz::operator-=(const Macierz &m) throw (Zle_Wymiary)
{
    if(a!=m.a || b!=m.b)
        throw new Zle_Wymiary();

    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            macierz[i][j] -= m.macierz[i][j];

    return *this;
}

Macierz& Macierz::operator*=(const Macierz &m) throw (Zle_Wymiary)
{
    if (a != m.b)
        throw new Zle_Wymiary();

    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            float tmp = 0;
            for (int k=0; k<b; k++)
            {
                tmp += macierz[i][k]*m.macierz[k][j];//  a.macierz[i].vals[k] * b.macierz[k].vals[j];
            }
            macierz[i][j] = tmp;
        }
    }

    return *this;
}

void Macierz::Wypisz(){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++)
            std::cout<<macierz[i][j]<<" ";
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

Macierz& Macierz::operator~(){

    Macierz *tmp = new Macierz(b, a);

    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            tmp->macierz[j][i] = macierz[i][j];

    this->macierz = tmp->macierz;
    a=tmp->a;
    b=tmp->b;

    return *this;
}
namespace Obliczenia{
    Macierz operator+ (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary){
        if(m1.a != m2.a || m1.b != m2.b )
            throw new Zle_Wymiary();

        Macierz *new_m = new Macierz(m1.a, m1.b);

        for(int i=0; i<m1.a; i++)
            for(int j=0; j<m1.b; j++)
                new_m->macierz[i][j] = m1.macierz[i][j] + m2.macierz[i][j];

        return *new_m;
    }
}
Macierz operator- (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary){
    if(m1.a != m2.a || m1.b != m2.b)
        throw new Zle_Wymiary();

    Macierz *new_m = new Macierz(m1.a, m1.b);

    for(int i=0; i<m1.a; i++)
        for(int j=0; j<m1.b; j++)
            new_m->macierz[i][j] = m1.macierz[i][j] + m2.macierz[i][j];

    return *new_m;
}
Macierz operator* (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary){
    if (m1.a != m2.b)
        throw new Zle_Wymiary();
    Macierz *new_m = new Macierz(m1.a, m2.b);

    for (int i=0; i<m1.a; i++){
        for (int j=0; j<m1.b; j++){
            for (int k=0; k<m1.b; k++)
            {
                new_m->macierz[i][j] += m1.macierz[i][k]*m2.macierz[k][j];//  a.macierz[i].vals[k] * b.macierz[k].vals[j];
            }
        }
    }

    return *new_m;
}

//Obliczenia::Macierz operator* (const Macierz &m, const float &s)

Macierz operator~ (const Macierz &m){
    Macierz *new_m = new Macierz(m.b, m.a);

    for (int i=0; i<m.a; i++)
        for (int j=0; j<m.b; j++)
            new_m->macierz[j][i] = m.macierz[i][j];

    return *new_m;
}

Macierz::~Macierz(){
    delete macierz;
}
/*
std::istream  operator >> (std::istream &in, Obliczenia::Macierz &m)
{
    int a,b;

    in >> a;
    in >> b;
    m.macierz = new float*[a];
    for(int i=0; i<b; i++)
        m.macierz[i] = new float[b];

    m.a = a;
    m.b = b;

    int ile = 0;
    int wiersz = 0;
    int kolumna = 0;

    while(ile < a*b){
        in >> m.macierz[wiersz][kolumna];

        if(kolumna == b-1){
            kolumna = 0;
            wiersz++;
        }
        else
            kolumna++;

        ile++;
    }

    return in;
}

Obliczenia::Macierz std::ostream operator << (std::ostream &out, const Obliczenia::Macierz &m)
{
    out << "Macierz " << m.a << "x" << m.b << std::endl;

    for(int i=0; i<m.a; i++){
        for(int j=0; j<m.b; j++)
            out << m.macierz[i][j] << "  ";
        out << std::endl;
    }
    out << std::endl;

    return out;
}
*/
void Macierz::Zmien_wiersz(int w1, int w2){

    for(int i=0; i<b; i++){
        int tmp;
        tmp = macierz[w1][i];
        macierz[w1][i] = macierz[w2][i];
        macierz[w2][i] = tmp;
    }
}

void Macierz::Zmien_kolumne(int k1, int k2){

    for(int i=0; i<b; i++){
        int tmp;
        tmp = macierz[i][k1];
        macierz[i][k1] = macierz[i][k2];
        macierz[i][k2] = tmp;
    }

}
void Macierz::Dodaj_wiersz(int w1, int w2, float l){
    for(int i=0; i<a; i++)
        macierz[w1][i] += macierz[w2][i]*l;
}
void Macierz::Dodaj_kolumna(int k1, int k2, float l){
    for(int i=0; i<b; i++)
        macierz[i][k1] += macierz[i][k2]*l;
}
void Macierz::Pomnoz_wiersz_liczba(int w1, float l){
    for(int i=0; i<a; i++)
        macierz[w1][i] *= l;
}
void Macierz::Pomnoz_kolumne_liczba(int k1, float l){
    for(int i=0; i<b; i++)
        macierz[i][k1] *= l;
}

float Macierz::Det(){}

Macierz & Macierz::Usun_wiersz(int w1){
    w1--;

    Macierz *tmp = new Macierz(*this);
    tmp->Zmien_wiersz(w1, a-1);
    tmp->a--;
    tmp->macierz[a-1] = nullptr;


    return *tmp;
}

Macierz & Macierz::Usun_kolumne(int k1){
    k1--;
    Macierz *tmp = new Macierz(a,b-1);

    for(int i=0; i<a; i++){
        int j_tmp = 0;
        for(int j=0; j<b; j++){
            if(j == k1);
            else{
                tmp->macierz[i][j_tmp] = macierz[i][j];
                j_tmp++;
            }
        }
    }
    return *tmp;
}
