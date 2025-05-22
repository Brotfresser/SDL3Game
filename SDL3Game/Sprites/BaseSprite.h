#pragma once
#include <SDL3/SDL.h>
#include "SpriteSmoothMove.h"
#include "BaseSpriteInterface.h"

enum EventType {
    NONE,
    SCENE_SWITCH_REQUEST,
    GAME_CLOSE
};

class BaseSprite : public BaseSpriteInterface
{
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    const char* path_to_file;
    SDL_FRect dstrect;
    // размеры спрайта в файле
    float rect_w, rect_h;

    BaseSprite(SDL_Renderer* renderer, const char* file, float x = 0, float y = 0);
public:
    SpriteSmoothMove smooth_move_data;
    float& x, & y;
    const float& w, h;
    // чтение из файла
    SDL_FRect srcrect;
    // множитель, раст€гивает спрайт
    float rect_w_k = 1, rect_h_k = 1;
    bool is_active = true;
        
    virtual ~BaseSprite();
    void load_texture(float w = 0, float h = 0) = 0;
    void load_texture(const char* path_to_file, float w = 0, float h = 0) override;
    void draw() override;
    void update() override;
    void handleEvents(SDL_Event* event) override;
    void on_mouse_clicked() override;
    void on_mouse_enter() override;
    void on_mouse_exit() override;
    bool is_in_rect(float x, float y) const override;
    virtual bool is_collided_with_sprite(const BaseSprite& obj);
    void activate() override;
    void deactivate() override;

    const char* get_path_to_file() const override;
    SDL_Texture* get_texture() const override;
    float get_rect_w_original() const override;
    float get_rect_h_original() const override;
};

