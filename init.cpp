#include "init.h"

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf(":( could not initialize SDL video subsystem: %s\n", SDL_GetError());
        return false;
    }
    gWindow = SDL_CreateWindow("Zombies Vs Family", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        printf(":( could not create the SDL_Window (gWindow): %s\n", SDL_GetError());
        return false;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        printf(":( could not create the SDL_Renderer (gRenderer): %s\n", SDL_GetError());
        return false;
    }
    return true;
}
