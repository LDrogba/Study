#ifndef Data_hpp
#define Data_hpp

class Data
{
public:
    Data(unsigned int day, unsigned int month, unsigned int year);
    Data();
    unsigned int get_day() const;
    unsigned int get_month() const;
    unsigned int get_year() const;
    virtual unsigned int operator- (const Data &d) const;
    void operator++ ();
    void operator-- ();
    void operator+= (unsigned int i);
    void operator-= (unsigned int i);
    static unsigned int dniwmiesiacach[2][13];
    static unsigned int dniodpoczroku[2][13];


protected:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int day_count(const Data &d) const;
    bool intercalar( unsigned int year) const;
    bool Data_correct(unsigned int day, unsigned int month, unsigned int year);

};

#endif // Data_hpp
