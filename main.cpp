#include "common.h"
#include "init.h"
#include "loadMedia.h"
#include "render.h"
#include "close.h"
#include "gameLoop.h"


int main()
{
    if (!init())
    {
        printf(":( could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    else if (!loadMedia())
    {
        printf(":( could not load media: %s\n", SDL_GetError());
        return 1;
    }
    else
    {
        runGameLoop();
    }
    // close();
    return 0;
}