#pragma once
#include "Bumper.h"

class PopBumper : public Bumper
{
protected:
    bool collidedPopBumper;
public:
    PopBumper(float radius, Vector2D center);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime);
    static Obstacle* readPopBumper(ifstream& file);
};