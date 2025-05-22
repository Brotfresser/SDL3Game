#include "BaseSprite.h"
#include <SDL3_image/SDL_image.h>


BaseSprite::BaseSprite(SDL_Renderer* renderer, const char* file, const float x, const float y) :
    dstrect(), srcrect(),
    x(dstrect.x), y(dstrect.y),
    w(dstrect.w), h(dstrect.h),
    smooth_move_data(dstrect.x, dstrect.y)
{
    //SDL_Log("init BaseSprite x: %10.1f, y: %10.1f   | %s", x, y, file);
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
    dstrect.w = rect_w * rect_w_k;
    dstrect.h = rect_h * rect_h_k;
    if (is_active) 
        SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}


void BaseSprite::update() {
    smooth_move_data.update();
}

void BaseSprite::handleEvents(SDL_Event* event) {

}

void BaseSprite::on_mouse_clicked() {

}

void BaseSprite::on_mouse_enter() {

}

void BaseSprite::on_mouse_exit() {

}


bool BaseSprite::is_in_rect(float x, float y) const {
    if (this->x <= x && x <= this->x + rect_w)
        if (this->y <= y && y <= this->y + rect_h)
            return is_active && true;
    return false;
}


bool BaseSprite::is_collided_with_sprite(const BaseSprite& obj) {
    if (!is_active)
        return false;

    float obj_right = obj.x + obj.w;
    float obj_bottom = obj.y + obj.h;
    float obj_left = obj.x;
    float obj_top = obj.y;

    return (obj_right > x && obj_left < x + w && obj_bottom > y && obj_top > y + h);
        
}
void BaseSprite::activate() { is_active = true; }
void BaseSprite::deactivate() { is_active = false; }


const char *BaseSprite::get_path_to_file() const {
    return path_to_file;
}

SDL_Texture* BaseSprite::get_texture() const {
    return texture;
}

float BaseSprite::get_rect_w_original() const {
    return rect_w;
}


float BaseSprite::get_rect_h_original() const {
    return rect_h;
}
