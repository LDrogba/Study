/****************************/
/*
    Autor: Łukasz Wojdon
    Data: 5.02.2017
    Projekt: The Catacombs
*/
/****************************/

#include <string.h>
#include "SDL_ttf.h"
#include "Maze.h"
#include "SDL_window.h"
#include "Game.h"
#include "Global.h"
#include "player.h"
#include "game_date.h"
#include "MazeShow.h"
#include "State_Fight.h"
#include "State_HeroStats.h"
#include "State_Win.h"
#include "State_Manual.h"
#include "MainMenu.h"

State State_Game;

int State_Game_FnEnter( State* St )
{
    printf( "State_Game_FnEnter\n" );

    SDL_FillRect(gCurrentSurface, NULL, SDL_MapRGB(gCurrentSurface->format, 0, 0, 0));

    if(ifcreated == 1){
        return 1;
    }

    g_Maze = malloc( NumCells* NumCells );

    printf( "Generating %d x %d maze\n", NumCells, NumCells);
    srand( (unsigned int)time( NULL ) );

    memset( g_Maze, 0, NumCells*NumCells );

    g_PtX = RandomInt();
    g_PtY = RandomInt();

    GenerateMaze();

    CreateMaze();

    Hero.x = 0;
    Hero.y = 0;
    Hero.sword = 30;
    Hero.hp = 100;

    ifcreated = 1;

    return 1;
}

int State_Game_FnRun( State* St )
{
    int w,h,x=800,y=550;

    SDL_FillRect(gCurrentSurface, NULL, SDL_MapRGB(gCurrentSurface->format, 0, 0, 0));

    g_Tab[Hero.y][Hero.x].was_player = 1;

    Print_Maze();

    if(Is_key_down(SDLK_p)){
        if(Hero.potions > 0){
            Hero.hp +=30;
            Hero.potions --;
        }
    }
    if(g_Tab[Hero.y][Hero.x].exit)
       ChangeState(&State_Win);


    if(Is_key_down(SDLK_i))
        ChangeState( &State_HeroStats );

    if(Is_key_down(SDLK_ESCAPE))
        ChangeState( &State_MainMenu );

    if(Is_key_down(SDLK_LSHIFT) || Is_key_down(SDLK_RSHIFT))
        ChangeState (& State_Manual);

    if(Is_key_down(SDLK_DOWN)){
        if(!(g_Tab[Hero.y][Hero.x].door & (1<<1))){
            g_Tab[Hero.y][Hero.x].player = 0;
            g_Tab[Hero.y+1][Hero.x].player = 1;
            Hero.y += 1;
        }
    }

    if(Is_key_down(SDLK_UP)){
        if(!(g_Tab[Hero.y][Hero.x].door & (1<<3))){
            g_Tab[Hero.y][Hero.x].player = 0;
            g_Tab[Hero.y-1][Hero.x].player = 1;
            Hero.y -= 1;
        }
    }

    if(Is_key_down(SDLK_RIGHT)){
        if(!(g_Tab[Hero.y][Hero.x].door & (1<<2))){
            g_Tab[Hero.y][Hero.x].player = 0;
            g_Tab[Hero.y][Hero.x+1].player = 1;
            Hero.x += 1;
        }
    }

    if(Is_key_down(SDLK_LEFT)){
        if(!(g_Tab[Hero.y][Hero.x].door & (1<<0))){
            g_Tab[Hero.y][Hero.x].player = 0;
            g_Tab[Hero.y][Hero.x-1].player = 1;
            Hero.x -= 1;
        }
    }

        if(g_Tab[Hero.y][Hero.x].monster == 1){
            ChangeState(&State_Fight);
        }


        if(g_Tab[Hero.y][Hero.x].chest != NULL){

            if(g_Tab[Hero.y][Hero.x].chest->opened == 0)
                SDL_BlitSurface(chest_close_big, NULL, gCurrentSurface, NULL);

            if(Is_key_down(SDLK_o))
                g_Tab[Hero.y][Hero.x].chest->opened = 1;

            if(g_Tab[Hero.y][Hero.x].chest->opened == 1){
                if(Is_key_down(SDLK_q))
                    g_Tab[Hero.y][Hero.x].chest->opened = 0;
                else{

                    SDL_BlitSurface(chest_open_big, NULL, gCurrentSurface, NULL);

                    Wypisz_tekst("Found items: ",x, y, gFont_medium);
                    TTF_SizeText(gFont_medium, "Found items ", &w, &h);
                    y+=h;

                    if(g_Tab[Hero.y][Hero.x].chest->IsPotion){
                        Wypisz_tekst("Potions: 1 ", x, y, gFont_small);
                        TTF_SizeText(gFont_small, "Potions: 1", &w, &h);
                        y+=h;
                        if(Is_key_down(SDLK_c)){
                            Hero.potions++;
                            g_Tab[Hero.y][Hero.x].chest->IsPotion = 0;
                        }
                    }

                    if(g_Tab[Hero.y][Hero.x].chest->IsSward){
                        Wypisz_tekst("Sword with ", x, y, gFont_small);
                        TTF_SizeText(gFont_small,"Sword with ", &w, &h);
                        x+=w;

                        Wypisz_liczbe(g_Tab[Hero.y][Hero.x].chest->SwardPower, x ,y, gFont_small);
                        if(g_Tab[Hero.y][Hero.x].chest->SwardPower < 10)
                            TTF_SizeText(gFont_small, "0 " , &w, &h);
                        else
                            TTF_SizeText(gFont_small, "00 " , &w, &h);
                        x+=w;

                        Wypisz_tekst("power ", x, y, gFont_small);
                        if(Is_key_down(SDLK_r)){
                            int k = Hero.sword;
                            Hero.sword = g_Tab[Hero.y][Hero.x].chest->SwardPower;
                            g_Tab[Hero.y][Hero.x].chest->SwardPower = k;
                        }
                    }
                }
            }
        }

    return 1;
}

int State_Game_FnExit( State* St )
{
    printf( "State_Game_FnExit\n" );

    return 1;
}

int State_Game_Create( State* St )
{
    St->Enter = State_Game_FnEnter;
    St->Run = State_Game_FnRun;
    St->Exit = State_Game_FnExit;
    St->Destroy = State_Destroy;

    return 1;
}

int State_Game_Destroy( State* St )
{
    State_Destroy(St);
    // ....
    return 1;
}
