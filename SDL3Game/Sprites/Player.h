#pragma once
#include "Sprite.h"
#include <SDL3/SDL.h>

#include "SpriteWithAnimation.h"

struct Player: public SpriteWithAnimation
{
	float speed = 500;
	Player(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0);
	void update() override;
};

