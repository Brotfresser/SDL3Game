#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Sprite.h"
#include "TextRect.h"
#include "timer.h"

#include <list>
#include <iostream>


#ifndef STDSTRING
#include <string>
#define STDSTRING
#endif

using std::cout;
using std::endl;



static SDL_Window* window;
static SDL_Renderer* renderer;

Timer timer;
static std::list<Sprite*> all_sprites_to_draw;
Sprite* player;
TextRect* main_text;

int IterateDelay = 1000 / 60;


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer("My Game", 640, 480, 0, &window, &renderer);
    player = new Sprite(renderer, "assets/hero/hero.png", 32, 32, 100, 300);
    main_text = new TextRect(renderer);
    all_sprites_to_draw.push_back(player);
    all_sprites_to_draw.push_back(main_text);
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
        switch (event->key.scancode)
        {
        case SDL_SCANCODE_ESCAPE:
            return SDL_APP_SUCCESS;
        case SDL_SCANCODE_E:
            all_sprites_to_draw.push_back(new Sprite(renderer, "assets/hero/hero.png", 32, 32));
            break;
        }
    }
    for (auto& sprite : all_sprites_to_draw)
        sprite->handleEvents();
    return SDL_APP_CONTINUE;
} 


void render_draw_all() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
     
    for (auto& sprite : all_sprites_to_draw)
        sprite->draw();
    SDL_RenderPresent(renderer);
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
    if (timer) {
        cout << double(SDL_GetTicks())/1000 << endl;
        timer(1);
    }
    static int value = 0;
    main_text->change_text(std::to_string(value));
    ++value;
    for (auto& sprite : all_sprites_to_draw)
        sprite->update();
    render_draw_all();
    SDL_Delay(IterateDelay);
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{

}