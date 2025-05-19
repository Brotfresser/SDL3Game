#include "SpriteSmoothMove.h"
#include <cmath>
#include <global_functions.h>


SpriteSmoothMove::SpriteSmoothMove(float &x, float &y)
    :spriteX(x), spriteY(y)
{
    start_x = start_y = end_time = end_x = end_y = Vx = Vy = start_time = 0;
    is_active = false;
}


void SpriteSmoothMove::update() {
    if (!is_active)
        return;
    const double current_time = Global::GetTimeInSeconds() ;
    spriteX = start_x + Vx * (current_time - start_time);
    spriteY = start_y + Vy * (current_time - start_time);
    if (!never_stop && current_time >= end_time) {
        is_active = false;
        spriteX = end_x;
        spriteY = end_y;
    }
}

void SpriteSmoothMove::stop() {
    is_active = never_stop = false;
}


void SpriteSmoothMove::init_by_time(double end_x, double end_y, double time) {
    is_active = never_stop = false;
    start_x = spriteX; start_y = spriteY;
    this->end_x = end_x; this->end_y = end_y;
    Vx = (end_x - start_x) / time; Vy = (end_y - start_y) / time;
    start_time = Global::GetTimeInSeconds();
    end_time = time + start_time;
    is_active = true;
}


void SpriteSmoothMove::init_by_speed(double end_x, double end_y, double speed) {
    is_active = never_stop = false;
    start_x = spriteX; start_y = spriteY;
    this->end_x = end_x; this->end_y = end_y;
    const double c = sqrt(pow(end_x - start_x, 2) + pow(end_y - start_y, 2));
    const double time = c / speed;
    Vx = (end_x - start_x) / time; Vy = (end_y - start_y) / time;
    start_time = Global::GetTimeInSeconds();
    end_time = time + start_time;
    is_active = true;
}


void SpriteSmoothMove::init_by_speed_inf(double end_x, double end_y) {
    never_stop = true;
    start_x = spriteX; start_y = spriteY;
    Vx = end_x - start_x; Vy = end_y - start_y;
    start_time = Global::GetTimeInSeconds();
    this->end_x = this->end_y = end_time = 0;
    is_active = true;
}
