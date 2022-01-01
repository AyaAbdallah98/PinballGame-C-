#include "Ceiling.h"

#include <cmath>
using namespace std;

Ceiling::Ceiling(float position) : position(position), collidedLastFrame(false) {}

void Ceiling::draw(Interface& interface)
{
    interface.drawCeiling(position);
}

Vector2D Ceiling::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame && abs(position - ball.getCenter().y) < ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D{0 , ball.getVelocity().y * -2 } / collisionTime; //since the rule of impulse is F*t=m*(v2-v1), a*t=v2-v1
         //v2=-v1, v2-v1=-2v1, ay=-2*v1y/t
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

Obstacle* Ceiling::ReadCeiling_fromFile(ifstream& Ceilingfile) {
    float CeilingArray;
    Ceilingfile >> CeilingArray;
    Ceiling* Ceiling1 = new Ceiling(CeilingArray);
    return Ceiling1;
}


