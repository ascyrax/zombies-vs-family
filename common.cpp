#include "common.h"

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;
const int SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;

SDL_Texture *textureBg = nullptr; // texture for the background map
SDL_Texture *textureChar01 = nullptr; // texture for the character01

int charW = 100, charH = 100; // width and height of the characters
