#include "BaseSprite.h"
#include <SDL3_image/SDL_image.h>
#include "Scenes/BaseScene.h"


BaseSprite::BaseSprite(SDL_Renderer* renderer, const char* file, float x, float y) :
    dstrect(), srcrect(),
    x(dstrect.x), y(dstrect.y)
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

void BaseSprite::load_texture(SDL_Texture* new_texture) {
    SDL_DestroyTexture(texture);
    texture = new_texture;
    SDL_GetTextureSize(texture, &rect_w, &rect_h);
}

void BaseSprite::draw() {
    dstrect.w = rect_w * rect_w_k;
    dstrect.h = rect_h * rect_h_k;
    if (is_active) 
        SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

// ????? ?????? ?? ??????
void BaseSprite::update() {

}

void BaseSprite::handleEvents(SDL_Event* event) {

}

void BaseSprite::on_mouse_clicked() {

}

void BaseSprite::on_mouse_enter() {

}

void BaseSprite::on_mouse_exit() {

}


bool BaseSprite::is_in_rect(float x, float y) {
    if (this->x <= x && x <= this->x + rect_w)
        if (this->y <= y && y <= this->y + rect_h)
            return is_active && true;
    return false;
}


bool BaseSprite::is_collided_with_sprite(const BaseSprite& obj) {
    if (!is_active)
        return false;

    bool is_x_same = false;
    for (int x = obj.x; x < obj.x + obj.rect_w; ++x)
        if (this->x <= x && x <= this->x + this->rect_w) {
            is_x_same = true;
            break;
        }
    for (int y = obj.y; y < obj.y + obj.rect_h; ++y)
        if (this->y <= y && y <= this->y + this->rect_h) {
            return is_x_same;
        }

    return false;
        
}
void BaseSprite::activate() { is_active = true; }
void BaseSprite::deactivate() { is_active = false; }

const char *BaseSprite::get_path_to_file() {
    return path_to_file;
}

SDL_Texture* BaseSprite::get_texture() {
    return texture;
}
