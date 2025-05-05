#include "Sprite.h"
#include <SDL3_image/SDL_image.h>


Sprite::Sprite(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y) :
    BaseSprite(renderer, file, x, y)
{
    load_texture(w, h);
}


void Sprite::load_texture(float w, float h) {
    texture = IMG_LoadTexture(renderer, path_to_file);
    if (w == 0 && h == 0)
        SDL_GetTextureSize(texture, &w, &h);

    dstrect = { x, y, w, h };
    srcrect = { 0, 0, w, h };
}
