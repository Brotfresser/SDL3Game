#pragma once
#include "Sprite.h"
#include "AnimationClass/BaseAnimation.h"


struct SpriteWithAnimation: Sprite {
    BaseAnimation* animation;

    SpriteWithAnimation(SDL_Renderer* renderer, BaseAnimation* animation, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);

    SpriteWithAnimation(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);

    void change_animation(BaseAnimation* animation);
    void update() override;
    ~SpriteWithAnimation() override;
};
