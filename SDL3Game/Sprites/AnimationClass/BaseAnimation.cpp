#include "BaseAnimation.h"


BaseAnimation::BaseAnimation(BaseSprite* sprite, int *arr, const double deltaTime)
    : sprite(sprite), deltaTime(deltaTime), arr_max_x_id(arr) {}

void BaseAnimation::change_id_y(const int new_id_y) {
    if (id_y != new_id_y) {
        id_x = 0;
        id_y = new_id_y;
        animation_timer(0);
    }
}

BaseAnimation::~BaseAnimation() {
    delete [] arr_max_x_id;
}
