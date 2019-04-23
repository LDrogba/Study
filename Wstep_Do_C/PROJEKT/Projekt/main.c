/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_keycode.h>
#include "Global.h"
#include "SDL_window.h"
#include "States.h"
#include "State_Entry.h"

int main(int argc, char* argv[])
{
    InitStates();
    initWindow();
    TTF_Init();
    loadMedia();

    ChangeState( &State_Entry );

    while(!gGlobalExit)
    {
        Event_Handle();

        if (gNextState!=NULL && gNextState!=gCurrentState)
        {
            if (gCurrentState!=NULL)
                gCurrentState->Exit( gCurrentState );

            gCurrentState = gNextState;
            gCurrentState->Enter( gCurrentState );
        }

        gCurrentState->Run( gCurrentState );

        SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }

    DestroyStates();
    TTF_Quit();
    SDL_Quit();
    return 0;
}

