#pragma once
using all_sprites_container = std::list<BaseSprite*>;


#define UIMENUBUTTONMOUSEMOTION(current_button) for (auto& sprite : *current_button.all_buttons) \
if (sprite->is_in_rect(Global::MouseX, Global::MouseY) && sprite != *current_button) { \
(*current_button)->on_mouse_exit(); \
current_button.current = std::ranges::find(*current_button.all_buttons, sprite); \
(*current_button)->on_mouse_enter(); \
}

#define UIMENUBUTTONSSWTICH(current_button) case SDL_SCANCODE_RETURN: \
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
    BaseSprite* operator*() const;
    ~UIMenuButtons();
};
