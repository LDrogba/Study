/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdio.h>

#ifndef States
#define States

struct _State
{
    int( *Enter )(struct _State* St );
    int( *Run )(struct _State* St );
    int( *Exit )(struct _State* St );
    int( *Destroy )(struct _State* St );

    void* Data;
};

typedef struct _State State;

//////////////

int State_Destroy( State* St );

int ChangeState( State* NewState );

void InitStates();

void DestroyStates();

#endif
