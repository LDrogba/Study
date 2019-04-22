#ifndef Wymierne_hpp
#define Wymierna_hpp

#include <iostream>
#include "wyjatki.hpp"
#include <climits>

namespace Obliczenia{

    class Wymierna{
        int licznik, mianownik;

    public:
        Wymierna(int l, int m) throw (Dzielenie_przez_0);
        Wymierna(int x);
        int get_licznik();
        int get_mianownik();
        Wymierna & operator* (const Wymierna& w) throw (Przekroczono_zakres_int);
        Wymierna & operator/ (const Wymierna& w) throw (Przekroczono_zakres_int);
        Wymierna & operator+ (const Wymierna& w) throw (Przekroczono_zakres_int);
        Wymierna & operator- (const Wymierna& w) throw (Przekroczono_zakres_int);
        Wymierna & operator~ () throw (Dzielenie_przez_0);
        Wymierna & operator! () throw (Dzielenie_przez_0);



        operator double() const;
        explicit operator int() const;

        friend std::ostream& operator<< (std::ostream &wyj, Wymierna &w);
    private:
        int sum25();
        int NWD(int l1, int l2);

    };
}
#endif // Wymierne_hpp
