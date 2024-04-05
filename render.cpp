#include "render.h"
#include "human.h"

SDL_Texture *currentHumanTexture = NULL;

void renderBg()
{
    SDL_RenderCopy(gRenderer, textureBg, nullptr, nullptr);
}

void simulateMove(int index, Human *human)
{
    int frame;
    if (frameNo % 10 == 0)
    {
        if (human->movToX != human->x)
            human->x += (human->movToX > human->x) ? 1 : -1;
        if (human->movToY != human->y)
            human->y += (human->movToY > human->y) ? 1 : -1;
        int val = (frameNo / 200) % 8;
        // std::cout << "val: " << val << std::endl;
        currentHumanTexture = texturesHumansWalk[index][val];
    }
}

void simulateIdle(int index, Human *human)
{
    currentHumanTexture = texturesHumansIdle[index][(frameNo / 200) % 6];
}

void renderHumans()
{
    // std::cout << humans.size() << std::endl;

    if (humans.size() == 0)
    {
        // std::cout << "if" << std::endl;
        createHuman();
    }
    for (int i = 0; i < humans.size(); i++)
    {
        // std::cout << "i = " << i << std::endl;
        Human *human = humans[i];
        if (human->movToX != human->x || human->movToY != human->y)
            simulateMove(i, human);
        else
            simulateIdle(i, human);

        SDL_Rect destRect = {human->x, human->y, human->w, human->h};
        SDL_RenderCopy(gRenderer, currentHumanTexture, nullptr, &destRect);
    }
}

void renderEnemies()
{
    // every 10000 frames, add an enemy to the map
}

void render()
{
    renderBg();
    renderHumans();
    renderEnemies();
}