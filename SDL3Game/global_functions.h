//
// Created by Brotfresser on 12.05.2025.
//

#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H
#include <string>

#include "Scenes/BaseScene.h"

namespace Global {
    void openWebsite(std::string url);
    void changeScene(BaseScene* scene);
    void CloseGame();
}
#endif //GLOBAL_FUNCTIONS_H
