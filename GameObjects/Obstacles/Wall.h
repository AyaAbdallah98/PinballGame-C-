#pragma once

#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class Wall: public Obstacle
{
private:
    float position;  // The horizontal position of the wall
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    //Wall();
    explicit Wall(float position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball & ball, float collisionTime) override;
    void set_wallPosition(float Position);
    static Obstacle* ReadWalls_fromFile(ifstream& HereIsobstacle);
};



