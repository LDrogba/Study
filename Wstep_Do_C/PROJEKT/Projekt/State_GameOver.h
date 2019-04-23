/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef GameOver
#define GameOver

#include "States.h"
#include <SDL.h>

extern State State_GameOver;

int State_GameOver_FnEnter( State* St );

int State_GameOver_FnRun( State* St );

int State_GameOver_FnExit( State* St );

int State_GameOver_Create( State* St );

int State_GameOver_Destroy( State* St );

SDL_Surface* gameover_bmp;


#endif // GameOver
