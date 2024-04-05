#ifndef COMMON_H
#define COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int frameNo;

extern SDL_Texture *textureBg;

extern int charW, charH;

extern std::vector<std::vector<SDL_Texture *>> texturesHumansIdle;
extern std::vector<std::vector<SDL_Texture *>> texturesHumansWalk;

#endif // COMMON_H