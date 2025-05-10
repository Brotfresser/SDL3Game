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
	// указатель на буфер, который нужно отобразить
	SDL_Renderer* renderer;
	// указатель на новую сцену, на которую нужно будет переключитьс€
	BaseScene* new_scene_ptr = nullptr;
	BaseScene(const BaseScene&) = delete;
	BaseScene& operator =(const BaseScene&) = delete;
public:
	std::list<BaseSprite*> all_sprites;

	BaseScene(SDL_Renderer* renderer);
	// main.cpp автоматически вызывает get_new_scene_ptr когда получает EventType::SCENE_SWITCH_REQUEST
	BaseScene* get_new_scene_ptr();
	virtual EventType event(SDL_Event* event) = 0;
	virtual EventType draw() = 0;
	virtual EventType update() = 0;
	virtual ~BaseScene() = 0;

	// в сценах с игроком, нужно реализовывать подсцены дл€ каждой комнаты?
	// или переключатьс€ между каждой игровой сценой занова инициализиру€ игрока и т.д.?
};

