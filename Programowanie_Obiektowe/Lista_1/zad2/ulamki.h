#ifndef ulamki
#define ulamki

typedef struct
{
    int licznik;
    int mianownik;
}Ulamek;

void Change_sign(Ulamek* x);
Ulamek* Add_1(Ulamek* x, Ulamek* y);
void Add_2(Ulamek* x, Ulamek* y);
Ulamek* Multiply_1(Ulamek* x, Ulamek* y);
void Multiply_2(Ulamek* x, Ulamek* y);
Ulamek* Divide_1(Ulamek* x, Ulamek* y);
void Divide_2(Ulamek* x, Ulamek* y);
Ulamek* Substitution_1(Ulamek* x, Ulamek *y);
void Substitution_2(Ulamek* x, Ulamek* y);
int NWD(int a, int b);
void Skroc(Ulamek* a);

#endif // ulamki
