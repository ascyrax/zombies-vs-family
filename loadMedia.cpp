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

bool loadHumansIdle()
{
    const int CNT_HUMANS = 4;
    const int CNT_IDLE_IMAGES = 6;

    SDL_Surface *surfHumanIdle = nullptr;

    for (int i = 1; i <= CNT_HUMANS; i++)
    {
        std::vector<SDL_Texture *> texturesHumanIdle;
        for (int j = 0; j < CNT_IDLE_IMAGES; j++)
        {
            std::string fileBg = "media/characters/useful/01/Full body animated characters/Char " + std::to_string(i) + "/with hands/idle_" + std::to_string(j) + ".png";
            // std::cout << fileBg << std::endl;
            surfHumanIdle = IMG_Load(fileBg.c_str());
            if (surfHumanIdle == NULL)
            {
                printf(":( could not load %s. error = %s\n", fileBg.c_str(), IMG_GetError());
                return false;
            }

            texturesHumanIdle.emplace_back(SDL_CreateTextureFromSurface(gRenderer, surfHumanIdle));
            if (texturesHumanIdle.back() == NULL)
            {
                printf(":( could not generate texture from %s. error = %s\n", fileBg.c_str(), SDL_GetError());
                return false;
            }
        }
        texturesHumansIdle.push_back(texturesHumanIdle);
    }
    // free surface
    SDL_FreeSurface(surfHumanIdle);
    surfHumanIdle = nullptr;

    return true;
}

bool loadHumansWalk()
{
    const int CNT_HUMANS = 4;
    const int CNT_WALK_IMAGES = 6;

    SDL_Surface *surfHumanWalk = nullptr;

    for (int i = 1; i <= CNT_HUMANS; i++)
    {
        std::vector<SDL_Texture *> texturesHumanWalk;
        for (int j = 0; j < CNT_WALK_IMAGES; j++)
        {
            std::string fileBg = "media/characters/useful/01/Full body animated characters/Char " + std::to_string(i) + "/with hands/walk_" + std::to_string(j) + ".png";
            // std::cout << fileBg << std::endl;
            surfHumanWalk = IMG_Load(fileBg.c_str());
            if (surfHumanWalk == NULL)
            {
                printf(":( could not load %s. error = %s\n", fileBg.c_str(), IMG_GetError());
                return false;
            }

            texturesHumanWalk.emplace_back(SDL_CreateTextureFromSurface(gRenderer, surfHumanWalk));
            if (texturesHumanWalk.back() == NULL)
            {
                printf(":( could not generate texture from %s. error = %s\n", fileBg.c_str(), SDL_GetError());
                return false;
            }
        }
        texturesHumansWalk.push_back(texturesHumanWalk);
    }
    // free surface
    SDL_FreeSurface(surfHumanWalk);
    surfHumanWalk = nullptr;

    return true;
}

bool loadHumans()
{
    if (!loadHumansIdle())
    {
        printf(":( error loading idle human images and converting it to textures: %s\n", SDL_GetError());
        return false;
    }
    else if (!loadHumansWalk())
    {
        printf(":( error loading walking human images and converting it to textures: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool loadMedia()
{
    if (loadBg() && loadHumans())
        return true;
    else
        return false;
}
