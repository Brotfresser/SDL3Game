#pragma once
#include <SDL3/SDL.h>


class Timer {
	double wait_time = 0;
	double first_time = SDL_GetTicks() / 1000;	

public:
	Timer();
	Timer(double wait_time);
	void operator () (double time_seconds);
	operator bool();
};