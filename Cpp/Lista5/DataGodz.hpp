#ifndef DataGodz_hpp
#define DataGodz_hpp

#include "Data.hpp"

class DataGodz final : public Data
{
public:
    unsigned int get_hour() const;
    unsigned int get_minute() const ;
    unsigned int get_second() const ;

    DataGodz(unsigned int day, unsigned int month = 1, unsigned int year = 0,
             unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);
    DataGodz();
    void operator++ ();
    void operator-- ();
    void operator+= (unsigned int i);
    void operator-= (unsigned int i);
    bool operator< (const DataGodz &d) const;
    bool operator== (const DataGodz &d) const;
    friend unsigned int operator- (const DataGodz &d1, const DataGodz &d2);

private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    bool Time_correct(unsigned int s, unsigned int m, unsigned int h);
};

unsigned int operator- (const DataGodz &d1, const DataGodz &d2);

#endif // DataGodz_hpp
