#pragma once
#include <SDL3/SDL.h>


class Timer {
	double wait_time = 0;
	double first_time = static_cast<double>(SDL_GetTicksNS()) / 1'000'000'000;

public:
	Timer();
	explicit Timer(double wait_time);
	void operator () (double time_seconds);
	explicit operator bool() const;
};