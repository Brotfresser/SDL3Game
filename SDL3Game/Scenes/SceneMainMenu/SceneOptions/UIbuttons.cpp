#include "../../../TextRect.h"
#include <format>
#include "../../../global_options.h"


// неравномерно, придется делать их как отдельные спрайты
const char* text_format(const char* mes1, const char* mes2) {
    int columns = 35 - strlen(mes1) - strlen(mes2);
    const char* format = std::format("{}{:{}}{}\n", mes1, "", columns, mes2).c_str();
    return  format;
}
int id = 0;
int get_id_y() {
    return id++;
}
constexpr int start_y = 240;
constexpr int deltaY = 80;
struct ButtonFullscreen : public TextRect {
    void load_text() {
        if (GameOptions::Fullscreen) {
            change_text(text_format("Fullscreen", "ON"));
            SDL_SetWindowFullscreen(Global::window, true);
        }
        else {
            change_text(text_format("Fullscreen", "OFF"));
            SDL_SetWindowFullscreen(Global::window, false);
        }

    }
    ButtonFullscreen(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        id = 0;
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void switch_param() {
        const char* text;
        GameOptions::Fullscreen = !GameOptions::Fullscreen;
        load_text();
    }


    void on_mouse_clicked() override {
        switch_param();
    }
    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                        switch_param();
                        break;
                    case SDL_SCANCODE_RIGHT:
                        switch_param();
                        break;
                }

        }
    }
    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};

void change_volume(int& num, char mod) {
    if (mod == '+')
        num += 10;
    else {
        num -= 10;
    }
    if (num > 100)
        num = 100;
    else if (num < 0)
        num = 0;
}


#define MyOptionVar GameOptions::Main_Volume
struct ButtonMainVolume : public TextRect {
    void load_text() {
        change_text(text_format("Main Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    ButtonMainVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


#define MyOptionVar GameOptions::BGM_Volume
struct ButtonBGMVolume : public TextRect {
    void load_text() {
        change_text(text_format("BGM Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    ButtonBGMVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


#define MyOptionVar GameOptions::BGS_Volume
struct ButtonBGSVolume : public TextRect {
    void load_text() {
        change_text(text_format("BGS Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    ButtonBGSVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


#define MyOptionVar GameOptions::SE_Volume
struct ButtonSEVolume : public TextRect {
    void load_text() {
        change_text(text_format("SE Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    ButtonSEVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


#define MyOptionVar GameOptions::Sister_Volume
struct ButtonSisterVolume : public TextRect {
    void load_text() {
        change_text(text_format("Sister Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    ButtonSisterVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


#define MyOptionVar GameOptions::Max_Player_Msgs
struct ButtonMaxPlayerMsgs : public TextRect {
    void load_text() {
        change_text(text_format("MaxPlayerMessages", std::format("{}", MyOptionVar).c_str()));
    }
    ButtonMaxPlayerMsgs(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, '+');

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, '-');
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, '+');
                        load_text();
                        break;
                }

        }
    }

    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};
#undef MyOptionVar


struct ButtonShwWpnDr : public TextRect {
    void load_text() {
        if (GameOptions::Show_Weapon_Durability)
            change_text(text_format("Show Weapon Durability", "ON"));
        else
            change_text(text_format("Show Weapon Durability", "OFF"));
    }
    ButtonShwWpnDr(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void switch_param() {
        const char* text;
        GameOptions::Show_Weapon_Durability = !GameOptions::Show_Weapon_Durability;
        load_text();
    }


    void on_mouse_clicked() override {
        switch_param();
    }
    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        switch_param();
                        break;
                case SDL_SCANCODE_RIGHT:
                        switch_param();
                        break;
                }

        }
    }
    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};