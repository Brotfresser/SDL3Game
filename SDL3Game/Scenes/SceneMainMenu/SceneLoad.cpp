#pragma once
#include <Scenes/BaseScene.h>
#include "SceneLoad/UIButtons.cpp"


constexpr int files_cnt = 20 + 1;
class SceneLoad: public BaseScene
{
    UIMenuButtons menu_buttons;
public:
    SceneLoad(SDL_Renderer* renderer)
        :BaseScene(renderer)
    {
        menu_buttons.init();
        all_sprites.push_back(new Sprite(renderer, "assets/homeVN/kitchen/bg/dk_CW_N_RL.png"));
        menu_buttons.all_buttons->push_back(new UIButtonLoad(renderer, 840, 160));
        menu_buttons.all_buttons->push_back(new UIButtonLoad(renderer, 840, 160 + 437));
        menu_buttons.current = menu_buttons.all_buttons->begin();
        (*menu_buttons.current)->on_mouse_enter();
    }

    EventType event(SDL_Event* event) override {
        switch (event->type) {
            case SDL_EVENT_MOUSE_MOTION:
                UI_MENU_BUTTON_MOUSE_MOTION_ITER(menu_buttons)
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_ESCAPE:
                        break;
                        UI_MENU_BUTTON_SWITCH_ITER(menu_buttons)
                }
                break;
        }
        return Global::event;
    }

    EventType draw() override {
        BaseScene::draw();
        for (auto& button : *menu_buttons.all_buttons) {
            button->draw();
        }
        return EventType::NONE;
    }

    EventType update() override {
        return Global::event;
    }
};
