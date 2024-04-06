#ifndef COMMON_H
#define COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>
#include "debug.h"

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int frameNo;

extern SDL_Texture *textureBg;

extern int charW, charH;

extern std::vector<std::vector<SDL_Texture *>> texturesHumansIdle;
extern std::vector<std::vector<SDL_Texture *>> texturesHumansWalk;

// background map
extern int MAP_WIDTH, MAP_HEIGHT;
extern const int BG_ZOOM_FACTOR;

struct Camera
{
    Camera();
    ~Camera();

    void updateSDLRect();

    int x, y, w, h;
    int moveSpeed;
    SDL_Rect cameraRect;
};

// camera
extern Camera *mainCamera;

#endif // COMMON_H