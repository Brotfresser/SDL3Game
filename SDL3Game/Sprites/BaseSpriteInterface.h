#pragma once


struct BaseSpriteInterface {
    virtual ~BaseSpriteInterface() = default;

    virtual void load_texture(float w = 0, float h = 0) = 0;
    virtual void load_texture(const char* path_to_file, float w = 0, float h = 0) = 0;
    virtual void draw() = 0;
    virtual void update()= 0;
    virtual void handleEvents(SDL_Event* event) = 0;
    virtual void on_mouse_clicked() = 0;
    virtual void on_mouse_enter() = 0;
    virtual void on_mouse_exit() = 0;
    virtual bool is_in_rect(float x, float y) const = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;

    virtual const char* get_path_to_file() const = 0;
    virtual SDL_Texture* get_texture() const = 0;
    virtual float get_rect_w_original() const = 0;
    virtual float get_rect_h_original() const = 0;
};
