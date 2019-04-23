/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <SDL.h>
#include "State_Entry.h"
#include "Global.h"
#include "MainMenu.h"
#include "SDL_window.h"
#include "windows.h"
State State_Entry;

int State_Entry_FnEnter(State *St){

    gCurrentSurface = loadSurface("../../../Bitmapy/entry.bmp");

    return 1;
}

int State_Entry_FnRun(State *St){
    Wypisz_tekst("PRESS SPACE", 420, 600, gFont_medium);
    if(Is_key_down(SDLK_SPACE))
        ChangeState( &State_MainMenu);

    return 1;
}

int State_Entry_FnExit(State *St){

    return 1;
}

int State_Entry_Create(State* St){

    St->Enter = State_Entry_FnEnter;
    St->Run = State_Entry_FnRun;
    St->Exit = State_Entry_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;
}

int State_Entry_Destroy(State* St){

    State_Destroy( St);

    return 1;
}
