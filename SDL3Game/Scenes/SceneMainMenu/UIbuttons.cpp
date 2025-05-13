#include <SDL3/SDL.h>
#include "../../Sprite.h"
#include <string>
//#include "../../global_variables.h"
#include "../../global_functions.h"
#include "../SceneGameStart.h"
#include "SceneOptions.cpp"


struct UIButtonNew : Sprite {
    friend SceneMainMenu;

    UIButtonNew(SDL_Renderer *renderer, const char *file, float w = 0, float h = 0,
                float x = 0, float y = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        SDL_Log("game new");
        Global::changeScene(new SceneGameStart(renderer));
    }
};


struct UIButtonLoad : Sprite {
    friend SceneMainMenu;

    UIButtonLoad(SDL_Renderer *renderer, const char *file, float w = 0, float h = 0,
                 float x = 0, float y = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        SDL_Log("game load");
    }
};


struct UIButtonSettings : Sprite {
    friend SceneMainMenu;

    UIButtonSettings(SDL_Renderer *renderer, const char *file, float w = 0, float h = 0, float x = 0, float y = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        Global::changeScene(new SceneOptions(renderer));
    }
};


struct UIButtonSupport : public Sprite {
    friend SceneMainMenu;

    UIButtonSupport(SDL_Renderer *renderer, const char *file, float w = 0, float h = 0, float x = 0, float y = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        Global::openWebsite("https://nlch.itch.io/sister");
    }
};


struct UIButtonExit : Sprite {
    friend SceneMainMenu;

    UIButtonExit(SDL_Renderer *renderer, const char *file, float w = 0, float h = 0, float x = 0, float y = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        SDL_Log("close game");
        Global::CloseGame();
    }
};
