#pragma once
#include "Sprite.h"
#include <SDL3/SDL.h>

struct Player: public Sprite
{
	Player(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
	void update() override;
};

