#include "Sprite.h"
#include <SDL3_image/SDL_image.h>


Animation::Animation(float& rect_w, float& rect_h, SDL_FRect& srcrect, double deltaTime, int* arr)
    : rect_w(rect_w), rect_h(rect_h), srcrect(srcrect)
{
    this->deltaTime = deltaTime;
    this->arr_max_x_id = arr;
}

void Animation::change_id_y(int new_id_y) {
    if (id_y != new_id_y) {
        id_x = 0;
        id_y = new_id_y;
        animation_timer(0);
    }
}

void Animation::update_frame() {
    if (arr_max_x_id != nullptr && animation_timer) {
        animation_timer(deltaTime);
        ++id_x;
        if (id_x >= arr_max_x_id[id_y])
            id_x = 0;
        srcrect.x = id_x * rect_w;
        srcrect.y = id_y * rect_h;
    }
}
Animation::~Animation() {
    delete arr_max_x_id;
}



Sprite::Sprite(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y) :
    BaseSprite(renderer, file, x, y)
{
    rect_w = w;
    rect_h = h;
    load_texture(rect_w, rect_h);
}


Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
    if (animation != nullptr)
        delete animation;
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

void Sprite::load_texture(SDL_Texture* new_texture) {
    SDL_DestroyTexture(texture);
    texture = new_texture;
    SDL_GetTextureSize(texture, &rect_w, &rect_h);
}