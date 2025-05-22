#pragma once
#include <list>
#include <Sprites/BaseSprite.h>
using all_sprites_container = std::list<BaseSpriteInterface*>;


#define UI_SPRITE_MOUSE_MOTION(current_sprite, sprites_list) for (auto& sprite : sprites_list) \
if (sprite->is_in_rect(Global::MouseX, Global::MouseY) && sprite != current_sprite) { \
current_sprite->on_mouse_exit(); \
current_sprite = *std::ranges::find(sprites_list, sprite); \
current_sprite->on_mouse_enter(); \
}


#define UI_MENU_BUTTON_MOUSE_PRESSED(current_button, sprites_list) if (event->button.button == SDL_BUTTON_LEFT) \
for (auto& sprite : sprites_list) \
    if (sprite->is_in_rect(Global::MouseX, Global::MouseY) && sprite == *current_button) \
        (*current_button)->on_mouse_clicked();


#define UI_MENU_BUTTON_MOUSE_MOTION_ITER(current_button) for (auto& sprite : *current_button.all_buttons) \
if (sprite->is_in_rect(Global::MouseX, Global::MouseY) && sprite != *current_button) { \
(*current_button)->on_mouse_exit(); \
current_button.current = std::ranges::find(*current_button.all_buttons, sprite); \
(*current_button)->on_mouse_enter(); \
}


#define UI_MENU_BUTTON_SWITCH_ITER(current_button) case SDL_SCANCODE_RETURN: \
(*current_button)->on_mouse_clicked(); \
break; \
case SDL_SCANCODE_UP: \
(*current_button)->on_mouse_exit(); \
--current_button; \
(*current_button)->on_mouse_enter(); \
break; \
case SDL_SCANCODE_DOWN: \
(*current_button)->on_mouse_exit(); \
++current_button; \
(*current_button)->on_mouse_enter(); \
break;


struct UIMenuButtons {
    all_sprites_container* all_buttons = nullptr;
    using iter = all_sprites_container::iterator;
    iter current;
    void init();
    void init(iter begin, iter end);
    iter operator++();
    iter operator--();
    iter operator++(int);
    iter operator--(int);
    BaseSpriteInterface* operator*() const;
    ~UIMenuButtons();
};
