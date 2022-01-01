#include "Gate.h"

#include <cmath>
using namespace std;

Gate::Gate(float point1x, float point1y, float point2x, float point2y) : collidedLastFrame(false) {
    this->point1x = point1x;
    this->point1y = point1y;
    this->point2x = point2x;
    this->point2y = point2y;
  
}

void Gate::draw(Interface& interface)
{
    interface.drawGate(point1x, point1y, point2x, point2y);
}

Vector2D Gate::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame 
        && abs(point1y - ball.getCenter().y) < ball.getRadius() 
        && (ball.getVelocity().y) > 0 
        && ball.getCenter().x > point1x 
        && ball.getCenter().x < point2x)
    {
        collidedLastFrame = true;
        return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime; 
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}

Obstacle* Gate::ReadGates_fromFile(ifstream& Here_Is_obstacle) {

    float GateArray[4];
    for (int k = 0; k < 4; k++) {
        Here_Is_obstacle >> GateArray[k];
    }
    Gate* Gate1 = new Gate(GateArray[0], GateArray[1], GateArray[2], GateArray[3]);
    return Gate1;
}