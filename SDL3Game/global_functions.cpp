#include "global_functions.h"
#include "global_variables.h"
#include <fstream>


namespace Global {
//     void openWebsite(const std::string& url) {
// #ifdef _WIN32
//         std::string command = "start ";
// #elif __APPLE__
//         std::string command = "open " +;
// #else // Linux
//         std::string command = "xdg-open ";
// #endif
//         command += url;
//         system(command.c_str());
//     }

    double GetTimeInSeconds() {
        return static_cast<double>(SDL_GetTicksNS()) / 1'000'000'000.0;
    }

    void CloseGame() {
        Global::event = EventType::GAME_CLOSE;
    }
}