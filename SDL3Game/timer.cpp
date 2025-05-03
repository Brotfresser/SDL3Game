#include "Timer.h"
#include <SDL3/SDL.h>


void Timer::operator () (double time_seconds) {
	this->first_time = double(SDL_GetTicks()) / 1000;
	this->wait_time = time_seconds;  // - 0.001 ?;
}


Timer::operator bool () {
	return (first_time + wait_time) < double(SDL_GetTicks()) / 1000;
}