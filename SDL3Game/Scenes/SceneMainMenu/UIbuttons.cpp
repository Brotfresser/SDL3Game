#include <SDL3/SDL.h>
#include <Sprites/Sprite.h>
#include <string>
#include <global_functions.h>
#include <SwitchSceneFabric.h>


constexpr float start_button_x = 1920.0 * 80/100;
constexpr int new_button_x = start_button_x - 30;
constexpr double speed_button = 83;


struct UIButtonNew final : Sprite {

    explicit UIButtonNew(SDL_Renderer *renderer, const char *file = "assets/MainMenu/buttons/NEW_.png",
        float w = 0, float h = 0,
                float x = start_button_x, float y = 1080.0 * 63/100)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
        smooth_move_data.init_by_speed(new_button_x, y, speed_button);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
        smooth_move_data.init_by_speed(start_button_x, y, speed_button);
    }

    void on_mouse_clicked() override {
        SceneFabric::SwitchScene(AllScenesID::GameStart);
    }
};


struct UIButtonLoadGame final : Sprite {

    explicit UIButtonLoadGame(SDL_Renderer *renderer, const char *file = "assets/MainMenu/buttons/LOAD_.png",
        float w = 0, float h = 0,
                 float x = start_button_x, float y = 1080.0 * 70/100)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
        smooth_move_data.init_by_speed(new_button_x, y, speed_button);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
        smooth_move_data.init_by_speed(start_button_x, y, speed_button);
    }

    void on_mouse_clicked() override {
        SceneFabric::SwitchScene(AllScenesID::LoadGame);
    }
};


struct UIButtonSettings final : Sprite {

    explicit UIButtonSettings(SDL_Renderer *renderer, const char *file = "assets/MainMenu/buttons/SETTING_.png",
        float w = 0, float h = 0,
        float x = start_button_x, float y = 1080.0 * 77/100)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
        smooth_move_data.init_by_speed(new_button_x, y, speed_button);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
        smooth_move_data.init_by_speed(start_button_x, y, speed_button);
    }

    void on_mouse_clicked() override {
        SceneFabric::SwitchScene(AllScenesID::Options);
    }
};


struct UIButtonSupport final : Sprite {

    explicit UIButtonSupport(SDL_Renderer *renderer, const char *file = "assets/MainMenu/buttons/SUPPORT_.png",
        float w = 0, float h = 0,
        float x = start_button_x, float y = 1080.0 * 84/100)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
        smooth_move_data.init_by_speed(new_button_x, y, speed_button);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
        smooth_move_data.init_by_speed(start_button_x, y, speed_button);
    }

    void on_mouse_clicked() override {
        SDL_OpenURL("https://nlch.itch.io/sister");
    }
};


struct UIButtonExit final : Sprite {

    explicit UIButtonExit(SDL_Renderer *renderer, const char *file = "assets/MainMenu/buttons/EXIT_.png",
        float w = 0, float h = 0,
        float x = start_button_x, float y = 1080.0 * 91/100)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
        smooth_move_data.init_by_speed(new_button_x, y, speed_button);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
        smooth_move_data.init_by_speed(start_button_x, y, speed_button);
    }

    void on_mouse_clicked() override {
        SDL_Log("close game");
        Global::CloseGame();
    }
};
