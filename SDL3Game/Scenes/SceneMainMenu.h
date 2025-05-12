#pragma once
#include "BaseScene.h"


class SceneMainMenu: public BaseScene
{
	SceneMainMenu(const SceneMainMenu&) = delete;
	SceneMainMenu& operator =(const SceneMainMenu&) = delete;
public:
	SceneMainMenu(SDL_Renderer* renderer);
	EventType event(SDL_Event* event) override;
	EventType draw() override;
	EventType update() override;
	~SceneMainMenu() override;
};

