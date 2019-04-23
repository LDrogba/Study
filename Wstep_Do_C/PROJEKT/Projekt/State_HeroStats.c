/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include "HeroStats.h"
#include "State_HeroStats.h"
#include "Global.h"
#include "MazeShow.h"
#include "player.h"
#include "HeroStats.h"
#include "MainMenu.h"
#include "Game.h"
#include "State_Manual.h"

State State_HeroStats;

int State_HeroStats_FnEnter(State *St ){
    printf("HeroStats enter\n");


    background_stat = Pusty;
    SDL_FillRect(background_stat, NULL, 0);


    SDL_SetSurfaceBlendMode( background_stat, SDL_BLENDMODE_BLEND );
    SDL_SetSurfaceAlphaMod( background_stat, 100);

    SDL_BlitSurface(background_stat, NULL, gCurrentSurface, NULL);

    SDL_BlitSurface(HeroStats_window, NULL, gCurrentSurface, NULL);

    Wypisz_bohatera();

    return 1;
}

int State_HeroStats_FnRun(State *St ){

    if(Is_key_down(SDLK_i) || Is_key_down(SDLK_ESCAPE))
        ChangeState(&State_Game);

    if(Is_key_down(SDLK_p)){
        if(Hero.potions > 0){
            Hero.hp +=30;
            Hero.potions--;
            SDL_BlitSurface(HeroStats_window, NULL, gCurrentSurface, NULL);
            Wypisz_bohatera();
        }
    }

    return 1;
}

int State_HeroStats_FnExit(State *St){
    printf("State_HeroStats exit\n");

    return 1;
}

int State_HeroStats_Create( State* St )
{
    St->Enter = State_HeroStats_FnEnter;
    St->Run = State_HeroStats_FnRun;
    St->Exit = State_HeroStats_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;
}

int State_HeroStats_Destroy( State* St )
{
    State_Destroy(St);
    // ....
    return 1;
}
