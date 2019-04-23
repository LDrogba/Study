/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "SDL_window.h"
#include "stdbool.h"
#include <SDL.h>
#include <stdio.h>
#include <string.h>
bool initWindow()
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;

    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //create Window
        gWindow = SDL_CreateWindow( "The Catacombs", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    }

    if( gWindow == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //get window surface
        gScreenSurface = SDL_GetWindowSurface(gWindow);
        }

    return success;
}


