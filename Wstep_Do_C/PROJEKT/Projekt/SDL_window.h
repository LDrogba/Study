/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "Global.h"
#ifndef Window
#define Window

#include <SDL.h>
#include <stdbool.h>

SDL_Surface* loadSurface(const char* str);
bool loadFromRenderedText( const char* textureText, SDL_Color textColor );
bool initWindow();



#endif // SDL_Window
