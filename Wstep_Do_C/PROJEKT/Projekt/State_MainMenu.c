/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "MainMenu.h"
#include "SDL_window.h"
#include "Global.h"
#include "fight.h"

#include "State_Manual.h"
#include "Game.h"

State State_MainMenu;

int State_Menu_FnEnter( State* St )
{
    gCurrentSurface = loadSurface("../../../Bitmapy/menu_skelts.bmp");
    Wypisz_tekst("Main Menu", 450, 100, gFont_medium);
    Wypisz_tekst("SPACE - Start Game", 420, 350, gFont_small);
    Wypisz_tekst("ESCAPE - Exit", 420, 400, gFont_small);
    Wypisz_tekst("SHIFT - Manual", 420, 450, gFont_small);

    printf("State_Menu_FnEnter\n");
    return 1;
}

int State_Menu_FnRun( State* St )
{
    if(Is_key_down(SDLK_SPACE))
        ChangeState(&State_Game);
    if(Is_key_down(SDLK_ESCAPE))
        gGlobalExit = 1;
    if(Is_key_down(SDLK_LSHIFT) || Is_key_down(SDLK_RSHIFT))
        ChangeState(&State_Manual);
    return 1;
}

int State_Menu_FnExit( State* St )
{
    printf( "State_Menu_FnExit\n" );
    return 1;
}

int State_Menu_Create( State* St )
{
    St->Enter = State_Menu_FnEnter;
    St->Run = State_Menu_FnRun;
    St->Exit = State_Menu_FnExit;
    St->Destroy = State_Destroy;

    return 1;
}

int State_Menu_Destroy( State* St )
{
    State_Destroy(St);
    // ....
    return 1;
}
