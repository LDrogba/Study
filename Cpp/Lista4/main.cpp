#include <iostream>
#include "tabbit.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl << "-------------" << endl;
    tab_bit tb_1{true,true,false};
    cout << "tb_1: " << tb_1 << endl << "-------------"  << endl;
    tab_bit tb_2(0);
    cout << "tb_2: " << tb_2 << endl << "-------------" << endl;
    tab_bit tb_3(tb_1);
    cout << "tbl_3 stworzony z kopiowania tb_1: " << tb_3 << endl << "-------------"  << endl;
    cout << "tb_2 | tb_1: " << (tb_3 | tb_1) << endl << "-------------" << endl;
    cout << "podaj 3 wartosci bedac 0 lub 1" << endl;
    cin >> tb_2;
    cout << "nowa tablica tb_2: " << tb_2 << endl << "-------------" << endl;
    cout << "tb_2 & tb_1: " << (tb_2 & tb_1 ) << endl << "-------------" << endl;
    cout << "tb_2: " << tb_2 << endl << "-------------" << endl;
    cout << "tb_2 ^ tb_1: " << (tb_2 ^ tb_1) << endl << "-------------" << endl;
    cout << "tb_2: " << tb_2 << endl << "-------------" << endl;
    cout << "!tb_2: " << (!tb_2) << endl << "-------------" << endl;
    tb_2 &= tb_1;
    cout << "tb_2 &= tb_1: " << tb_2 << endl << "-------------" << endl;
    return 0;
}
