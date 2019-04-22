
#ifndef Macierz_hpp
#define Macierz_hpp

#include <iostream>
#include "Bledy.hpp"

namespace Obliczenia{
class Macierz{
    public:
        float **macierz;
        int a;
        int b;
    public:
        Macierz (const int &a);                          // konstruktor macierz jednostkowa kwadratowa DONE
        Macierz (const int &a, int const &b);                  // konstruktor macierz wypelniona 0 prostokatna DONE
        Macierz (const Macierz &m);                // konstruktor kopjujacy DONE
        Macierz (Macierz &&m);                     // konstruktor przenosszacy DONE

        Macierz & operator= (const Macierz &m);  // przypisanie kopjujace DONE
        Macierz & operator= (Macierz &&m);       // przypisanie przenoszace DONE
        Macierz & operator-= (const Macierz &m) throw (Zle_Wymiary); // odejmowanie od macierzy DONE
        Macierz & operator+= (const Macierz &m) throw (Zle_Wymiary); // dodawanie do macierzy DONE
        Macierz & operator*= (const Macierz &m) throw (Zle_Wymiary); // mnozenie przez macierz DONE
        Macierz & operator*= (const float &s);   // mnozenie przez skalar DONE
        Macierz & operator~();                   // transpozcyja DONE
        friend Macierz operator+ (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary);// dodwanie dwoch macierzy DONE
        friend Macierz operator- (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary); // odejmowanie dwoch macierzy DONE
        friend Macierz operator* (const Macierz &m1, const Macierz &m2) throw (Zle_Wymiary); // mnozenie dwoch macierzy DONE
        friend Macierz operator* (const Macierz &m, const float &s)
        {
            Macierz *new_m = new Macierz(m.a, m.b);

            for (int i=0; i<m.a; i++)
                for (int j=0; j<m.b; j++)
                    new_m->macierz[i][j] = m.macierz[i][j] * s;

            return *new_m;
        } // mnozenie macierzy przez skalar DONE
        friend Macierz operator~ (const Macierz &m); // transpozycja DONE
        ~Macierz(); // DONE

        void Zmien_wiersz(int w1, int w2);
        void Zmien_kolumne(int k1, int k2);
        void Dodaj_wiersz(int w1, int w2, float l);
        void Dodaj_kolumna(int k1, int k2, float l);
        void Pomnoz_wiersz_liczba(int w1, float l);
        void Pomnoz_kolumne_liczba(int k1, float l);
        Macierz & Usun_wiersz(int w1);
        Macierz & Usun_kolumne(int k1);
        float Det();




        void Wypisz();                           // DONE

        friend std::ostream & operator<< (std::ostream& out, const Macierz& m){
            out << "Macierz " << m.a << "x" << m.b << std::endl;

            for(int i=0; i<m.a; i++){
                for(int j=0; j<m.b; j++)
                    out << m.macierz[i][j] << "  ";
                out << std::endl;
            }
            out << std::endl;

            return out;
        }; // DONE

        friend std::istream & operator>> (std::istream& in, Macierz& m){
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
    };
}

#endif // Macierz_hpp
