#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    float w;
    float h;
}Figura;

float Pole (Figura* f){
    switch (f->typ)
    {
        case trojkat:
            printf("%f %f \n", f->w, f->h);
            float pole = ( f->w * f->h ) / 2;
            return pole;
            break;
        case kolo:
            return (( f->h * f->h * PI));
            break;
        case kwadrat:
            return ( f->h * f->h );
            break;
        default:
            return 0;
    }
}

void Przesun(Figura *f, float x, float y)
{
    f->x += x;
    f->y += y;
}



int main()
{
    //printf ("%d %d %d", trojkat, kolo, kwadrat);
    Figura x;
    x.typ = kwadrat;
    x.h = 5;

    printf("%f", Pole(&x));
}
