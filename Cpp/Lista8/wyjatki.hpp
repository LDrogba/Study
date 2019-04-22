#ifndef Wyjatki_hpp
#define Wyjatki_hpp

#include <exception>

class Wyjatek_Wymierny : std::exception{
public:
    const char *exp() const throw(){
        return "exception";
    }
};

class Dzielenie_przez_0 : Wyjatek_Wymierny{
public:
    const char *exp() const throw(){
        return "dzielenie przez 0";
    }
};

class Przekroczono_zakres_int : Wyjatek_Wymierny{
public:
    const char *exp() const throw(){
        return "zakres int'a przekroczony";
    }
};

#endif // Wyjatki_hpp
