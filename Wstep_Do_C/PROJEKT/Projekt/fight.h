/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#ifndef state_fight
#define state_fight

#include "SDL_ttf.h"
#include <SDL.h>
#include <time.h>
#include <math.h>

typedef struct _sword{
    int x;
    int y;
    int direction;
    double speed;
}sword_pos;

sword_pos sword;

SDL_Rect s_health;

SDL_Surface* fight_surface;
SDL_Surface* fight_skel;
SDL_Surface* fight_sword;
SDL_Surface* fight_scelt_head;
SDL_Surface* fight_bone;
SDL_Surface* fight_skelt_hp;
SDL_Surface* fight_skelt_hp_minus;

extern TTF_Font* gFont_Fight;

clock_t start_time;

#endif // state_fight
