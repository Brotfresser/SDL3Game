#include "SwitchSceneFabric.h"
#include <global_variables.h>

#include "Scenes/SceneMainMenu.cpp"
#include "Scenes/SceneMainMenu/SceneLoad.cpp"
#include "Scenes/SceneMainMenu/SceneOptions.cpp"
#include "Scenes/SceneGameStart.cpp"

namespace SceneFabric {
    std::unique_ptr<BaseScene> get_new_scene_ptr(int scene_id) {
        using std::make_unique;

        switch (scene_id) {
            case AllScenesID::MainMenu:
                return make_unique<SceneMainMenu>(Global::renderer);
            case AllScenesID::LoadGame:
                return make_unique<SceneLoad>(Global::renderer);
            case AllScenesID::Options:
                return make_unique<SceneOptions>(Global::renderer);
            case AllScenesID::GameStart:
                return make_unique<SceneGameStart>(Global::renderer);
            default:
                return make_unique<SceneMainMenu>(Global::renderer);
        }
    }

    void SwitchScene(const int scene_id) {
        Global::new_scene_ptr = SceneFabric::get_new_scene_ptr(scene_id);
        Global::event = EventType::SCENE_SWITCH_REQUEST;
    }
}