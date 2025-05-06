#include "Player.h"
#include "global_variables.h"
#include <iostream>


Player::Player(SDL_Renderer* renderer, const char* file, float w, float h, float x, float y)
    : Sprite(renderer, file, w, h, x, y)
{
    ;
}


void Player::update() {
    const bool* keys = SDL_GetKeyboardState(NULL);
    if (this->is_mouse_over)
        std::cout << "mouse over\n";
    if (keys[SDL_SCANCODE_W])
        y -= 10;
    if (keys[SDL_SCANCODE_S])
        y += 10;
    if (keys[SDL_SCANCODE_A])
        x -= 10;
    if (keys[SDL_SCANCODE_D])
        x += 10;
}