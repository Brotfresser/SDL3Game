#include "BaseSprite.h"
#include <SDL3_image/SDL_image.h>


BaseSprite::BaseSprite(SDL_Renderer* renderer, const char* file, float x, float y) :
    dstrect(), srcrect(),
    x(dstrect.x), y(dstrect.y),
    rect_w(dstrect.w), rect_h(dstrect.h)
{
    this->renderer = renderer;
    path_to_file = file;
    this->x = x; this->y = y;
    texture = nullptr;
}


BaseSprite::~BaseSprite() {
    SDL_DestroyTexture(texture);
}


void BaseSprite::load_texture(const char* path_to_file, float w, float h) {
    this->path_to_file = path_to_file;
    load_texture(w, h);
}


void BaseSprite::draw() {
    if (is_active)
        SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

// потом убрать на всякий
void BaseSprite::update() {

}

void BaseSprite::handleEvents() {

}

void BaseSprite::on_mouse_clicked() {

}

bool BaseSprite::is_in_rect(float x, float y) {
    if (this->x <= x && x <= this->x + rect_w)
        if (this->y <= y && y <= this->y + rect_h)
            return is_active && true;
    return false;
}


bool BaseSprite::is_collided_with_sprite(const BaseSprite& obj) {
    return is_active && is_in_rect(obj.x, obj.y);
        
}
void BaseSprite::activate() { is_active = true; }
void BaseSprite::deactivate() { is_active = false; }