#include "loadMedia.h"


bool loadBg()
{
    std::string fileBg = "media/backgrounds/bg05.webp";
    SDL_Surface *surfBg = IMG_Load(fileBg.c_str());
    if (surfBg == NULL)
    {
        printf(":( could not load %s. error = %s\n", fileBg.c_str(), IMG_GetError());
        return false;
    }
    textureBg = SDL_CreateTextureFromSurface(gRenderer, surfBg);
    if (textureBg == NULL)
    {
        printf(":( could not generate texture from %s. error = %s\n", fileBg.c_str(), SDL_GetError());
        return false;
    }
    // free surface
    SDL_FreeSurface(surfBg);
    surfBg = nullptr;
    return true;
}

bool loadCharacters()
{
    std::string fileBg = "media/characters/useful/01/Full body animated characters/Char 1/with hands/idle_0.png";
    SDL_Surface *surfCharacter = IMG_Load(fileBg.c_str());
    if (surfCharacter == NULL)
    {
        printf(":( could not load %s. error = %s\n", fileBg.c_str(), IMG_GetError());
        return false;
    }
    textureChar01 = SDL_CreateTextureFromSurface(gRenderer, surfCharacter);
    if (textureChar01 == NULL)
    {
        printf(":( could not generate texture from %s. error = %s\n", fileBg.c_str(), SDL_GetError());
        return false;
    }
    // free surface
    SDL_FreeSurface(surfCharacter);
    surfCharacter = nullptr;
    return true;
}

bool loadMedia()
{
    if (loadBg() && loadCharacters())
        return true;
    else
        return false;
}
