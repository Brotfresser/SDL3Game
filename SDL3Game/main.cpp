#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Scenes/SceneMainMenu.h"
#include "Sprite.h"
#define __MAIN_GLOBAL_DEFINITION__
#include <iostream>
#include "global_options.h"
#include "save_and_load.h"
#include "global_variables.h"

const char* GameTitle = "A Simple Life with My Unobtrusive Sister on BreadEngine";
static SDL_Window* window;
static SDL_Renderer* renderer;

int WindowX = 1280, WindowY = 920;
float MouseX, MouseY;
BaseScene* prev_scene = nullptr;
BaseScene* current_scene;

int IterateDelay = 1000 / 60;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    load_options();
    setlocale(LC_ALL, "Russian");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer(GameTitle, WindowX, WindowY, SDL_WINDOW_RESIZABLE, &window, &renderer);
    if (GameOptions::Fullscreen)
        SDL_SetWindowFullscreen(window, true);

    SDL_SetRenderLogicalPresentation(renderer, 1920, 1080, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_Event window_resize;
    window_resize.type = SDL_EVENT_WINDOW_RESIZED;
    SDL_PushEvent(&window_resize);
    Global::window = window;
    current_scene = new SceneMainMenu(renderer);
    return SDL_APP_CONTINUE;
}


SDL_AppResult handleSceneEvents(EventType event) {
    switch (event)
    {
        case EventType::SCENE_SWITCH_REQUEST:
            SDL_Log("SCENE_SWITCH_REQUEST");
            Global::event = EventType::NONE;
            prev_scene = current_scene;
            current_scene = Global::new_scene_ptr;
            Global::new_scene_ptr = nullptr;
            delete prev_scene;
            break;
    case EventType::GAME_CLOSE:
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

int Letterboxing_w, Letterboxing_h;
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_MOUSE_MOTION:
        SDL_GetMouseState(&MouseX, &MouseY);
        //                            
        MouseX = (MouseX - Letterboxing_w / 2) * ((WindowX - Letterboxing_w / 2) / (WindowX - Letterboxing_w));
        MouseY = (MouseY - Letterboxing_h / 2) * ((WindowY - Letterboxing_h / 2) / (WindowY - Letterboxing_h));

        //                     1920 1080
        MouseX *= float(1920) / (WindowX - Letterboxing_w);
        MouseY *= float(1080) / (WindowY - Letterboxing_h);

        Global::MouseX = MouseX;
        Global::MouseY = MouseY;
        break;
    case SDL_EVENT_WINDOW_RESIZED:
        SDL_GetWindowSize(window, &WindowX, &WindowY);
        float k = std::min((float)WindowX / 1920, (float)WindowY / 1080);
        Letterboxing_w = WindowX - (1920 * k);
        Letterboxing_h = WindowY - (1080 * k);
        break;
    }

    return handleSceneEvents(current_scene->event(event));
} 


void render_draw_all() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    handleSceneEvents(current_scene->draw());
    SDL_RenderPresent(renderer);
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
    SDL_AppResult to_return = SDL_APP_CONTINUE;
    //SDL_Log("SDL_AppIterate");
    if (Global::new_scene_ptr == nullptr)
        to_return = handleSceneEvents(current_scene->update());
    render_draw_all();
    SDL_Delay(IterateDelay);
    return to_return;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    save_options();
    TTF_Quit();
    SDL_Quit();
}