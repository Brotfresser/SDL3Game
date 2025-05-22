#include "AnimationByFile.h"
#include <format>

AnimationByFile::AnimationByFile(BaseSprite* sprite, const char *file_name, int *arr, double deltaTime, const char* file_prefix)
    :BaseAnimation(sprite, arr, deltaTime), file_name(file_name), file_prefix(file_prefix) {}

void AnimationByFile::update_frame() {
    if (animation_timer) {
        animation_timer(deltaTime);
        ++id_x;
        if (id_x >= arr_max_x_id[id_y])
            id_x = 1;
        sprite->load_texture(std::format("{}{}{}", file_name, id_x, file_prefix).c_str());
    }
}

