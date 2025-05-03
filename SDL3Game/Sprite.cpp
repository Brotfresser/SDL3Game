#include "Sprite.h"
#include <SDL3_image/SDL_image.h>

Sprite::Sprite(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y) :
    x(dstrect.x), y(dstrect.y),
    rect_w(dstrect.w), rect_h(dstrect.h)
{
    texture = IMG_LoadTexture(renderer, file);
    if (w == 0 && h == 0)
        SDL_GetTextureSize(texture, &w, &h);
    this->renderer = renderer;
    path_to_file = file;
    dstrect = { x, y, w, h };
    srcrect = { 0, 0, w, h };
}

void Sprite::draw() {
    SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

void Sprite::update() {
    const bool* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_W])
        y -= 10;
    if (keys[SDL_SCANCODE_S])
        y += 10;
    if (keys[SDL_SCANCODE_A])
        x -= 10;
    if (keys[SDL_SCANCODE_D])
        x += 10;
}

void Sprite::handleEvents() {

}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}


