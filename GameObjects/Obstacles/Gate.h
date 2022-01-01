#pragma once

#include "Obstacle.h"

//It represents a gate, which is like a line segment, and the ball will bounce off if it hit it from below, and pass smoothly if it hit it from above.

class Gate : public Obstacle
{
private:
    float point1x, point1y, point2x, point2y;  // The position of the two points that form the line segment
    bool collidedLastFrame;  // Whether or not the last frame was a collision 

public:
    explicit Gate(float point1x, float point1y, float point2x, float point2y);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadGates_fromFile(ifstream& HereIsobstacle);
};

