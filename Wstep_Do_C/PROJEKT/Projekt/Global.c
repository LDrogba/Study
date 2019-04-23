/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <stdlib.h>
#include "MazeShow.h"
#include "maze_date.h"
#include "room.h"
#include "game_date.h"
#include "Global.h"
#include "fight.h"
#include "HeroStats.h"
#include "State_GameOver.h"
#include "SDL_ttf.h"

int k;
int gGlobalVar;
int gGlobalExit = 0;
int gNewStateEnter = 1;

Cell g_Tab[NumCells][NumCells];

bool gTab_key_event[512];

void gTab_key_event_zeruj()
{
    for(int i=0; i<512; i++){
        gTab_key_event[i] = 0;
    }
}

unsigned char* g_Maze = NULL;
State* gCurrentState = NULL;
State* gNextState = NULL;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The images that correspond to a keypress
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gWallSurfaces[ 5 ];
SDL_Surface* gTextSurface = NULL;
SDL_Surface* Pusty = NULL;

TTF_Font* gFont_medium = NULL;
TTF_Font* gFont_small = NULL;
TTF_Font* gFont_big = NULL;


SDL_Color FgColor = {255,255,255,0};
SDL_Color BgColor = {0,0,0,0};


void Event_Handle(){

    SDL_Event event;

    gTab_key_event_zeruj();

    while(SDL_PollEvent(&event) != 0){

        if(event.type == SDL_QUIT)
            gGlobalExit = 1;

        if (event.type == SDL_KEYDOWN)
            gTab_key_event[event.key.keysym.sym &511] = 1;

    }
}


bool Is_key_down( SDL_Keycode Key){
    if(gTab_key_event[Key &511] == 1)
        return 1;
    else
        return 0;
}

void Wypisz_tekst(const char* str, int x, int y, TTF_Font* font){

    SDL_Surface* text;

    SDL_Rect r;
    r.x = x;
    r.y = y;;

    text = TTF_RenderText_Blended(font, str , FgColor);

    if(text==NULL)
        printf("nie dziala render\n");

    SDL_BlitSurface(text, NULL, gCurrentSurface, &r);
}

void Wypisz_liczbe(int nr, int x, int y, TTF_Font* font){

    SDL_Surface* num;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    char textBuffer[4];

    sprintf(textBuffer, "%d", nr);

    num = TTF_RenderText_Blended(font, textBuffer , FgColor);

    SDL_BlitSurface(num, NULL, gCurrentSurface, &r);

}

SDL_Surface* loadSurface(const char* str)
{
     SDL_Surface* loadedSurface = SDL_LoadBMP( str );
     if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", str, SDL_GetError() );
     }
     return loadedSurface;
}


bool loadMedia(){

    bool success = true;

    gWallSurfaces[ up ] = loadSurface( "../../../Bitmapy/u_wall.bmp" );
    if( gWallSurfaces[ up ] == NULL ) {
        printf( "Failed to load Up Wall image!\n" );
        return false;
    }
    //Load up surface
    gWallSurfaces[ down ] = loadSurface( "../../../Bitmapy/d_wall.bmp" );
    if( gWallSurfaces[ down ] == NULL ) {
        printf( "Failed to load Down Wall image!\n" );
        return false;
    }

    //Load down surface
    gWallSurfaces[ left ] = loadSurface( "../../../Bitmapy/l_wall.bmp" );
    if( gWallSurfaces[ left ] == NULL ) {
        printf( "Failed to load Left Wall image!\n" );
        return false;
    }

    //Load right surface
    gWallSurfaces[ right ] = loadSurface( "../../../Bitmapy/r_wall.bmp" );
    if( gWallSurfaces[ right ] == NULL ) {
        printf( "Failed to load Right Wall image!\n" );
        return false;
    }

    gWallSurfaces[ base ] = loadSurface( "../../../Bitmapy/base.bmp");
    if( gWallSurfaces[ base ] == NULL){
        printf( "Failed to load BASE\n");
        return false;
    }

    for(int i=0; i<5; i++)
        SDL_SetColorKey(gWallSurfaces[i], SDL_TRUE, SDL_MapRGB( gWallSurfaces[i]->format, 0xFF, 0, 0xFF));

    chest = loadSurface( "../../../Bitmapy/chest.bmp");
    SDL_SetColorKey(chest, SDL_TRUE, SDL_MapRGB(chest->format, 0xFF, 0, 0xFF));

    skelt = loadSurface( "../../../Bitmapy/skelt.bmp");
    SDL_SetColorKey(skelt, SDL_TRUE, SDL_MapRGB(skelt->format, 0xFF, 0, 0xFF));

    hero_bmp = loadSurface( "../../../Bitmapy/hero.bmp");
    SDL_SetColorKey(hero_bmp, SDL_TRUE, SDL_MapRGB(hero_bmp->format, 0xFF, 0, 0xFF));

    chest_open = loadSurface( "../../../Bitmapy/chest_open.bmp");
    SDL_SetColorKey(chest_open, SDL_TRUE, SDL_MapRGB(chest_open->format, 0xFF, 0, 0xFF));

    chest_open_big = loadSurface( "../../../Bitmapy/chest_open2_big.bmp");
    SDL_SetColorKey(chest_open_big, SDL_TRUE, SDL_MapRGB(chest_open_big->format, 0xFF, 0, 0xFF));

    chest_close_big = loadSurface( "../../../Bitmapy/chest_close_big.bmp");
    SDL_SetColorKey(chest_close_big, SDL_TRUE, SDL_MapRGB(chest_close_big->format, 0xFF, 0, 0xFF));

    clear_text = loadSurface("../../../Bitmapy/clear_text.bmp");
    SDL_SetColorKey(clear_text, SDL_TRUE, SDL_MapRGB(clear_text->format, 0xFF, 0, 0xFF));

    fight_skel = loadSurface("../../../Bitmapy/fight_skelt.bmp");
    SDL_SetColorKey(fight_skel, SDL_TRUE, SDL_MapRGB(fight_skel->format, 0x99, 0x33, 0));

    fight_sword = loadSurface("../../../Bitmapy/fight_sword.bmp");
    SDL_SetColorKey(fight_sword, SDL_TRUE, SDL_MapRGB(fight_sword->format, 0xFF, 0, 0xFF));

    fight_bone = loadSurface(("../../../Bitmapy/fight_bone_pre.bmp"));
    SDL_SetColorKey(fight_bone, SDL_TRUE, SDL_MapRGB(fight_bone->format, 0xFF, 0, 0xFF));

    fight_skelt_hp = loadSurface(("../../../Bitmapy/fight_skelt_hp.bmp"));
    SDL_SetColorKey(fight_skelt_hp, SDL_TRUE, SDL_MapRGB(fight_skelt_hp->format, 0xFF, 0, 0xFF));

    fight_skelt_hp_minus = loadSurface(("../../../Bitmapy/fight_skelt_hp_minus.bmp"));
    SDL_SetColorKey(fight_skelt_hp_minus, SDL_TRUE, SDL_MapRGB(fight_skelt_hp_minus->format, 0xFF, 0, 0xFF));

    HeroStats_window = loadSurface(("../../../Bitmapy/game_hero_stats.bmp"));
    SDL_SetColorKey(HeroStats_window, SDL_TRUE, SDL_MapRGB(HeroStats_window->format, 0xFF, 0, 0xFF));

    Pusty = loadSurface(("../../../Bitmapy/pusty.bmp"));
    SDL_SetColorKey(Pusty, SDL_TRUE, SDL_MapRGB(Pusty->format, 0xFF, 0, 0xFF));

    game_exit = loadSurface(("../../../Bitmapy/exit.bmp"));
    SDL_SetColorKey(game_exit, SDL_TRUE, SDL_MapRGB(game_exit->format, 0xFF, 0, 0xFF));

    gameover_bmp = loadSurface(("../../../Bitmapy/game_over.bmp"));
    SDL_SetColorKey(gameover_bmp, SDL_TRUE, SDL_MapRGB(gameover_bmp->format, 0xFF, 0, 0xFF));

    torches = loadSurface("../../../Bitmapy/fire.bmp");
    SDL_SetColorKey(torches, SDL_TRUE, SDL_MapRGB(torches->format, 0xFF, 0, 0xFF));

    printf("ladowanie ttf\n");

    gFont_small = TTF_OpenFont("../../../Font/X-Files.ttf", 30);
    gFont_medium = TTF_OpenFont("../../../Font/X-Files.ttf", 50);
    gFont_big = TTF_OpenFont("../../../Font/X-Files.ttf", 100);

return success;
}





