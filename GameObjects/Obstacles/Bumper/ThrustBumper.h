#pragma once
#include "Bumper.h"

class ThrustBumper : public Bumper
{
protected:
    bool collidedThrustBumper;
public:
    ThrustBumper(float radius, Vector2D center);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime);
    static Obstacle* readThrustBumper(ifstream& file);
};
