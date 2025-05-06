#pragma once
#include "Player.h"

#ifdef __MAIN_GLOBAL_DEFINITION__
#define GLOBAL(type, name, value) type name = value
#else
#define GLOBAL(type, name, value) extern type name
#endif


namespace Global {
	GLOBAL(int, var, 0);
	GLOBAL(Player*, player, nullptr);
}