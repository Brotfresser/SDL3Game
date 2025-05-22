#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#define __MAIN_GLOBAL_DEFINITION__
#include <ctime>

#include "global_options.h"
#include "save_and_load.h"
#include "global_variables.h"
#include "SwitchSceneFabric.h"

const char* GameTitle = "A Simple Life with My Unobtrusive Sister on BreadEngine";
static SDL_Window* window;
static SDL_Renderer* renderer;

int WindowX = 1280, WindowY = 920;
float MouseX, MouseY;
std::unique_ptr<BaseScene> current_scene;
FILE* log_file = fopen("log.txt", "w");


void SDL_LogToFile(void* userdata, int category, const SDL_LogPriority priority, const char* message) {
    const auto log_file = static_cast<FILE *>(userdata);

    // Получаем текущее время
    time_t rawTime;
    char timeBuffer[40];  // Буфер для времени (формат: "HH:MM:SS")

    time(&rawTime);
    const tm *timeInfo = localtime(&rawTime);
    strftime(timeBuffer, sizeof(timeBuffer), "%d.%m.%Y %H:%M:%S", timeInfo);

    if (priority < SDL_LOG_PRIORITY_ERROR)
        fprintf(log_file, "[%s] %s\n", timeBuffer, message);
    else
        fprintf(log_file, "[%s] [ERROR] - %s\n", timeBuffer, message);
    fflush(log_file);  // Немедленная запись в файл
}


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
#ifdef NDEBUG
    SDL_SetLogOutputFunction(SDL_LogToFile, log_file);
#endif
    SDL_Log("---Game Started!---");
    load_options();
    setlocale(LC_ALL, "Russian");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer(GameTitle, WindowX, WindowY, SDL_WINDOW_RESIZABLE, &window, &renderer);

    if (!window || !renderer) {
        SDL_Log("Error creating window or renderer, %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (GameOptions::Fullscreen)
        SDL_SetWindowFullscreen(window, true);

    SDL_SetRenderLogicalPresentation(renderer, 1920, 1080, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_SetRenderVSync(renderer, true);

    SDL_Event window_resize;
    window_resize.type = SDL_EVENT_WINDOW_RESIZED;
    SDL_PushEvent(&window_resize);

    Global::window = window;
    Global::renderer = renderer;

    current_scene = SceneFabric::get_new_scene_ptr(AllScenesID::MainMenu);
    return SDL_APP_CONTINUE;
}


SDL_AppResult handleSceneEvents(EventType event) {
    switch (event)
    {
        case EventType::SCENE_SWITCH_REQUEST:
            SDL_Log("SCENE_SWITCH_REQUEST");
            Global::event = EventType::NONE;
            current_scene.swap(Global::new_scene_ptr);
            Global::new_scene_ptr.reset();
            break;
        case EventType::GAME_CLOSE:
            return SDL_APP_SUCCESS;
        default: ;
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
            MouseX *= static_cast<float>(1920) / (WindowX - Letterboxing_w);
            MouseY *= static_cast<float>(1080) / (WindowY - Letterboxing_h);

            Global::MouseX = MouseX;
            Global::MouseY = MouseY;
            break;
        case SDL_EVENT_WINDOW_RESIZED: {
            SDL_GetWindowSize(window, &WindowX, &WindowY);
            const float k = std::min(static_cast<float>(WindowX) / 1920, static_cast<float>(WindowY) / 1080);
            Letterboxing_w = WindowX - (1920 * k);
            Letterboxing_h = WindowY - (1080 * k);
            break;
        }
        default: ;
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
    auto to_return = SDL_APP_CONTINUE;
    if (Global::new_scene_ptr == nullptr)
        to_return = handleSceneEvents(current_scene->update());
    render_draw_all();
    //SDL_Delay(IterateDelay);
    return to_return;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    save_options();
    if (window)
        SDL_DestroyWindow(window);
    if (renderer)
        SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    SDL_Log("---ALlgood---");
    if (log_file)
        fclose(log_file);
}