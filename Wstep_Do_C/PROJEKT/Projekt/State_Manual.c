/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "State_Manual.h"
#include "SDL.h"
#include "Global.h"

#include "MainMenu.h"
#include "Game.h"

State State_Manual;

int State_Manual_FnEnter(State* St){

    SDL_FillRect(gCurrentSurface, NULL, 0);
    int w,h;
    int x = 400;
    int y = 100;

    Wypisz_tekst("MANUAL", x, y, gFont_big);

    x=200;
    y=300;

    Wypisz_tekst("arrows - move", x, y, gFont_small);
    TTF_SizeText(gFont_small, "move - arrows", &w, &h);
    y+=h+5;

    Wypisz_tekst("' o ' - Open chest", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Open chest - 'o' ", &w, &h);
    y+=h+5;

    Wypisz_tekst("' r ' - Take sword from chest ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Take sword from chest - 'r' ", &w, &h);
    y+=h+5;

    Wypisz_tekst("' c ' - Take potion from chest ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Take potion from chest - 'c' ", &w, &h);
    y+=h+5;

    Wypisz_tekst("' p ' - Use potion", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Use potion - 'p' ", &w, &h);
    y+=h+5;

    Wypisz_tekst("' i ' - Show/close hero stats ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "Show/close hero stats - 'i' ", &w, &h);
    y+=h+5;

    Wypisz_tekst("' SPACE ' - Press while sword is on ", x, y, gFont_small);
    TTF_SizeText(gFont_small, "' SPACE ' - press while sword is on", &w, &h);
    y+=h;
    TTF_SizeText(gFont_small, "' SPACE ' - ", &w, &h);
    x+=w;

    Wypisz_tekst("the red space (fight) ", x, y, gFont_small);
    TTF_SizeText(gFont_small, " the red space while fightig", &w, &h);
    y+=h+5;


    x = 200;

    Wypisz_tekst("' shift ' - Back to game/Manual", x, y, gFont_small);
    TTF_SizeText(gFont_small, " ' shift ' - Back to game", &w, &h);
    y+=h+5;

    Wypisz_tekst("ESCAPE - Back to main menu ", x, y, gFont_small);
    return 1;
}


int State_Manual_FnRun(State* St){

    if(Is_key_down(SDLK_ESCAPE))
        ChangeState(&State_MainMenu);
    if(Is_key_down(SDLK_LSHIFT) || Is_key_down(SDLK_RSHIFT))
        ChangeState(&State_Game);
    return 1;
}

int State_Manual_FnExit(State *St){

    return 1;
}

int State_Manual_Create(State* St){

    St->Enter = State_Manual_FnEnter;
    St->Run = State_Manual_FnRun;
    St->Exit = State_Manual_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;
}
