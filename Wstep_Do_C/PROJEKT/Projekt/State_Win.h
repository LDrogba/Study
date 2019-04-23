/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef Win
#define Win

#include "States.h"
#include "SDL_ttf.h"

extern State State_Win;

int State_Win_FnEnter( State* St );

int State_Win_FnRun( State* St );

int State_Win_FnExit( State* St );

int State_win_Create( State* St );

int State_win_Destroy( State* St );

TTF_Font* gFont_Win;


#endif // Win

