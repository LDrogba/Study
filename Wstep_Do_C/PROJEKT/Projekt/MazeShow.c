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
#include "player.h"
#include "Global.h"

void Print_Maze(){
    Cell tmp;

    SDL_Rect h;
    h.x=Hero.x*80+70;
    h.y=Hero.y*80+70;

    SDL_Surface* shade;
    shade = Pusty;

	for(int i=0; i<NumCells; i++){
		for(int j=0; j<NumCells; j++){

            SDL_Rect r;
            r.x=j*80 + 70;
            r.y=i*80 + 70;
            tmp = g_Tab[i][j];

            if(tmp.was_player){
                SDL_BlitSurface(gWallSurfaces[base], NULL, gCurrentSurface, &r);


            for(int k=0; k<4; k++){
                if(tmp.door&(1<<k)){
                    if(k == 0)
                        SDL_BlitSurface(gWallSurfaces[left], NULL, gCurrentSurface, &r);
                    if(k == 1)
                        SDL_BlitSurface(gWallSurfaces[down], NULL, gCurrentSurface, &r);
                    if(k == 2)
                        SDL_BlitSurface(gWallSurfaces[right], NULL, gCurrentSurface, &r);
                    if(k == 3)
                        SDL_BlitSurface(gWallSurfaces[up], NULL, gCurrentSurface, &r);
                }
            }


                if(tmp.chest != NULL){
                    if(tmp.chest->opened == 0)
                        SDL_BlitSurface(chest, NULL, gCurrentSurface, &r );
                    else if(tmp.chest->opened == 1)
                        SDL_BlitSurface(chest_open, NULL, gCurrentSurface, &r );
                }

                if(tmp.monster)
                    SDL_BlitSurface(skelt, NULL, gCurrentSurface, &r );

                if(tmp.player)
                    SDL_BlitSurface(hero_bmp, NULL, gCurrentSurface, &r);

                if(tmp.exit)
                    SDL_BlitSurface(game_exit, NULL, gCurrentSurface, &r);
            }
		}
    }
    SDL_FillRect(shade, NULL, 0);
    SDL_SetSurfaceBlendMode( shade, SDL_BLENDMODE_BLEND );
    SDL_SetSurfaceAlphaMod( shade, 100 );
    SDL_BlitSurface(shade, NULL, gCurrentSurface, NULL);

    tmp = g_Tab[Hero.y][Hero.x];

    SDL_BlitSurface(gWallSurfaces[base], NULL, gCurrentSurface, &h);



    for(int k=0; k<4; k++){
        if(tmp.door&(1<<k)){
            if(k == 0)
                SDL_BlitSurface(gWallSurfaces[left], NULL, gCurrentSurface, &h);
            if(k == 1)
                SDL_BlitSurface(gWallSurfaces[down], NULL, gCurrentSurface, &h);
            if(k == 2)
                SDL_BlitSurface(gWallSurfaces[right], NULL, gCurrentSurface, &h);
            if(k == 3)
                SDL_BlitSurface(gWallSurfaces[up], NULL, gCurrentSurface, &h);
        }
    }

    if(tmp.chest != NULL){
        if(tmp.chest->opened == 0)
            SDL_BlitSurface(chest, NULL, gCurrentSurface, &h );
        else if(tmp.chest->opened == 1)
            SDL_BlitSurface(chest_open, NULL, gCurrentSurface, &h );
    }

    if(tmp.monster)
        SDL_BlitSurface(skelt, NULL, gCurrentSurface, &h );

    if(tmp.player)
        SDL_BlitSurface(hero_bmp, NULL, gCurrentSurface, &h);

    if(tmp.exit)
        SDL_BlitSurface(game_exit, NULL, gCurrentSurface, &h);

    SDL_BlitSurface(torches , NULL, gCurrentSurface, &h);

}

void ClearTab()
{
    for(int i=0; i<NumCells; i++)
        for(int j=0; j<NumCells; j++){
            g_Tab[i][j].door=0;
            g_Tab[i][j].exit=0;
            g_Tab[i][j].monster=0;
            g_Tab[i][j].was_player=0;
            g_Tab[i][j].chest = NULL;
            g_Tab[i][j].player = 0;
        }
}




