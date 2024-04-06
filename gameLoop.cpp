#include "gameLoop.h"
#include "render.h"
#include "human.h"
#include "common.h"

// Camera *mainCamera;

void handleEvent(SDL_Event *e, bool &quit)
{
    if (e->type == SDL_QUIT)
        quit = true;
    else if (e->type == SDL_MOUSEBUTTONDOWN)
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
    else if (e->type == SDL_KEYDOWN)
    {
        if (e->key.keysym.sym == SDLK_w)
        {
            mainCamera->y -= mainCamera->moveSpeed;
            if (mainCamera->y < 0)
                mainCamera->y = 0;

            mainCamera->updateSDLRect();
        }
        else if (e->key.keysym.sym == SDLK_s)
        {
            mainCamera->y += mainCamera->moveSpeed;
            if (mainCamera->y + mainCamera->h > MAP_HEIGHT)
                mainCamera->y = MAP_HEIGHT - mainCamera->h;

            mainCamera->updateSDLRect();
        }
        else if (e->key.keysym.sym == SDLK_a)
        {
            mainCamera->x -= mainCamera->moveSpeed;
            if (mainCamera->x < 0)
                mainCamera->x = 0;

            mainCamera->updateSDLRect();
        }
        else if (e->key.keysym.sym == SDLK_d)
        {
            mainCamera->x += mainCamera->moveSpeed;
            if (mainCamera->x + mainCamera->w > MAP_WIDTH)
                mainCamera->x = MAP_WIDTH - mainCamera->w;

            mainCamera->updateSDLRect();
        }
    }
}

void runGameLoop()
{
    SDL_Event *e;
    bool quit = false;
    while (!quit)
    {
        frameNo++;
        while (SDL_PollEvent(e) == 1)
        {
            handleEvent(e, quit);
            // if (e->type == SDL_QUIT)
            //     quit = true;
        }

        // clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(gRenderer);

        render();

        // update screen
        SDL_RenderPresent(gRenderer);
    }
}