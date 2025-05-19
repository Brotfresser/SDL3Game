#include <Sprites/TextRect.h>
#include <format>
#include <global_options.h>


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
struct ButtonFullscreen final : TextRect {
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
    explicit ButtonFullscreen(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        id = 0;
        load_text();
        x = 1920.0 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void switch_param() {
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
                    case SDL_SCANCODE_RIGHT:
                        switch_param();
                        break;
                    default: ;
                }
            default: ;
        }
    }
    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};


static void change_volume(int& num, const int mod, int mx = 100) {
    num += mod;

    if (num > mx)
        num = mx;
    else if (num < 0)
        num = 0;
}


#define MyOptionVar GameOptions::Main_Volume
struct ButtonMainVolume final : public TextRect {
    void load_text() {
        change_text(text_format("Main Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    explicit ButtonMainVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920.0 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                            change_volume(MyOptionVar, -10);
                            load_text();
                            break;
                    case SDL_SCANCODE_RIGHT:
                            change_volume(MyOptionVar, 10);
                            load_text();
                            break;
                    default: ;
                }
            default: ;
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
struct ButtonBGMVolume final : public TextRect {
    void load_text() {
        change_text(text_format("BGM Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    explicit ButtonBGMVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                            change_volume(MyOptionVar, -10);
                            load_text();
                            break;
                    case SDL_SCANCODE_RIGHT:
                            change_volume(MyOptionVar, 10);
                            load_text();
                            break;
                    default: ;
                }
            default: ;
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
struct ButtonBGSVolume final : public TextRect {
    void load_text() {
        change_text(text_format("BGS Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    explicit ButtonBGSVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                            change_volume(MyOptionVar, -10);
                            load_text();
                            break;
                    case SDL_SCANCODE_RIGHT:
                            change_volume(MyOptionVar, 10);
                            load_text();
                            break;
                    default: ;
                }
            default: ;
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
struct ButtonSEVolume final : public TextRect {
    void load_text() {
        change_text(text_format("SE Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    explicit ButtonSEVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                case SDL_SCANCODE_LEFT:
                        change_volume(MyOptionVar, -10);
                        load_text();
                        break;
                case SDL_SCANCODE_RIGHT:
                        change_volume(MyOptionVar, 10);
                        load_text();
                        break;
                    default: ;
                }
            default: ;
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
struct ButtonSisterVolume final : public TextRect {
    void load_text() {
        change_text(text_format("Sister Volume", std::format("{}%", MyOptionVar).c_str()));
    }
    explicit ButtonSisterVolume(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                            change_volume(MyOptionVar, -10);
                            load_text();
                            break;
                    case SDL_SCANCODE_RIGHT:
                            change_volume(MyOptionVar, 10);
                            load_text();
                            break;
                    default: ;
                }
            default: ;
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
struct ButtonMaxPlayerMsgs final : public TextRect {
    void load_text() {
        change_text(text_format("MaxPlayerMessages", std::format("{}", MyOptionVar).c_str()));
    }
    explicit ButtonMaxPlayerMsgs(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void on_mouse_clicked() override {
        change_volume(MyOptionVar, 10);

        load_text();
    }

    void handleEvents(SDL_Event *event) override {
        switch (event->type) {
            case SDL_EVENT_KEY_DOWN:
                switch (event->key.scancode) {
                    case SDL_SCANCODE_LEFT:
                            change_volume(MyOptionVar, -1);
                            load_text();
                            break;
                    case SDL_SCANCODE_RIGHT:
                            change_volume(MyOptionVar, 1);
                            load_text();
                            break;
                    default: ;
                }
            default: ;
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


struct ButtonShwWpnDr final : public TextRect {
    void load_text() {
        if (GameOptions::Show_Weapon_Durability)
            change_text(text_format("Show Weapon Durability", "ON"));
        else
            change_text(text_format("Show Weapon Durability", "OFF"));
    }
    explicit ButtonShwWpnDr(SDL_Renderer* renderer) : TextRect(renderer, "-", 0, 0,
        SDL_TEXT_COLOR_WHITE, 50, "assets/fonts/Haiyanzhishidongdong-Regular-2.ttf")
    {
        load_text();
        x = 1920 / 2 - rect_w / 2;
        y = start_y + deltaY * get_id_y();
        SDL_SetTextureAlphaMod(texture, 128);
    }
    void switch_param() {
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
                    case SDL_SCANCODE_RIGHT:
                            switch_param();
                            break;
                        default: ;
                }
            default: ;
        }
    }
    void on_mouse_enter() override {
        SDL_SetTextureAlphaMod(texture, 255);
    }
    void on_mouse_exit() override {
        SDL_SetTextureAlphaMod(texture, 128);
    }
};