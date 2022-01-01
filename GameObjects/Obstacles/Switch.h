#pragma once

#include "Obstacle.h"


class Switch : public Obstacle
{
private:
    float pointx1, pointy1, pointx2, pointy2;  // The position of the two points that form the line segment
    bool collidedLastFrame;  // Whether or not the last frame was a collision 
    int COUNT;
public:
    explicit Switch(float pointx1, float pointy1, float pointx2, float pointy2);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* readSwitch(ifstream& HereIsobstacle);
};
