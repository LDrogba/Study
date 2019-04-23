/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "HeroStats.h"
#include "player.h"
#include "Global.h"

void Wypisz_bohatera(){

    int h=0,w=0,x,y;

    x=530;
    y=130;

    Wypisz_tekst("HERO", x, y, gFont_medium);
    TTF_SizeText(gFont_medium, "HERO", &w, &h);

    x=450;
    y=240;
    Wypisz_tekst("Health: ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Health: ", &w, &h);

    x+=w;
    Wypisz_liczbe(Hero.hp, x, y, gFont_small);
    TTF_SizeText(gFont_small, "100", &w, &h);

    x=450;
    y+=h+10;
    Wypisz_tekst("Sword: ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Sword: ", &w, &h);

    x+=w;
    Wypisz_liczbe(Hero.sword,x, y, gFont_small);
    TTF_SizeText(gFont_small, "50", &w, &h);

    x=450;
    y+=h+10;
    Wypisz_tekst("Potions: ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Potions: ", &w, &h);

    x+=w;
    Wypisz_liczbe(Hero.potions, x, y, gFont_small);
    TTF_SizeText(gFont_small, "50", &w, &h);

}
