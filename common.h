#ifndef COMMON_H
#define COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;

extern SDL_Texture *textureBg;
extern SDL_Texture *textureChar01;

extern int charW, charH;

#endif // COMMON_H