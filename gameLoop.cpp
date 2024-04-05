#include "gameLoop.h"
#include "render.h"
#include "human.h"

void runGameLoop()
{
    SDL_Event *e;
    bool quit = false;
    while (!quit)
    {
        frameNo++;
        while (SDL_PollEvent(e) == 1)
        {
            if (e->type == SDL_QUIT)
                quit = true;
            else
            {
                if (e->type == SDL_MOUSEBUTTONDOWN)
                {
                    if (e->button.button == SDL_BUTTON_RIGHT)
                    {
                        int movToX = e->button.x;
                        int movToY = e->button.y;
                        // std::cout << movToX << " " << movToY << std::endl;
                        for (int i = 0; i < humans.size(); i++)
                        {
                            if (humans[i]->isHumanSelected)
                            {
                                humans[i]->movToX = movToX;
                                humans[i]->movToY = movToY;
                                // humans[i]->isHumanSelected = false;
                            }
                        }
                    }
                }
            }
        }

        // clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(gRenderer);

        render();

        // update screen
        SDL_RenderPresent(gRenderer);
    }
}