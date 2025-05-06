#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>


#include "Sprite.h"
#include "Player.h"
#include "TextRect.h"  // <string>
#include "Scenes/headers/SceneMainMenu.h"
#include "timer.h"

#define __MAIN_GLOBAL_DEFINITION__
#include "global_variables.h"

#include <iostream>

using std::cout;
using std::endl;


static SDL_Window* window;
static SDL_Renderer* renderer;

Timer timer;
float MouseX, MouseY;
BaseScene* prev_scene = nullptr;
BaseScene* current_scene;

int IterateDelay = 1000 / 60;


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{        
    setlocale(LC_ALL, "Russian");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer("My Game", 640, 480, 0, &window, &renderer);
    current_scene = new SceneMainMenu(renderer);
    return SDL_APP_CONTINUE;
}


void change_scene(BaseScene* new_scene) {
    delete current_scene;
    current_scene = new_scene;
}


void handleSceneEvents(EventType event) {
    switch (event)
    {
    case EventType::SCENE_SWITCH_REQUEST:
        prev_scene = current_scene;
        current_scene = current_scene->get_new_scene_ptr();
        delete prev_scene;
        break;
    default:
        break;
    }
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    
    SDL_GetMouseState(&MouseX, &MouseY);

    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    }
    for (auto& sprite : current_scene->all_sprites)
        if (sprite->is_in_rect(MouseX, MouseY))
            if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
                sprite->on_mouse_clicked();

    handleSceneEvents(current_scene->event(event));
    return SDL_APP_CONTINUE;
} 


void render_draw_all() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    handleSceneEvents(current_scene->draw());
    SDL_RenderPresent(renderer);
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
    
    if (timer) {
        //cout << double(SDL_GetTicks())/1000 << endl;
        timer(1);
    }
    for (auto& sprite : current_scene->all_sprites)
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_INPUT_FOCUS && sprite->is_in_rect(MouseX, MouseY))
            sprite->is_mouse_over = true;
        else
            sprite->is_mouse_over = false;

    handleSceneEvents(current_scene->update());
    render_draw_all();
    SDL_Delay(IterateDelay);
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    TTF_Quit();
    SDL_Quit();
}