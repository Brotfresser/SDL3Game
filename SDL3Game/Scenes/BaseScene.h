#pragma once
#include <SDL3/SDL.h>
#include <list>
#include "../BaseSprite.h"


struct BaseScene
{
protected:
	// указатель на буфер, который нужно отобразить
	SDL_Renderer* renderer;

	BaseScene(const BaseScene&) = delete;
	BaseScene& operator =(const BaseScene&) = delete;
public:
	std::list<BaseSprite*> all_sprites;

	BaseScene(SDL_Renderer* renderer);
	virtual EventType event(SDL_Event* event) = 0;
	virtual EventType draw() = 0;
	virtual EventType update() = 0;
	virtual ~BaseScene() = 0;
};

