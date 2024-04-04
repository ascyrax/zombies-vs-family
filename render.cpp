#include "render.h"

void renderBg()
{
    SDL_RenderCopy(gRenderer, textureBg, nullptr, nullptr);
}
void renderCharacters()
{
    SDL_Rect destRect = {500, 500, charW, charH};
    SDL_RenderCopy(gRenderer, textureChar01, nullptr, &destRect);
}

void render()
{
    renderBg();
    renderCharacters();
}