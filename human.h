#ifndef HUMANS_H
#define HUMANS_H

#include "common.h"

// human
struct Human
{
    // constructor
    Human();
    // deconstructor
    ~Human();

    // member variables
    int x, y, w, h;
    int movToX, movToY;

    bool isHumanSelected; // selected by a left-mouse click maybe

    SDL_Surface **surfaces;
    int surfaceCount;
};

extern std::vector<Human *> humans;
extern void createHuman();

#endif // HUMANS_H