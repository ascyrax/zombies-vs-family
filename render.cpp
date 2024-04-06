#include "render.h"
#include "human.h"

SDL_Texture *currentHumanTexture = NULL;

bool renderBg()
{
    if (SDL_RenderCopy(gRenderer, textureBg, &mainCamera->cameraRect, nullptr) != 0)
    {
        printf(":( error rendering the background textures using a ZOOM_FACTOR: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void simulateMove(int index, Human *human)
{
    if (frameNo % 10 != 0)
        return;
    if (human->movToX != human->x)
        human->x += (human->movToX > human->x) ? 1 : -1;
    if (human->movToY != human->y)
        human->y += (human->movToY > human->y) ? 1 : -1;
    int val = (frameNo / 200) % 8;
    if (frameNo % 200 != 0)
        return;
    currentHumanTexture = texturesHumansWalk[index][val];
}

void simulateIdle(int index, Human *human)
{
    if (frameNo % 300 != 0)
        return;
    currentHumanTexture = texturesHumansIdle[index][(frameNo / 300) % 6];
}

bool renderHumans()
{
    if (humans.size() == 0)
    {
        createHuman();
        currentHumanTexture = texturesHumansIdle[0][0];
    }
    for (int i = 0; i < humans.size(); i++)
    {
        Human *human = humans[i];
        if (human->movToX != human->x || human->movToY != human->y)
            simulateMove(i, human);
        else
            simulateIdle(i, human);

        SDL_Rect destRect = {human->x - 150, human->y - 200, human->w, human->h};

        SDL_RenderCopy(gRenderer, currentHumanTexture, nullptr, &destRect);
    }

    return true;
}

bool renderEnemies()
{
    // every 10000 frames, add an enemy to the map
    return true;
}

bool render()
{
    if (!renderBg())
    {
        printf(":( error rendering the background: %s\n", SDL_GetError());
        return false;
    }
    if (!renderHumans())
    {
        printf(":( error rendering the humans: %s\n", SDL_GetError());
        return false;
    }
    if (!renderEnemies())
    {
        printf(":( error rendering the enemies: %s\n", SDL_GetError());
        return false;
    }

    return true;
}