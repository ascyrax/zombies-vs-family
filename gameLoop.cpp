#include "gameLoop.h"
#include "render.h"

void runGameLoop()
{
    SDL_Event *e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(e) == 1)
        {
            if (e->type == SDL_QUIT)
                quit = true;
        }

        // clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(gRenderer);

        render();

        // update screen
        SDL_RenderPresent(gRenderer);
    }
}