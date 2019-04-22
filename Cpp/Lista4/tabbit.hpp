#ifndef tabbit_hpp
#define tabbit_hpp

#include <iostream>

class tab_bit
{
    typedef uint64_t slowo; // komorka w tablicy
    static const int rozmiarSlowa; // rozmiar slowa w bitach
    friend std::istream & operator >> (std::istream &we, tab_bit &tb);
    friend std::ostream & operator << (std::ostream &wy, const tab_bit &tb);

    struct ref
        {
            slowo* ptrSl;
            int numBit;
            bool operator = ( bool flag );
         }; // klasa pomocnicza do adresowania bitów DONE

    protected:
        int dl; // liczba bitów
        slowo *tab; // tablica bitów

    public:
        explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm] DONE
        explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa] DONE
                                     // zainicjalizowana wzorcem
        tab_bit (const tab_bit &tb); // konstruktor kopiujący DONE
        tab_bit (tab_bit &&tb); // konstruktor przenoszący DONE
        tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujące DONE
        tab_bit & operator = (tab_bit &&tb); // przypisanie przenoszące DONE
        tab_bit (const std::initializer_list<bool> &lis); // DONE
        ~tab_bit (); // destruktor DONE
        tab_bit ();

    private:
        slowo *Powieksz(int i); // metoda powiekszajaca tablice bitow DONE
        void pisz (int i, bool b); // metoda pomocnicza do zapisu bitu DONE
        bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu DONE

    public:
        bool operator[] (int i) const; // indeksowanie dla stałych tablic bitowych DONE
        ref operator[] (int i); // indeksowanie dla zwykłych tablic bitowych DONE
        inline int rozmiar () const; // rozmiar tablicy w bitach DONE

    public:
        tab_bit & operator | (const tab_bit &tb);
        tab_bit & operator |= (const tab_bit &tb);
        tab_bit & operator & ( const tab_bit &tb);
        tab_bit & operator &= (const tab_bit &tb);
        tab_bit & operator ^ (const tab_bit &tb);
        tab_bit & operator ^= (const tab_bit &tb);
        tab_bit & operator ! ();

        // operatory bitowe: | i |=, & i &=, ^ i ^= oraz ! - DONE

    public:
        friend std::istream & operator >> (std::istream &we, tab_bit &tb);
        friend std::ostream & operator << (std::ostream &wy, tab_bit &tb);
        // zaprzyjaźnione operatory strumieniowe: << i >> - NOPE
};

#endif // tabbit_hpp
