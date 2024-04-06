#include "close.h"

void close()
{
    // texturesHumansIdle
    for (int i = 0; i < texturesHumansIdle.size(); i++)
    {
        for (int j = 0; j < texturesHumansIdle[i].size(); j++)
        {
            SDL_DestroyTexture(texturesHumansIdle[i][j]);
            texturesHumansIdle[i][j] = nullptr;
        }
    }
    // texturesHumansWalk
    for (int i = 0; i < texturesHumansWalk.size(); i++)
    {
        for (int j = 0; j < texturesHumansWalk[i].size(); j++)
        {
            SDL_DestroyTexture(texturesHumansWalk[i][j]);
            texturesHumansWalk[i][j] = nullptr;
        }
    }

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;

    SDL_DestroyTexture(textureBg);
    textureBg = nullptr;

    // delete mainCam;
    // mainCam = nullptr;
}