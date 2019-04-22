#include "Operatory.hpp"
#include <cmath>

Operator1arg::Operator1arg(Wyrazenie *w)
    :wyr1(w)
{
    prior = 10;
}

Operator2arg::Operator2arg(Wyrazenie *w1, Wyrazenie *w2)
    :Operator1arg(w1)
    ,wyr2(w2)
{
    prior = 1;
}

Operator1arg::~Operator1arg()
{
    delete wyr1;
}

Operator2arg::~Operator2arg()
{
    delete wyr2;
}

Op_bezwzgl::Op_bezwzgl(Wyrazenie *w)
    :Operator1arg(w)
{

}

double Op_bezwzgl::Oblicz()
{
    double tmp = wyr1->Oblicz();
    if(tmp<0)
        return tmp*(-1);
    else
        return tmp;
}

std::string Op_bezwzgl::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "|";
    ret_str += wyr_str;
    ret_str += "|";

    return ret_str;
}

Op_cos::Op_cos(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_cos::Oblicz()
{
    return cos(wyr1->Oblicz());
}

std::string Op_cos::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "cos(";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

Op_sin::Op_sin(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_sin::Oblicz()
{
    return sin(wyr1->Oblicz());
}

std::string Op_sin::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "sin(";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

Op_przeciw::Op_przeciw(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_przeciw::Oblicz()
{
    return wyr1->Oblicz()*(-1);
}

std::string Op_przeciw::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "(- ";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

Op_ln::Op_ln(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_ln::Oblicz()
{
    return log(wyr1->Oblicz());
}

std::string Op_ln::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "ln(";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

Op_exp::Op_exp(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_exp::Oblicz()
{
    return exp(wyr1->Oblicz());
}

std::string Op_exp::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "(e^";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

Op_odwrot::Op_odwrot(Wyrazenie *w)
    :Operator1arg(w)
{
}

double Op_odwrot::Oblicz()
{
    return 1/(wyr1->Oblicz());
}

std::string Op_odwrot::Opis()
{
    std::string wyr_str = wyr1->Opis();
    std::string ret_str = "(1/";
    ret_str += wyr_str;
    ret_str += ")";

    return ret_str;
}

//--------- DWUARGUMENTOWE -----------------

Op_dodaj::Op_dodaj(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
}

double Op_dodaj::Oblicz()
{
    return wyr1->Oblicz() + wyr2->Oblicz();
}

std::string Op_dodaj::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";

    ret_str += wyr1_str;
    ret_str += "+";
    ret_str += wyr2_str;

    return ret_str;
}

Op_odejmij::Op_odejmij(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
}

double Op_odejmij::Oblicz()
{
    return wyr1->Oblicz() - wyr2->Oblicz();
}

std::string Op_odejmij::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";
    int p_w2 = (wyr2->prior);

    ret_str += wyr1_str;

    ret_str += "-";

    if(p_w2 <= prior){
        ret_str += "(";
        ret_str += wyr2_str;
        ret_str += ")";
    }
    else
    ret_str += wyr2_str;

    return ret_str;
}

Op_mnoz::Op_mnoz(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
    prior = 3;
}

double Op_mnoz::Oblicz()
{
    return wyr1->Oblicz() * wyr2->Oblicz();
}

std::string Op_mnoz::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";
    int p_w1 = (wyr1->prior);
    int p_w2 = (wyr2->prior);

    if(p_w1 < prior){
        ret_str += "(";
        ret_str += wyr1_str;
        ret_str += ")";
    }
    else
        ret_str += wyr1_str;

    ret_str += "*";

    if(p_w2 < prior){
        ret_str += "(";
        ret_str += wyr2_str;
        ret_str += ")";
    }
    else
    ret_str += wyr2_str;

    return ret_str;
}

Op_dziel::Op_dziel(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
    prior = 3;
}

double Op_dziel::Oblicz()
{
    return wyr1->Oblicz() / wyr2->Oblicz();
}

std::string Op_dziel::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";
    int p_w1 = (wyr1->prior);
    int p_w2 = (wyr2->prior);

    if(p_w1 < prior){
        ret_str += "(";
        ret_str += wyr1_str;
        ret_str += ")";
    }
    else
        ret_str += wyr1_str;

    ret_str += "/";

    if(p_w2 < prior){
        ret_str += "(";
        ret_str += wyr2_str;
        ret_str += ")";
    }
    else
    ret_str += wyr2_str;
    return ret_str;
}

Op_potega::Op_potega(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
    prior = 4;
}

double Op_potega::Oblicz()
{
    return pow(wyr1->Oblicz(), wyr2->Oblicz());
}

std::string Op_potega::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";
    int p_w1 = (wyr1->prior);
    int p_w2 = (wyr2->prior);

    if(p_w1 < prior){
        ret_str += "(";
        ret_str += wyr1_str;
        ret_str += ")";
    }
    else
        ret_str += wyr1_str;

    ret_str += "^";

    if(p_w2 < prior){
        ret_str += "(";
        ret_str += wyr2_str;
        ret_str += ")";
    }
    else
    ret_str += wyr2_str;
    return ret_str;
}

Op_logarytm::Op_logarytm(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
    prior = 1;
}

double Op_logarytm::Oblicz()
{
    return log(wyr1->Oblicz()) / log(wyr2->Oblicz());
}

std::string Op_logarytm::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "log_";

    ret_str += wyr1_str;
    ret_str += "_";
    ret_str += wyr2_str;
    return ret_str;
}

Op_modulo::Op_modulo(Wyrazenie *w1, Wyrazenie *w2)
    :Operator2arg(w1, w2)
{
    prior = 1;
}

double Op_modulo::Oblicz()
{
    int calkowite = wyr1->Oblicz()/wyr2->Oblicz();
    return wyr1->Oblicz() - calkowite*wyr2->Oblicz();
}

std::string Op_modulo::Opis()
{
    std::string wyr1_str = wyr1->Opis();
    std::string wyr2_str = wyr2->Opis();
    std::string ret_str = "";
    int p_w1 = (wyr1->prior);
    int p_w2 = (wyr2->prior);

    if(p_w1 < prior){
        ret_str += "(";
        ret_str += wyr1_str;
        ret_str += ")";
    }
    else
        ret_str += wyr1_str;

    ret_str += "%";

    if(p_w2 < prior){
        ret_str += "(";
        ret_str += wyr2_str;
        ret_str += ")";
    }
    else
    ret_str += wyr2_str;
    return ret_str;
}
