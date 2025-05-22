#include "Sprite.h"
#include <SDL3_image/SDL_image.h>


Sprite::Sprite(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y) :
    BaseSprite(renderer, file, x, y)
{
    rect_w = w;
    rect_h = h;
    load_texture(rect_w, rect_h);
}



void Sprite::load_texture(float w, float h) {
    SDL_DestroyTexture(texture);
    texture = IMG_LoadTexture(renderer, path_to_file);
    if (texture == nullptr) {
        SDL_Log("error loading texture: %s", SDL_GetError());
    }
    if (w == 0 && h == 0)
        SDL_GetTextureSize(texture, &rect_w, &rect_h);
    dstrect = { x, y, rect_w, rect_h };
    srcrect = { 0, 0, rect_w, rect_h };
}