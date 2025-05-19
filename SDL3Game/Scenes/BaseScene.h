#pragma once
#include <SDL3/SDL.h>
#include <list>
#include "../Sprites/BaseSprite.h"
#include "UIMenuButtons.h"


struct BaseScene
{
protected:
	// ��������� �� �����, ������� ����� ����������
	SDL_Renderer* renderer;

	BaseScene(const BaseScene&) = delete;
	BaseScene& operator =(const BaseScene&) = delete;
public:
	all_sprites_container all_sprites;

	BaseScene(SDL_Renderer* renderer);
	virtual EventType event(SDL_Event* event) = 0;
	virtual EventType draw();
	virtual EventType update() = 0;
	// ������������� delete all_sprites
	virtual ~BaseScene();
};

