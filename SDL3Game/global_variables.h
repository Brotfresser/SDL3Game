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

	GLOBAL(Player*, player, nullptr);

}