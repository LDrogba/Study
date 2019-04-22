#include <iostream>
#include "Proste.hpp"
//Przeciazenie wyjscia dla Punktu, Wektora, Prostej
using namespace std;

int main()
{
    Punkt a(0, 0);
    Punkt b(1, 1);

    Wektor v(1, 2);
    Wektor u(1, 1);

    Prosta k(-3, 1, 17);
    Prosta i(2, 1, -33);

    cout << "tworzenie wektora ze wspolrzednych" << endl << "3, 4 -> ";
    Wektor p(3, 4);
    cout<< p.dx << " " << p.dy << endl;

    cout << "kopiowanie wektora" << endl << p.dx << " " << p.dy << " -> ";
    Wektor q(p);
    cout<< q.dx << " " << q.dy << endl;

    cout << "przesowanie punktu o wektor" << endl
    << a.x << " " << a.y << " o wektor " << v.dx << " " << v.dy << " -> ";
    Punkt e( a, v);
    cout << e.x << " " << e.y << endl;

    cout << "polaczenie wektorow " << endl;
    Wektor* n_v = Comp(v, u);
    cout << v.dx << " " << v.dy << " , ";
    cout << u.dx << " " << u.dy << " wynosi: " ;
    cout << n_v->dx << " " << n_v->dy << endl;

    cout << "czy proste sa rownolegle" << endl;
    cout << czy_proste_rown(k, i) << endl;

    cout << "przesuniecie o prostej o wektor" << endl;
    Prosta l(k, v);
    cout << k.get_a() << " " << k.get_b()<< " " << k.get_c() << " : " << v.dx << " " << v.dy << " -> ";
    cout << l.get_a() << " " << l.get_b()<< " " << l.get_c() <<endl;

    Punkt* ptt = przeciecie(k, i);
    cout << "punkt przeciecia prostych: " << ptt->x << " " << ptt->y << endl;
    return 0;
}
