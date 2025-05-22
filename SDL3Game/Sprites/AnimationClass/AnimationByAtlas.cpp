#include "AnimationByAtlas.h"

AnimationByAtlas::AnimationByAtlas(BaseSprite* sprite, int* arr, double deltaTime)
    : BaseAnimation(sprite, arr, deltaTime) {}


void AnimationByAtlas::update_frame() {
    if (animation_timer) {
        animation_timer(deltaTime);
        ++id_x;
        if (id_x >= arr_max_x_id[id_y])
            id_x = 0;
        sprite->srcrect.x = id_x * sprite->get_rect_w_original();
        sprite->srcrect.y = id_y * sprite->get_rect_h_original();
    }
}