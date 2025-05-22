#pragma once
#include "TextRect.h"


struct BaseTextEffect : BaseSpriteInterface {
    TextRect* text_rect;
    bool finished = true;

    BaseTextEffect(TextRect* text);
    ~BaseTextEffect() override;

    virtual void effect_on() = 0;
    bool is_finished() const;

    void load_texture(float w = 0, float h = 0) override;
    void load_texture(const char* path_to_file, float w = 0, float h = 0) override;
    void draw() override;
    void update() override;
    void handleEvents(SDL_Event* event) override;
    void on_mouse_clicked() override;
    void on_mouse_enter() override;
    void on_mouse_exit() override;
    bool is_in_rect(float x, float y) const override;
    void activate() override;
    void deactivate() override;

    const char* get_path_to_file() const override;
    SDL_Texture* get_texture() const override;
    float get_rect_w_original() const override;
    float get_rect_h_original() const override;
};
