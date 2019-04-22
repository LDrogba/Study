#include "DataGodz.hpp"
#include <iostream>
#include <ctime>
unsigned int DataGodz::get_hour() const
{
    return hour;
}

unsigned int DataGodz::get_minute() const
{
    return minute;
}

unsigned int DataGodz::get_second() const
{
    return second;
}

bool DataGodz::Time_correct(unsigned int s, unsigned int m, unsigned int h)
{
    return (s < 60 && m < 60 && h < 24);
}

DataGodz::DataGodz(unsigned int d, unsigned int mon, unsigned int y, unsigned int h, unsigned int m, unsigned int s)
{
    if(!Data_correct(d, mon, y))
        throw std::invalid_argument("Podana data jest niepoprawna");
    if(!Time_correct(s, m, h))
        throw std::invalid_argument("Podana godzina jest niepoprawna");

    year = y;
    month = mon;
    day = d;
    hour = h;
    minute = m;
    second = s;

}

DataGodz::DataGodz()
{
    time_t czas;
    struct tm *ptr;
    time( &czas );
    ptr = localtime( &czas );

    year = ptr->tm_year + 1900;
    month = ptr->tm_mon + 1;
    day = ptr ->tm_mday;
    hour = ptr ->tm_hour;
    minute = ptr->tm_min;
    second = ptr->tm_sec;
}

void DataGodz::operator++()
{
    if(second < 58)
    {
        second++;
        return;
    }

    if(minute < 58)
    {
        second = 0;
        minute++;
        return;
    }

    if(hour < 23)
    {
        second = 0;
        minute = 0;
        hour++;
        return;
    }

    if(day < dniwmiesiacach[intercalar(year)][month])
    {
        second = 0;
        minute = 0;
        hour = 0;
        day++;
        return;
    }

    if(month < 12)
    {
        second = 0;
        minute = 0;
        hour = 0;
        day = 1;
        month++;
        return;
    }


    second = 0;
    minute = 0;
    hour = 0;
    day = 1;
    month = 1;
    year++;
    return;
}

void DataGodz::operator--()
{
    if(second > 1)
    {
        second--;
        return;
    }

    if(minute > 1)
    {
        second = 59;
        minute--;
        return;
    }

    if(hour > 1)
    {
        second = 59;
        minute = 59;
        hour--;
        return;
    }

    if(day > 1)
    {
        second = 59;
        minute = 59;
        hour = 23;
        day--;
        return;
    }

    if(month > 1)
    {
        second = 59;
        minute = 59;
        hour = 23;
        day=dniwmiesiacach[intercalar(year)][month-1];
        month--;
        return;
    }

    second = 59;
    minute = 59;
    hour = 23;
    day = 31;
    month = 12;
    year--;
}

void DataGodz::operator+=(unsigned int i)
{
    unsigned int sec_in_month = (60*60*24*dniwmiesiacach[intercalar(year)][month]);
    unsigned int actual_sec_in_month = (second + minute*60 + hour * 60 * 60 + (day - 1)* 60 * 60 * 24);

    while(i >= (sec_in_month - actual_sec_in_month)) //miesiac i rok nowej daty
    {
        i -= sec_in_month - actual_sec_in_month;
        second = 0;
        minute = 0;
        hour = 0;///////////
        day = 1;
        month++;

        if (month == 13)
        {
            year++;
            month=1;
        }

        sec_in_month = (60*60*24*dniwmiesiacach[intercalar(year)][month]);
        actual_sec_in_month = (second + minute*60 + hour * 60 * 60 + (day-1) * 60 * 60 * 24);
    }

    unsigned int sec_in_day = 60*60*24;
    unsigned int actual_sec_in_day = second + minute * 60 + hour * 60 * 60;

    while(i >= (sec_in_day - actual_sec_in_day)) // dzien miesiaca nowej daty
    {
        i -= sec_in_day - actual_sec_in_day;
        second = 0;
        minute = 0;
        hour = 0;
        day++;
    }

    unsigned int sec_in_hour = 60*60;
    unsigned int actual_sec_in_hour = second + minute * 60;

    while(i >= (sec_in_hour - actual_sec_in_hour)) // godzina nowej daty
    {
        i -= sec_in_hour - actual_sec_in_hour;
        second = 0;
        minute = 0;
        hour++;
    }

    while(i >= 60 - second)
    {
        i-= 60 - second;
        second = 0;
        minute++;
    }

    second += i;
}

void DataGodz::operator-=(unsigned int i)
{
    unsigned int actual_sec_in_month = second + minute*60 + hour*60*60 + (day-1)*60*60*24;

    while( i >= actual_sec_in_month)
    {
        i -= actual_sec_in_month;
        month--;
        if(month == 0)
        {
            year--;
            month = 12;
        }
        second = 60;
        minute = 59;
        hour = 23;
        day = dniwmiesiacach[intercalar(year)][month];

        actual_sec_in_month = dniwmiesiacach[intercalar(year)][month]*60*60*24;
    }

    unsigned int actual_sec_in_day = second + minute*60 + hour*60*60;

    while (i > actual_sec_in_day)
    {
        i -= actual_sec_in_day;

        day--;
        second = 60;
        minute = 59;
        hour = 23;

        actual_sec_in_day = 24*60*60;
    }

    unsigned int actual_sec_in_hour = second + minute*60;

    while (i > actual_sec_in_hour)
    {
        i -= actual_sec_in_hour;

        hour--;
        minute = 59;
        second = 60;

        actual_sec_in_hour =  60*60;
    }

    while (i > second)
    {
        i-=second;

        minute--;
        second = 60;
    }

    second -= i;

}

bool DataGodz::operator< (const DataGodz &d) const
{
    if(get_year() > d.get_year())
            return false;
    else
        if(get_year() < d.get_year())
            return true;
    else
        if(get_month() > d.get_month())
            return false;
    else
        if(get_month() < d.get_month())
            return true;
    else
        if(get_day() > d.get_day())
        return false;
    else
        if(get_day() < d.get_day())
        return true;
    else
        if(get_hour() > d.get_hour())
        return false;
    else
        if(get_hour() < d.get_hour())
        return true;
    else
        if(get_minute() > d.get_minute())
        return false;
    else
        if(get_minute() < d.get_minute())
        return true;
    else
        if(get_second() > d.get_second())
        return false;
    else
        if(get_second() < d.get_second())
        return true;

    return false;
}

bool DataGodz::operator== (const DataGodz &d) const
{
    if((get_year() == d.get_year()) && (get_month() == d.get_month()) && (get_day() == d.get_day()) &&
        (get_hour() == d.get_hour()) && (get_minute() == d.get_minute()) && (get_second() == d.get_second()))
        return true;

    return false;
}
unsigned int operator-(const DataGodz &d1, const DataGodz &d2)
{
    unsigned int s = d2.get_second() - d1.get_second();
    unsigned int m = d2.get_minute() - d1.get_minute();
    unsigned int h = d2.get_hour() - d1.get_hour();
    unsigned int d = d2.operator-(d1);

    return abs(s + m*60 + h*60*60 + d*60*60*24);
}
