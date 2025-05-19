#include "Player.h"


Player::Player(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y)
    : Sprite(renderer, file, w, h, x, y)
{
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    animation = new Animation(rect_w, rect_h, srcrect, 0.2, new int[12] {2,2,2,4,4,4,2,2,2,3,3,3} );
}


void Player::update() {
    if (!is_active)
        return;

    animation->update_frame();
    smooth_move_data.update();

    const bool* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_W]) {
        animation->change_id_y(5);
        smooth_move_data.init_by_speed_inf(x, y-speed);
    }
    if (keys[SDL_SCANCODE_S]) {
        animation->change_id_y(3);
        smooth_move_data.init_by_speed_inf(x, y+speed);
    }
    if (keys[SDL_SCANCODE_A])
        smooth_move_data.init_by_speed_inf(x-speed, y);
    if (keys[SDL_SCANCODE_D]) {
        animation->change_id_y(4);
        smooth_move_data.init_by_speed_inf(x+speed, y);
    }
    else if (!keys[SDL_SCANCODE_W] && !keys[SDL_SCANCODE_S] && !keys[SDL_SCANCODE_A]) {
        animation->change_id_y(0);
        smooth_move_data.stop();
    }
}