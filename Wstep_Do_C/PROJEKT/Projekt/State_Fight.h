/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef Fight
#define Fight

#include "States.h"

extern State State_Fight;

int State_Fight_FnEnter( State* St );

int State_Fight_FnRun( State* St );

int State_Fight_FnExit( State* St );

int State_Fight_Create( State* St );

int State_Fight_Destroy( State* St );



#endif // Fight

