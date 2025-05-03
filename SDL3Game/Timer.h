#pragma once


class Timer {
	double first_time;
	double wait_time;

public:
	void operator () (double time_seconds);
	operator bool();
};