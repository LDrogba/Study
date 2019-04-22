#include <iostream>
#include "Wymierne.hpp"
#include "wyjatki.hpp"

using namespace Obliczenia;

using namespace std;
int main()
{
    Wymierna w1(10, 1);
    Wymierna w2(1, 1);
    Wymierna w3(1, 1);
    Wymierna w5(-1, 6);
    cout << "w1: " << w1 << "w2: " << w2<< endl;
    try{
        w3 = w1+w2;
        cout << "w2+w1" << endl;
        cout << w3 << endl;
        ~w1;
        cout << "~w1" << endl;
        cout << w1 << endl;
        Wymierna w4(w1);
        cout << (int) w4 << endl;

        double k = w4;
        cout << k <<endl ;
        cout << w5 << endl;
    }
    catch (Przekroczono_zakres_int & w){
            cout << w.exp() << endl;
            }
    catch(Dzielenie_przez_0 & w){
        cout <<w.exp() << endl;
    }
    return 0;
}
