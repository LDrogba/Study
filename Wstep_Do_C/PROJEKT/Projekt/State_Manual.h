/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef Manual
#define Manual

#include "States.h"

extern State State_Manual;

int State_Manual_FnEnter( State* St );

int State_Manual_FnRun( State* St );

int State_Manual_FnExit( State* St );

int State_Manual_Create( State* St );

int State_Manual_Destroy( State* St );

#endif // Manual
