#include "common.h"

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;
const int SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;

SDL_Texture *textureBg = nullptr; // texture for the background map
// SDL_Texture *textureChar01 = nullptr; // texture for the character01
std::vector<std::vector<SDL_Texture *>> texturesHumansIdle;
std::vector<std::vector<SDL_Texture *>> texturesHumansWalk;

int charW = 100,
    charH = 100; // width and height of the characters

int frameNo = 0;

// BACKGROUND MAP
const int BG_ZOOM_FACTOR = 2.0;
int MAP_WIDTH = 1920, MAP_HEIGHT = 1080;

// CAMERA

Camera::Camera()
{

    // std::cout << "new camera instance" << std::endl;
    w = SCREEN_WIDTH / BG_ZOOM_FACTOR;
    h = SCREEN_HEIGHT / BG_ZOOM_FACTOR;

    x = MAP_WIDTH / 2 - w / 2;
    y = MAP_HEIGHT / 2 - h / 2;

    cameraRect = {x, y, w, h};

    moveSpeed = 10;
}

void Camera::updateSDLRect()
{
    cameraRect.x = x;
    cameraRect.y = y;
    cameraRect.w = w;
    cameraRect.h = h;
}

Camera::~Camera()
{
}

Camera *mainCamera;