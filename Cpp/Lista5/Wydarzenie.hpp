#ifndef Wydarzenie_hpp
#define Wydarzenie_hpp

#include <string>
#include "DataGodz.hpp"

class Wydarzenie
{
public:
    Wydarzenie(std::string nazwa, unsigned int day, unsigned int month = 1, unsigned int year = 0, unsigned int hour = 0, unsigned int minute = 0,
               unsigned int sec = 0);
    DataGodz czas;
    std::string opis;
    bool operator< ( const Wydarzenie &w1 );
};

#endif // Wydarzenie_hpp
