/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef Game
#define Game

#include "States.h"
#include "SDL_ttf.h"


extern State State_Game;

int State_Game_FnEnter( State* St );

int State_Game_FnRun( State* St );

int State_Game_FnExit( State* St );

int State_Game_Create( State* St );

void BornHero();

#endif
