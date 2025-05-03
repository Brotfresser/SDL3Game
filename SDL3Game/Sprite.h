#pragma once
#include <SDL3/SDL.h>

class Sprite
{
protected:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    const char* path_to_file;
    SDL_FRect dstrect;
    SDL_FRect srcrect;
    float& x, & y;
    float& rect_w, & rect_h;

public:
	Sprite(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
    ~Sprite();
    void draw();
    void update();
    void handleEvents();
};

