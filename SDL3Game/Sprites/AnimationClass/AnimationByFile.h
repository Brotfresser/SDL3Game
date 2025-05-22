#pragma once
#include "BaseAnimation.h"

// пока поддерживает только одну анимацию
struct AnimationByFile final : BaseAnimation {
    int id_x = 1;
    const char* file_name;
    const char* file_prefix = ".png";

    explicit AnimationByFile(BaseSprite* sprite, const char* file_name, int *arr, double deltaTime = 0.2, const char* file_prefix = ".png");

    void update_frame() override;
};
