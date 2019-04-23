/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdlib.h>
#include "State_Win.h"
#include "MazeShow.h"
#include "Global.h"
#include "game_date.h"
#include "MainMenu.h"

State State_Win;

int State_Win_FnEnter(State *St){

    SDL_FillRect(gCurrentSurface, NULL, 0);
    return 1;
}

int State_Win_FnRun(State *St){

    Wypisz_tekst(" You found exit!  ",0, 300, gFont_big);
    if(Is_key_down(SDLK_SPACE) || Is_key_down(SDLK_ESCAPE))
        ChangeState(&State_MainMenu);

    return 1;
}

int State_Win_FnExit(State *St){
    free(g_Maze);
    ClearTab();
    ifcreated = 0;
    return 1;
}

int State_win_Create(State *St){

    St->Enter = State_Win_FnEnter;
    St->Run = State_Win_FnRun;
    St->Exit = State_Win_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;

}

int State_win_Destroy(State *St){
    State_Destroy(St);

    return 1;
}
