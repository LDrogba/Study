/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/


#ifndef Global
#define Global
#include "States.h"
#include <SDL.h>
#include "SDL_ttf.h"
#include <stdbool.h>
#include "room.h"
#include "maze_date.h"
#include "stdbool.h"

extern Cell g_Tab[NumCells][NumCells];
extern int gGlobalVar;
extern int gGlobalExit;
extern int gNewStateEnter;
extern bool gTab_event[512];
extern SDL_Surface* gWallSurfaces[ 5 ];

extern unsigned char* g_Maze;
extern State* gCurrentState;
extern State* gNextState;
//The window we'll be rendering to
extern SDL_Window* gWindow;
//The surface contained by the window
extern SDL_Surface* gScreenSurface;
extern SDL_Surface* Pusty;
//The images that correspond to a keypress
extern SDL_Surface* gCurrentSurface;
extern int Heading_X[ 9 ];
extern int Heading_Y[ 9 ];
extern int Mask[ 9 ];

extern TTF_Font* gFont_small;
extern TTF_Font* gFont_medium;
extern TTF_Font* gFont_big;


void Wypisz_tekst(const char* str, int x, int y, TTF_Font* font);
void Wypisz_liczbe(int nr, int x, int y, TTF_Font* font);

extern SDL_Color FgColor;

bool loadMedia();
bool Is_key_down();

void gTab_key_event_zeruj();
void Event_Handle();

#endif // Global
