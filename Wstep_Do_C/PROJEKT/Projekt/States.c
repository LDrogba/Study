/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "States.h"
#include "Global.h"
#include <stdlib.h>
#include "State_Entry.h"
#include "State_Fight.h"
#include "State_GameOver.h"
#include "State_HeroStats.h"
#include "State_Manual.h"
#include "State_Win.h"
#include "Game.h"
#include "MainMenu.h"

int State_Destroy( State* St )
{
    free( St->Data );
    return 1;
}

int ChangeState( State* NewState )
{
    gNextState = NewState;
    return 1;
}

void InitStates()
{
    State_Menu_Create( &State_MainMenu );
    State_Game_Create( &State_Game );
    State_Fight_Create( &State_Fight );
    State_HeroStats_Create( &State_HeroStats );
    State_win_Create( &State_Win );
    State_GameOver_Create( &State_GameOver);
    State_Manual_Create( &State_Manual);
    State_Entry_Create( &State_Entry );
}

void DestroyStates()
{
    State_Destroy( &State_MainMenu );
    State_Destroy( &State_Game );
    State_Destroy( &State_Fight );
    State_Destroy( &State_HeroStats);
    State_Destroy( &State_Win);
    State_Destroy( &State_GameOver);
    State_Destroy( &State_Manual);
    State_Destroy( &State_Entry);
}
