#pragma once
#include <Sprites/TextClass/TextRect.h>

struct TextRectWithShadow : TextRect
{
    TextRect* shadow;
    float shadow_delta_x = 1, shadow_delta_y = 1;

    explicit TextRectWithShadow(SDL_Renderer* renderer, std::string text = "Sample text", float x = 200, float y = 200,
        SDL_Color text_color = SDL_TEXT_COLOR_WHITE,
        float text_size = 16, const char* file = "assets/fonts/FOT-NewCinemaAStd-D.otf",
        float shadow_delta_x = 1, float shadow_delta_y = 1
        );

    ~TextRectWithShadow() override;
    void load_texture(float w = 0, float h = 0) override;
    void draw() override;

    void change_font(std::string path_to_file) override;
    void change_text_color(SDL_Color new_color) override;
    void change_text_size(float new_text_size) override;
    void change_text(std::string new_text) override;

};
