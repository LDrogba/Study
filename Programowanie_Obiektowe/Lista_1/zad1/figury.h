#ifndef figury
#define figury

#define PI 3.14159265358979323846

typedef enum _Typfig
{
    trojkat,
    kolo,
    kwadrat
}Typfig;

typedef struct _Figura
{
    Typfig typ;
    float x; // x'owa
    float y;
    float sizes[5];
}Figura;

float Pole (Figura* f);
void Przesun(Figura *f, float x, float y);
float Sumapol (Figura* f[], int size);
Figura* Init_kwadrat(float x, float y, float a);
Figura* Init_kolo(float x, float y, float r);
Figura* Init_trojkat(float x, float y, float a, float h);


#endif // figury
