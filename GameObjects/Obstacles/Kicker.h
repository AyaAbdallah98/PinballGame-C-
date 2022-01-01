#pragma once
#include "Obstacle.h"

//It represents a flipper, which is like a right angled triangle, and the ball can hit any of the three sides and bounces off.

class Kicker : public Obstacle
{
private:
    float p1x, p1y, p2x, p2y, p3x, p3y;  // The position of the three points that form the triangle (flipper)
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    float get_p1x();
    float get_p1y();
    float get_p2x();
    float get_p2y();
    float get_p3x();
    float get_p3y();
    void set_p1x(float x1);
    void set_p1y(float y1);
    void set_p2x(float x2);
    void set_p2y(float y2);
    void set_p3x(float x3);
    void set_p3y(float y3);
    explicit Kicker(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle * ReadKickers_fromFile(ifstream& HereIsobstacle);
};

