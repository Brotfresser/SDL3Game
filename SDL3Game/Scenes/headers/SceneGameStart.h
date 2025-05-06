#pragma once
#include "BaseScene.h"
#include "SceneMainMenu.h"

struct SceneGameStart: BaseScene
{
private:
	SceneGameStart(const SceneGameStart&) = delete;
	SceneGameStart& operator =(const SceneGameStart&) = delete;
public:
	SceneGameStart(SDL_Renderer* renderer);
	EventType event(SDL_Event* event) override;
	EventType draw() override;
	EventType update() override;
	~SceneGameStart() override;
};

