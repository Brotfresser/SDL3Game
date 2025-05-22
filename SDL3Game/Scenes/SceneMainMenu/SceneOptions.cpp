#pragma once
#include "../BaseScene.h"
#include "../../global_variables.h"
#include "SceneOptions/UIbuttons.cpp"


struct SceneOptions final : public BaseScene
{
    UIMenuButtons menu_buttons;
    explicit SceneOptions(SDL_Renderer* renderer) : BaseScene(renderer)
    {
        menu_buttons.init();
        all_sprites.push_back(new Sprite(renderer, "assets/MainMenu/bg/dinner background.png"));
        menu_buttons.all_buttons->push_back(new ButtonFullscreen(renderer));
        menu_buttons.all_buttons->push_back(new ButtonMainVolume(renderer));
        menu_buttons.all_buttons->push_back(new ButtonBGMVolume(renderer));
        menu_buttons.all_buttons->push_back(new ButtonBGSVolume(renderer));
        menu_buttons.all_buttons->push_back(new ButtonSEVolume(renderer));
        menu_buttons.all_buttons->push_back(new ButtonSisterVolume(renderer));
        menu_buttons.all_buttons->push_back(new ButtonMaxPlayerMsgs(renderer));
        menu_buttons.all_buttons->push_back(new ButtonShwWpnDr(renderer));
        menu_buttons.current = menu_buttons.all_buttons->begin();
        (*menu_buttons)->on_mouse_enter();
    }

    EventType event(SDL_Event* event) override {
        switch (event->type) {
            case SDL_EVENT_MOUSE_MOTION:
                UI_MENU_BUTTON_MOUSE_MOTION_ITER(menu_buttons)
            case SDL_EVENT_MOUSE_BUTTON_UP:
                UI_MENU_BUTTON_MOUSE_PRESSED(menu_buttons, *menu_buttons.all_buttons)
                if (event->button.button == SDL_BUTTON_RIGHT)
                        SceneFabric::SwitchScene(AllScenesID::MainMenu);

            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    UI_MENU_BUTTON_SWITCH_ITER(menu_buttons)
                    case SDL_SCANCODE_ESCAPE:
                        SceneFabric::SwitchScene(AllScenesID::MainMenu);
                        break;
                default: ;
                }
                break;
        }
        (*menu_buttons.current)->handleEvents(event);
        return Global::event;
    }

    EventType draw() override {
        for (auto& sprite : all_sprites)
            sprite->draw();
        for (auto& button : *menu_buttons.all_buttons)
            button->draw();
        return EventType::NONE;
    }

    EventType update() override {
        return EventType::NONE;
    }

    ~SceneOptions() {
        for (auto& sprite : *menu_buttons.all_buttons)
            delete sprite;
    }
};
