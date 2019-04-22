#include "Wydarzenie.hpp"

bool Wydarzenie::operator< ( const Wydarzenie &w2)
{
    return(czas < w2.czas);
}

Wydarzenie::Wydarzenie( std::string nazwa, unsigned int day, unsigned int month, unsigned int year, unsigned int hour, unsigned int minute,
                       unsigned int sec)
    : czas(day,month,year,hour,minute,sec)
    , opis(nazwa)
{
}

