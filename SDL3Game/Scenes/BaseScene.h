#pragma once
#include <SDL3/SDL.h>
#include "../BaseSprite.h"
#include <list>

enum EventType {
	EVENT_NONE,
	SCENE_SWITCH_REQUEST
};

struct BaseScene
{
protected:
	// ��������� �� �����, ������� ����� ����������
	SDL_Renderer* renderer;
	// ��������� �� ����� �����, �� ������� ����� ����� �������������
	BaseScene* new_scene_ptr = nullptr;
	BaseScene(const BaseScene&) = delete;
	BaseScene& operator =(const BaseScene&) = delete;
public:
	std::list<BaseSprite*> all_sprites;

	BaseScene(SDL_Renderer* renderer);
	// main.cpp ������������� �������� get_new_scene_ptr ����� �������� EventType::SCENE_SWITCH_REQUEST
	BaseScene* get_new_scene_ptr();
	virtual EventType event(SDL_Event* event) = 0;
	virtual EventType draw() = 0;
	virtual EventType update() = 0;
	virtual ~BaseScene() = 0;

	// � ������ � �������, ����� ������������� �������� ��� ������ �������?
	// ��� ������������� ����� ������ ������� ������ ������ ������������� ������ � �.�.?
};

