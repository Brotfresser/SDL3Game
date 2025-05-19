#pragma once
#include <Sprites/Player.h>
#include <Scenes/BaseScene.h>
#include <memory>

#ifdef __MAIN_GLOBAL_DEFINITION__
#define GLOBAL(type, name, value) type name = value
#else
#define GLOBAL(type, name, value) extern type name
#endif


namespace Global {
	GLOBAL(SDL_Window*, window, nullptr);
	GLOBAL(SDL_Renderer*, renderer, nullptr);
	GLOBAL(float, MouseX, 0);
	GLOBAL(float, MouseY, 0);

	GLOBAL(EventType, event, EventType::NONE);
	// указатель на новую сцену, на которую игра сменится в main.cpp
	GLOBAL(std::unique_ptr<BaseScene>, new_scene_ptr, nullptr);
	GLOBAL(Player*, player, nullptr);

}