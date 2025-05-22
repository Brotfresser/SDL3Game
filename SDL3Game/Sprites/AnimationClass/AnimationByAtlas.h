#pragma once
#include "BaseAnimation.h"
#include "../BaseSprite.h"

struct AnimationByAtlas final : public BaseAnimation
{
    AnimationByAtlas(BaseSprite* sprite, int* arr, double deltaTime = 0.2);

    void update_frame() override;
};
