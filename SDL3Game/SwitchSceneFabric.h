#pragma once
#include <memory>
#include <Scenes/BaseScene.h>


enum AllScenesID {
    MainMenu, LoadGame, Options, GameStart
};

namespace SceneFabric {
    std::unique_ptr<BaseScene> get_new_scene_ptr(int scene_id);
    void SwitchScene(int scene_id);
}


