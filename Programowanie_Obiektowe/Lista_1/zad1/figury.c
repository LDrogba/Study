#include "figury.h"
#include <stdlib.h>
#include <math.h>

float Pole (Figura* f){
    switch (f->typ)
    {
        case trojkat:
            return (f->sizes[0] * f->sizes[1] / 2);
            break;
        case kolo:
            return (( f->sizes[0] * f->sizes[0] * PI));
            break;
        case kwadrat:
            return ( f->sizes[0] * f->sizes[0] );
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

float Sumapol (Figura* f[], int size)
{
    float suma = 0;
    for(int i = 0; i < size; i++){
        suma += Pole(f[i]);
    }
    return suma;
}

Figura* Init_kwadrat(float x, float y, float a)
{
    if(a < 0)
        return NULL;

    Figura* k = malloc(sizeof(Figura));
    k->sizes[0] = a;
    k->typ = kwadrat;
    k->x = x;
    k->y = y;

    return k;
}

Figura* Init_kolo(float x, float y, float r)
{
    if(r < 0)
        return NULL;

    Figura* k = malloc(sizeof(Figura));
    k->sizes[0] = r;
    k->typ = kolo;
    k->x = x;
    k->y = y;

    return k;
}

Figura* Init_trojkat(float x, float y, float a, float h)
{
    if(a < 0 || h < 0)
        return NULL;

    Figura* k = malloc(sizeof(Figura));
    k->sizes[0] = a;
    k->sizes[1] = h;
    k->typ = trojkat;
    k->x = x;
    k->y = y;

    return k;
}
