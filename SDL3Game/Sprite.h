#pragma once
#include <SDL3/SDL.h>
#include "BaseSprite.h"
#include "Timer.h"


struct Animation {
    Animation(float& rect_w, float& rect_h, SDL_FRect& srcrect, double deltaTime, int* arr);
    float& rect_w;
    float& rect_h;
    SDL_FRect& srcrect;
    // секунды
    double deltaTime = 0.2;
    // массив макс id_x для каждой анимации[id_y]
    int* arr_max_x_id = nullptr;

    int id_x = 0;
    int id_y = 0;
    Timer animation_timer{ deltaTime };
    void change_id_y(int new_id_y);
    void update_frame();
    ~Animation();
};


class Sprite: public BaseSprite
{
    friend Animation;
protected:
    Animation* animation = nullptr;
public:
	Sprite(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
    ~Sprite() override;
	void load_texture(float w = 0, float h = 0) override;
};

