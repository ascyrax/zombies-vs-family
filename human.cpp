#include "human.h"

std::vector<Human *> humans;
const int humanW = 100, humanH= 100;

Human::Human()
{
    x = 500;
    y = 500;
    w = humanW;
    h = humanH;
    movToX = x;
    movToY = y;
    isHumanSelected = true; // todo: false by default
    surfaceCount = 0;
    surfaces = nullptr;
}

Human::~Human()
{
    for (int i = 0; i < surfaceCount; i++)
    {
        if (surfaces[i])
            SDL_FreeSurface(surfaces[i]);
        surfaces[i] = nullptr;
    }
    delete[] surfaces;
}

void createHuman()
{
    Human *newHuman = new Human();
    humans.push_back(newHuman);
    return;
}