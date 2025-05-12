#pragma once
#include "Player.h"

#ifdef __MAIN_GLOBAL_DEFINITION__
#define GLOBAL(type, name, value) type name = value
#else
#define GLOBAL(type, name, value) extern type name
#endif


namespace Global {
	GLOBAL(SDL_Window*, window, nullptr);
	GLOBAL(float, MouseX, 0);
	GLOBAL(float, MouseY, 0);

	GLOBAL(EventType, event, EventType::NONE);
	// указатель на новую сцену, на которую нужно будет переключиться
	GLOBAL(BaseScene*, new_scene_ptr, nullptr);
	GLOBAL(Player*, player, nullptr);

}