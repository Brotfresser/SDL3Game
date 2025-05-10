#pragma once
#include "SceneMainMenu.h"

class SceneGameStart: public BaseScene
{
	SceneGameStart(const SceneGameStart&) = delete;
	SceneGameStart& operator =(const SceneGameStart&) = delete;
public:
	SceneGameStart(SDL_Renderer* renderer);
	EventType event(SDL_Event* event) override;
	EventType draw() override;
	EventType update() override;
	~SceneGameStart() override;
};

