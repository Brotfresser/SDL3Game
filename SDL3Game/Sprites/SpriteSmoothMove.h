#pragma once


struct SpriteSmoothMove {
    bool never_stop = false;
    bool is_active = false;
    bool checkCollision = false;
    float & spriteX, & spriteY;
    double start_x, start_y;
    double end_x, end_y;
    double end_time;
    double Vx, Vy;
    double start_time;

    SpriteSmoothMove(float& x, float& y);
    void update();
    void stop();
    void init_by_time(double end_x, double end_y, double time);
    void init_by_speed(double end_x, double end_y, double speed);
    void init_by_speed_inf(double end_x, double end_y);
};
