#include <SDL3/SDL.h>
#include <Sprites/Sprite.h>
#include <fstream>


struct UIButtonLoad : Sprite {
    const char * path_to_json_file = "save/autosave.json";

    UIButtonLoad(SDL_Renderer *renderer, float x = 840, float y = 160,
        const char *file = "assets/MainMenu/save_load/oniichan_room2.png", float w = 0, float h = 0)
        : Sprite(renderer, file, w, h, x, y) {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void update_file_status() {
        std::ifstream file(path_to_file);
        if (!file.is_open()) {
            path_to_file = "assets/MainMenu/save_load/oniichan_room2.png";
            load_texture();
        }
        else {

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }

    void on_mouse_clicked() override {
        //Global::changeScene(new SceneLoad(renderer));
    }
};