#include <iostream>
#include <vector>
#include <algorithm>

#include "Data.hpp"
#include "DataGodz.hpp"
#include "Wydarzenie.hpp"

using namespace std;

void Wypisz_Date(Data &d)
{
    cout << d.get_year() << "." << d.get_month() << "." << d.get_day() << endl;
}

void Wypisz_DataGodzina(DataGodz &d)
{
    cout << d.get_year() << "." << d.get_month() << "." << d.get_day() << " - "
         << d.get_hour() << ":" << d.get_minute() << "." << d.get_second() << endl;
}

void Wypisz_Wydarzenie(Wydarzenie &w)
{
    cout << w.opis << ": ";
    Wypisz_DataGodzina(w.czas);

}
int main()
{
    cout << "Hello world!" << endl;
    Data dat1 = Data(4, 1, 2000);
    cout << "data 1: ";
    Wypisz_Date(dat1);
    Data dat2 = Data(dat1);
    cout << "data 2: ";
    Wypisz_Date(dat2);
    Data dat3 = Data();
    cout << "data 3: ";
    Wypisz_Date(dat3);
    cout << "-------------------" << endl;
    dat2 = dat3;
    cout << "data 2 = data 3: ";
    Wypisz_Date(dat3);
    cout << "-------------------" << endl;
    dat3 -= 29;
    cout << "data 3 - 8 dni: ";
    Wypisz_Date(dat3);
    cout << "-------------------" << endl;
    dat3.operator++();
    cout << "data 3++: ";
    Wypisz_Date(dat3);
    cout << "-------------------" << endl;
    DataGodz datagodz1 = DataGodz(15, 4, 2018, 13, 20, 49);
    DataGodz datagodz2 = DataGodz(15, 3, 2018, 2, 2, 43);

    cout << "data z godzina 1: ";
    Wypisz_DataGodzina(datagodz1);

    cout << "data z godzina 2: ";
    Wypisz_DataGodzina(datagodz2);
    cout << "-------------------" << endl;
    cout << "Czy data z godz 2 jest mniejsza niz data z godz 1? 1-tak 0-nie" << endl;
     int k;
    if(datagodz2 < datagodz1)
        k=1;
    else
        k=0;

    cout << k << endl;

    cout << "-------------------" << endl;
    cout << "data z godzina 1 odjac data z godzina 2: ";
    cout << datagodz1 - datagodz2 << endl;
    cout << "-------------------" << endl;
    datagodz1 -= 400*24*60*60 + 3*60*60 + 10 * 60 + 3;

    cout << "data z godzina minus 400 dni 3 h 10 min i 3 sek  : ";

    Wypisz_DataGodzina(datagodz1);

    Wydarzenie Urodziny_Milosza = Wydarzenie("Urodziny Milosza", 30, 4, 2009);
    Wydarzenie Urodziny_Szymka = Wydarzenie("Urodziny Szymka", 30, 3, 2007);
    Wydarzenie Urodziny_Tomka = Wydarzenie("Urodziny Tomka", 27, 2, 1997);
    Wydarzenie Urodziny_Lukasza = Wydarzenie("Urodziny Lukasza", 29, 7, 1999);

    vector<Wydarzenie> historia = { Urodziny_Tomka, Urodziny_Milosza, Urodziny_Szymka, Urodziny_Lukasza};

    cout << "Przed sortowaniem: " << endl;
    for(Wydarzenie w : historia)
        Wypisz_Wydarzenie(w);

    sort(historia.begin(), historia.end());
    cout << "-------------------" << endl;
    cout << "Po sortowaniu: " << endl;
    for(Wydarzenie w : historia)
        Wypisz_Wydarzenie(w);

    return 0;
}
