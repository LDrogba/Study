/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef MainMenu
#define MainMenu

#include "SDL_ttf.h"
#include "States.h"

extern State State_MainMenu;

int State_Menu_FnEnter( State* St );

int State_Menu_FnRun( State* St );

int State_Menu_FnExit( State* St );

int State_Menu_Create( State* St );

int State_Menu_Destroy( State* St );

TTF_Font* gFont_MainMenu_title;
TTF_Font* gFont_MainMenu_options;


#endif // MainMenu

