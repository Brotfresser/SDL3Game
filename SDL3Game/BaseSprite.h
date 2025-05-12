#pragma once
#include <SDL3/SDL.h>

enum EventType {
    NONE,
    SCENE_SWITCH_REQUEST,
    GAME_CLOSE
};

class BaseSprite
{
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    const char* path_to_file;
    SDL_FRect dstrect;
    SDL_FRect srcrect;
    float rect_w, rect_h;

    BaseSprite(SDL_Renderer* renderer, const char* file, float x = 0, float y = 0);
public:
    float& x, & y;
    // ??????????, ?????????? ?????????
    float rect_w_k = 1, rect_h_k = 1;
    bool is_active = true;
        
    virtual ~BaseSprite();
    virtual void load_texture(float w = 0, float h = 0) = 0;
    virtual void load_texture(const char* path_to_file, float w = 0, float h = 0);
    virtual void load_texture(SDL_Texture* new_texture) = 0;
    virtual void draw();
    virtual void update();
    virtual void handleEvents();
    virtual void on_mouse_clicked();
    virtual void on_mouse_enter();
    virtual void on_mouse_exit();
    virtual bool is_in_rect(float x, float y);
    virtual bool is_collided_with_sprite(const BaseSprite& obj);
    void activate();
    void deactivate();

    const char* get_path_to_file();
};

