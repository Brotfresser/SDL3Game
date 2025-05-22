#pragma once
#include "Timer.h"
#include <Sprites/BaseSprite.h>

struct BaseAnimation {
    explicit BaseAnimation(BaseSprite* sprite, int *arr, double deltaTime = 0.2);
    BaseSprite* sprite;
    // задержка между кадрами анимации
    double deltaTime = 0.2;
    // Массив из id_y, в каждом максимальный размер id_x
    int* arr_max_x_id = nullptr;

    int id_x = 0;
    int id_y = 0;
    Timer animation_timer{ deltaTime };
    void change_id_y(int new_id_y);
    virtual void update_frame() = 0;
    virtual ~BaseAnimation();
};
