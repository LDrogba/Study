/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef Entry
#define Entry

#include "States.h"
#include "SDL_ttf.h"

extern State State_Entry;

int State_Entry_FnEnter( State* St );

int State_Entry_FnRun( State* St );

int State_Entry_FnExit( State* St );

int State_Entry_Create( State* St );

int State_Entry_Destroy( State* St );

#endif
