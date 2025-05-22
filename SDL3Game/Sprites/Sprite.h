#pragma once
#include <SDL3/SDL.h>
#include "BaseSprite.h"


struct Sprite: BaseSprite
{
	Sprite(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
	void load_texture(float w = 0, float h = 0) override;
};

