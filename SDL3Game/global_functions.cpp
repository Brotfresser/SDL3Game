#include "global_functions.h"
#include "global_variables.h"

namespace Global {
    void openWebsite(std::string url) {
#ifdef _WIN32
        std::string command = "start ";
#elif __APPLE__
        std::string command = "open " +;
#else // Linux и другие Unix-системы
        std::string command = "xdg-open ";
#endif
        command += "https://nlch.itch.io/sister";
        system(command.c_str());
    }

        void changeScene(BaseScene *scene) {
            Global::new_scene_ptr = scene;
            Global::event = EventType::SCENE_SWITCH_REQUEST;
        }
}