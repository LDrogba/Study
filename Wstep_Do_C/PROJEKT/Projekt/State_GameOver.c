/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "State_GameOver.h"
#include "Global.h"
#include "game_date.h"
#include "stdlib.h"
#include "MainMenu.h"
#include "MazeShow.h"

State State_GameOver;

int State_GameOver_FnEnter(State* St){

    SDL_BlitSurface(gameover_bmp, NULL, gCurrentSurface, NULL);
    Wypisz_tekst("GAME OVER", 300, 700, gFont_big);

    return 1;
}


int State_GameOver_FnRun(State* St){

    if( Is_key_down(SDLK_SPACE) || Is_key_down(SDLK_ESCAPE) || Is_key_down(SDLK_RETURN))
        ChangeState(&State_MainMenu);

    return 1;
}

int State_GameOver_FnExit(State* St){
    free(g_Maze);
    ClearTab();
    ifcreated = 0;

    return 1;
}

int State_GameOver_Create(State* St){
    St->Enter = State_GameOver_FnEnter;
    St->Run = State_GameOver_FnRun;
    St->Exit = State_GameOver_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;
}

int State_GameOver_Destroy(State *St){
    State_Destroy(St);

    return 1;
}
