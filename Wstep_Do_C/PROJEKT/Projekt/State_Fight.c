/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <time.h>
#include <stdlib.h>
#include "State_Fight.h"
#include "fight.h"
#include "Global.h"
#include "monster.h"
#include "player.h"
#include "windows.h"
#include "MainMenu.h"
#include "State_GameOver.h"
#include "Game.h"
#include "State_Manual.h"
#include "MazeShow.h"

State State_Fight;

int State_Fight_FnEnter(State* St){

    int h,w;

    srand(time(0));

    skeleton = (Skeleton_str*)malloc(sizeof(Skeleton_str));

    skeleton->hp = 99;
    skeleton->pow = rand()%30;

    s_health.x = 650;
    s_health.y = 0;

    start_time = clock();

    SDL_FillRect(gCurrentSurface, NULL, 0);

    SDL_BlitSurface(fight_skel, NULL, gCurrentSurface, NULL);

    Wypisz_liczbe(skeleton->hp, 510, 10, gFont_small);

    SDL_BlitSurface(fight_skelt_hp, NULL, gCurrentSurface, NULL );

    SDL_BlitSurface(fight_skelt_hp_minus, NULL, gCurrentSurface, &s_health);

    Wypisz_tekst("Hero HP: ", 510, 700, gFont_small);
    TTF_SizeText(gFont_small, "Hero HP: ", &w, &h);

    Wypisz_liczbe(Hero.hp, 510+w, 700, gFont_small);

    return 1;
}


int State_Fight_FnRun(State* St){


    if(Is_key_down(SDLK_ESCAPE))
        ChangeState( &State_MainMenu);
    if(Is_key_down(SDLK_LSHIFT) || Is_key_down(SDLK_RSHIFT))
        ChangeState( &State_Manual);

    int w,h;
    SDL_Rect r;

    time_t delta = difftime(clock(), start_time);

    r.x = 380 + (800-380)/2 + sin(delta/1300.0) * (800-380)/2;
    r.y = 500;

    if(Is_key_down(SDLK_SPACE)){
        if(r.x <= 636 && r.x >= 536 ){
            skeleton->hp -= Hero.sword;
            s_health.x -= Hero.sword;
            if(skeleton->hp <= 0){
                g_Tab[Hero.y][Hero.x].monster = 0;
                free(skeleton);
                ChangeState(&State_Game);
            }
        }
        else{
            Hero.hp -= rand()%10+15;
            if(Hero.hp <= 0)
                ChangeState( &State_GameOver);
        }

        SDL_FillRect(gCurrentSurface, NULL, 0);

        SDL_BlitSurface(fight_skel, NULL, gCurrentSurface, NULL);

        Wypisz_liczbe(skeleton->hp, 510, 10, gFont_small);

        SDL_BlitSurface(fight_skelt_hp, NULL, gCurrentSurface, NULL );

        SDL_BlitSurface(fight_skelt_hp_minus, NULL, gCurrentSurface, &s_health);

        Wypisz_tekst("Hero HP: ", 510, 700, gFont_small);
        TTF_SizeText(gFont_small, "Hero HP: ", &w, &h);

        Wypisz_liczbe(Hero.hp, 510+w, 700, gFont_small);

    }

    SDL_BlitSurface(fight_bone, NULL, gCurrentSurface, NULL);

    SDL_BlitSurface(fight_sword, NULL, gCurrentSurface, &r);

    return 1;
}

int State_Fight_FnExit(State* St){
    printf("zmiana stanu na game\n");
    Print_Maze();

    return 1;
}

int State_Fight_Create( State* St )
{
    St->Enter = State_Fight_FnEnter;
    St->Run = State_Fight_FnRun;
    St->Exit = State_Fight_FnExit;
    St->Destroy = State_Destroy;
    St->Data = NULL;

    return 1;
}

int State_Fight_Destroy( State* St )
{
    State_Destroy(St);
    return 1;
}
