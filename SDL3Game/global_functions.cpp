#include "global_functions.h"

#include <cstdlib>

void openWebsite(const std::string& url) {
#ifdef _WIN32
    std::string command = "start ";
#elif __APPLE__
    std::string command = "open " +;
#else // Linux и другие Unix-системы
    std::string command = "xdg-open ";
#endif
    command + url;
    system(command.c_str());
}
// // получается серый экран. мб вызывать в main после SDL_RenderPresent(renderer); ?
//SDL_Texture* Global::TakeScreenshot(SDL_Renderer* renderer) {
//    int width = 0, height = 0;
//    if (!SDL_GetWindowSizeInPixels(Global::window, &width, &height)) {
//        SDL_Log("Failed to GetWindowSize: %s", SDL_GetError());
//        return nullptr;
//    }
//
//    SDL_Surface* surface = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_RGBA32);
//    if (!surface) {
//        SDL_Log("Failed to create surface: %s", SDL_GetError());
//        return nullptr;
//    }
//    surface = SDL_RenderReadPixels(renderer, NULL);
//    if (!surface) {
//        SDL_Log("Failed to SDL_RenderReadPixels: %s", SDL_GetError());
//        return nullptr;
//    }
//
//
//    SDL_Texture* screenshotTexture = SDL_CreateTextureFromSurface(renderer, surface);
//    SDL_DestroySurface(surface);
//
//    if (!screenshotTexture) {
//        SDL_Log("Failed to create texture: %s", SDL_GetError());
//        return nullptr;
//    }
//    return screenshotTexture;
//}