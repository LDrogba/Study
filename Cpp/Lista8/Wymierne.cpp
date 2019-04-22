#include "Wymierne.hpp"
#include <exception>
using namespace Obliczenia;


Wymierna::Wymierna(int l, int m) throw (Dzielenie_przez_0)
        : licznik(l)
        , mianownik(m)
{

    if(mianownik == 0)
        throw Dzielenie_przez_0();

    int nwd = NWD(l, m);

    licznik /= nwd;
    mianownik /= nwd;

    if (mianownik < 0){
        mianownik *= -1;
        licznik *= -1;
    }
}

int Wymierna::NWD(int l, int m){
    if(l < 0)
        l *= -1;

    while(l!=m)
       if(l>m)
           l-=m;
       else
           m-=l;
    return l;

}

Wymierna::Wymierna(int liczba)
    :Wymierna(liczba, 1)
{
}

Wymierna::get_licznik(){
    return licznik;
}

Wymierna::get_mianownik(){
    return mianownik;
}

Wymierna& Wymierna::operator* (const Wymierna& w) throw (Przekroczono_zakres_int){
    long long int tmp_l = licznik * w.licznik;
    long long int tmp_m = mianownik *= w.mianownik;

    int nwd = NWD(tmp_l, tmp_m);
    tmp_l /= nwd;
    tmp_m /= nwd;

    if(tmp_l > INT_MAX || tmp_m > INT_MAX)
        throw Przekroczono_zakres_int();


    licznik = tmp_l;
    mianownik = tmp_m;

    return *this;
}

Wymierna & Wymierna::operator+(const Wymierna& w) throw (Przekroczono_zakres_int){
    Wymierna *tmp1 = new Wymierna(licznik, mianownik);
    Wymierna *tmp2 = new Wymierna(w.licznik, w.mianownik);

    long long int tmp_l = licznik * w.mianownik;
    long long int tmp_m = mianownik * w.mianownik;

    tmp2->licznik = tmp1->mianownik * w.licznik;
    tmp2->mianownik = tmp1->mianownik * w.mianownik;

    tmp_l += tmp2->licznik;


    int nwd = NWD(licznik, mianownik);

    tmp_l /= nwd;
    tmp_m /= nwd;

    if(tmp_l > INT_MAX || tmp_m > INT_MAX)
        throw Przekroczono_zakres_int();

    licznik = tmp_l;
    mianownik = tmp_m;

    return *this;
}

Wymierna & Wymierna::operator-(const Wymierna& w) throw (Przekroczono_zakres_int){
    Wymierna *tmp1 = new Wymierna(licznik, mianownik);
    Wymierna *tmp2 = new Wymierna(w.licznik, w.mianownik);

    long long int tmp_l = licznik * w.mianownik;
    long long int tmp_m = mianownik * w.mianownik;

    tmp2->licznik = tmp1->mianownik * w.licznik;
    tmp2->mianownik = tmp1->mianownik * w.mianownik;

    tmp_l -= tmp2->licznik;


    int nwd = NWD(licznik, mianownik);

    tmp_l /= nwd;
    tmp_m /= nwd;

    if(tmp_l >2 || tmp_m > INT_MAX)
        throw Przekroczono_zakres_int();

    licznik = tmp_l;
    licznik = tmp_m;

    return *this;
}

Wymierna & Wymierna::operator/ (const Wymierna& w) throw (Przekroczono_zakres_int){
    Wymierna *tmp = new Wymierna(w.mianownik, w.licznik);

    *this = *this* *tmp;

    return *this;
}

Wymierna & Wymierna::operator!() throw (Dzielenie_przez_0){

    if(licznik == 0)
        throw Dzielenie_przez_0();

    int tmp = licznik;
    licznik = mianownik;
    mianownik = tmp;

    return *this;
}

Wymierna & Wymierna::operator~() noexcept{

    licznik *= -1;

    return *this;
}

Wymierna::operator double() const{
    return (double) licznik/mianownik;
}

Wymierna::operator int() const{
    return licznik/mianownik;
}

namespace Obliczenia{

    std::ostream& operator<< (std::ostream &wyj, Wymierna &w){

        int liczba_int = w, liczb_po_przecniku = 6;
        double reszta = w;
        int ile = w.sum25();

        if (reszta < 0){
            wyj << "-";
            liczba_int *= -1;
            reszta *= -1;
        }

        reszta -= liczba_int;

        wyj << liczba_int;
        wyj << ".";

        for (int i = 0; i < ile; i++){

            if(liczb_po_przecniku == 0)
                break;

            int k =(int) (reszta * 10) % 10;
            wyj << k;
            reszta *= 10;
            reszta -= k;
            liczb_po_przecniku--;
        }

        if(liczb_po_przecniku > 0){
            wyj << "(";

            int pop = -1;

            while(true){

                if (liczb_po_przecniku == 0)
                    break;

                int k = (int) (reszta * 10) % 10;
                if (pop == k)
                    break;
                wyj << k;
                reszta *=10;
                reszta -= k;
                pop = k;
//                liczb_po_przecniku--;
            }
            wyj << ")";
        }

        return wyj;

    }
}

Wymierna::sum25()
{
    int mian = mianownik;
    int wynik = 0;

    while(true){
        if(mian % 2 == 0){
            wynik++;
            mian /= 2;
        }
        else if (mian % 5 == 0){
            wynik++;
            mian /= 5;
        }
        else
            break;
    }

    return wynik;
}
