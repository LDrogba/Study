#include "Data.hpp"
#include <iostream>
#include <ctime>
const Data *FIRST_DAY = new Data(1,1,0);

unsigned int Data::dniwmiesiacach[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwykłe
        {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestępne
    };

unsigned int Data::dniodpoczroku[2][13] = {
        {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwykłe
        {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestępne
    };

Data::Data(unsigned int day, unsigned int month, unsigned int year)
{
    if(!Data_correct(day, month, year))
        throw std::invalid_argument("Podana data nie istnieje");

    this->day = day;
    this->month = month;
    this->year = year;
}

Data::Data()
{
    time_t czas;
    struct tm *ptr;
    time( &czas );
    ptr = localtime( &czas );

    day = ptr->tm_mday;
    month = ptr->tm_mon + 1;
    year = ptr->tm_year + 1900;
}

unsigned int Data::get_day() const
{
    return day;
}

unsigned int Data::get_month() const
{
    return month;
}

unsigned int Data::get_year() const
{
    return year;
}


bool Data::Data_correct(unsigned int day, unsigned int month, unsigned int year)
{
    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0 )))
        if(dniwmiesiacach[1][month] >= day)
            return true;

    if(dniwmiesiacach[0][month] >= day)
        return true;

    return false;
}

bool Data::intercalar( unsigned int year) const
{
    return ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
}

unsigned int Data::day_count(const Data &d) const
{
    unsigned int days = 0;
    unsigned int in_years = d.get_year()/4 - d.get_year()/100 + d.get_year()/400;

    days = dniodpoczroku[0][12] * (d.get_year() - FIRST_DAY->get_year());
    days += in_years;

    if(intercalar(d.get_year()))
        days += dniodpoczroku[1][d.get_month() - FIRST_DAY->get_month()];
    else
        days += dniodpoczroku[0][d.get_month() - FIRST_DAY->get_month()];

    days += d.get_day() - FIRST_DAY->get_day();

    return days;
}

unsigned int Data::operator-(const Data &d) const
{
    unsigned int day_count_start = day_count(*this);
    unsigned int day_count_end = day_count(d);

    return abs(day_count_end - day_count_start);
}

void Data::operator--()
{

    if(day > 1)
    {
        day--;
        return;
    }

    if(month > 1)
    {
        if(intercalar(year))
        {
            day = dniwmiesiacach[1][month-1];
            month--;
        }
        else
        {
            day = dniwmiesiacach[0][month-1];
            month--;
        }
        return;
    }

    day = dniwmiesiacach[0][12];
    month = 12;
    year--;
}

void Data::operator++()
{
    int inter = intercalar(year);

    if(day<dniwmiesiacach[inter][month])
    {
        day++;
        return;
    }

    if(month<12)
    {
        day = 1;
        month++;
        return;
    }

    day = 1;
    month = 1;
    year++;
}

void Data::operator+=(unsigned int i)
{
    while(i > dniwmiesiacach[intercalar(year)][month] - day)
    {
        i-= dniwmiesiacach[intercalar(year)][month] - day;
        month++;
        if(month == 13)
        {
            year++;
            month=1;
        }
        day=0;
    }

    day+=i;
}

void Data::operator-=(unsigned int i)
{
    while(i >= day)
    {
        i-= day;
        month--;
        if(month == 0)
        {
            year--;
            month = 12;
        }
        day = dniwmiesiacach[intercalar(year)][month];
    }

    day -= i;
}
