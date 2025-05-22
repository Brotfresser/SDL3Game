#include "SpriteWithAnimation.h"

SpriteWithAnimation::SpriteWithAnimation(SDL_Renderer *renderer, BaseAnimation *animation, const char *file, float w, float h, float x, float y)
    : Sprite(renderer, file, w, h), animation(animation) {}

SpriteWithAnimation::SpriteWithAnimation(SDL_Renderer *renderer, const char *file, float w, float h, float x, float y)
    :SpriteWithAnimation(renderer, nullptr, file, w, h, x, y) {}


void SpriteWithAnimation::change_animation(BaseAnimation *animation) {
    this->animation = animation;
}

void SpriteWithAnimation::update() {
    Sprite::update();
    animation->update_frame();
}

SpriteWithAnimation::~SpriteWithAnimation() {
    delete animation;
}
