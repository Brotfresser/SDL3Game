#pragma once
#include <SDL3/SDL.h>
#include "BaseSprite.h"


class Sprite: public BaseSprite
{
public:
	Sprite(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
	virtual void load_texture(float w = 0, float h = 0) override;
};

