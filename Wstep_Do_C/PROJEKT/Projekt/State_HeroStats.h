/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef HeroStats
#define HeroStats

#include "States.h"

extern State State_HeroStats;

int State_HeroStats_FnEnter( State* St );

int State_HeroStats_FnRun( State* St );

int State_HeroStats_FnExit( State* St );

int State_HeroStats_Create( State* St );

int State_HeroStats_Destroy( State* St );



#endif // Fight

