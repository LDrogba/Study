#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Surface* ScreenSurface = NULL;

void Prawo()
{

}

int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Lewo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    ScreenSurface = SDL_GetWindowSurface( window );
    SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB( ScreenSurface ->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface( window );
    SDL_Delay(5000);


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

