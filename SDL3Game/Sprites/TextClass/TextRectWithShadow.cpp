#include "TextRectWithShadow.h"

TextRectWithShadow::TextRectWithShadow(SDL_Renderer *renderer, std::string text, float x, float y,
                                       SDL_Color text_color, float text_size, const char *file,
                                       float shadow_delta_x, float shadow_delta_y)

    :TextRect(renderer, text, x, y, text_color, text_size, file)
{
    this->shadow_delta_x = shadow_delta_x;
    this->shadow_delta_y = shadow_delta_y;
    shadow = new TextRect(renderer, text, x + shadow_delta_x, y + shadow_delta_y, SDL_TEXT_COLOR_BLACK, text_size, file);
}


TextRectWithShadow::~TextRectWithShadow() {
    delete shadow;
}

void TextRectWithShadow::load_texture(float w, float h) {
    TextRect::load_texture(w, h);
    shadow->load_texture(w, h);
}

void TextRectWithShadow::draw() {
    shadow->x = this->x + shadow_delta_x;
    shadow->y = this->y + shadow_delta_y;
    shadow->draw();
    TextRect::draw();
}

void TextRectWithShadow::change_font(std::string path_to_file) {
    TextRect::change_font(path_to_file);
    shadow->change_font(path_to_file);
}

void TextRectWithShadow::change_text_color(SDL_Color new_color) {
    TextRect::change_text_color(new_color);
    shadow->change_text_color(new_color);
}

void TextRectWithShadow::change_text_size(float new_text_size) {
    TextRect::change_text_size(new_text_size);
    shadow->change_text_size(new_text_size);
}

void TextRectWithShadow::change_text(std::string new_text) {
    TextRect::change_text(new_text);
    shadow->change_text(new_text);
}