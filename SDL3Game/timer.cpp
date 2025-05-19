#include "Timer.h"


Timer::Timer() = default;

Timer::Timer(const double wait_time) {
	(*this)(wait_time);
}


void Timer::operator () (const double time_seconds) {
	this->first_time = static_cast<double>(SDL_GetTicksNS()) / 1'000'000'000;
	this->wait_time = time_seconds;
}


Timer::operator bool () const {
	return (first_time + wait_time) < static_cast<double>(SDL_GetTicksNS()) / 1'000'000'000;
}