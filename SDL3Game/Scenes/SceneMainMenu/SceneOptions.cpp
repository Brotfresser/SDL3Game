#pragma once
#include "../BaseScene.h"
#include "../../global_variables.h"
#include "../../global_functions.h"
#include "../SceneMainMenu.h"
#include "SceneOptions/UIbuttons.cpp"
#include "../../TextRect.h"


//Sprite* bg;
struct SceneOptions: public BaseScene
{
    UIMenuButtons current_button;
    SceneOptions(SDL_Renderer* renderer) : BaseScene(renderer)
    {
        current_button.init();
        all_sprites.push_back(new Sprite(renderer, "assets/homeVN/kitchen/bg/dk_CW_N_RL.png"));
        current_button.all_buttons->push_back(new ButtonFullscreen(renderer));
        current_button.all_buttons->push_back(new ButtonMainVolume(renderer));
        current_button.all_buttons->push_back(new ButtonBGMVolume(renderer));
        current_button.all_buttons->push_back(new ButtonBGSVolume(renderer));
        current_button.all_buttons->push_back(new ButtonSEVolume(renderer));
        current_button.all_buttons->push_back(new ButtonSisterVolume(renderer));
        current_button.all_buttons->push_back(new ButtonMaxPlayerMsgs(renderer));
        current_button.all_buttons->push_back(new ButtonShwWpnDr(renderer));
        current_button.current = current_button.all_buttons->begin();
        (*current_button)->on_mouse_enter();
    }

    EventType event(SDL_Event* event) override {
        switch (event->type) {
            case SDL_EVENT_MOUSE_MOTION:
                UIMENUBUTTONMOUSEMOTION(current_button)
            case SDL_EVENT_MOUSE_BUTTON_UP:
                switch (event->button.button) {
                    case SDL_BUTTON_RIGHT:
                        Global::changeScene(new SceneMainMenu(renderer));
                        break;
                }
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_ESCAPE:

                        break;
                    UIMENUBUTTONSSWTICH(current_button)
                }
                break;
        }
        (*current_button.current)->handleEvents(event);
        return Global::event;
    }

    EventType draw() override {
        for (auto& sprite : all_sprites)
            sprite->draw();
        for (auto& button : *current_button.all_buttons)
            button->draw();
        return EventType::NONE;
    }

    EventType update() override {
        return EventType::NONE;
    }

    ~SceneOptions() {
        for (auto& sprite : *current_button.all_buttons)
            delete sprite;
    }
};
