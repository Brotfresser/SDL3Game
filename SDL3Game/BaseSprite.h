#pragma once
#include <SDL3/SDL.h>

class BaseSprite
{
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    const char* path_to_file;
    SDL_FRect dstrect;
    SDL_FRect srcrect;

    BaseSprite(SDL_Renderer* renderer, const char* file, float x = 0, float y = 0);
public:
    float& x, & y;
    float& rect_w, & rect_h;
        
    virtual ~BaseSprite();
    virtual void load_texture(float w = 0, float h = 0) = 0;
    virtual void load_texture(const char* path_to_file, float w = 0, float h = 0);
    virtual void draw();
    virtual void update();
    virtual void handleEvents();
    virtual void on_clicked();
    virtual bool is_in_rect(float x, float y);
};

