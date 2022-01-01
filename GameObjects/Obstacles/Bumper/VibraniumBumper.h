#pragma once
#include "Bumper.h"

class VibraniumBumper : public Bumper
{
protected:
    bool collidedVibraniumBumper;
public:
    VibraniumBumper(float radius, Vector2D center);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime);
    static Obstacle* readVibraniumBumper(ifstream& file);
};
