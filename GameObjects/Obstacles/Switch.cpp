#include "Switch.h"

#include <cmath>
using namespace std;

Switch::Switch(float pointx1, float pointy1, float pointx2, float pointy2) : collidedLastFrame(false) {
    this->pointx1 = pointx1;
    this->pointy1 = pointy1;
    this->pointx2 = pointx2;
    this->pointy2 = pointy2;
    COUNT = 0;
}

void Switch::draw(Interface& interface)
{
    interface.drawSwitch(pointx1, pointy1, pointx2, pointy2);
}

Vector2D Switch::collideWith(Ball& ball, float collisionTime)
{
    if (!collidedLastFrame
        && abs(pointy1 - ball.getCenter().y) < ball.getRadius()
        && ball.getCenter().x > pointx1
        && ball.getCenter().x < pointx2
        && COUNT == 0)
    {
        collidedLastFrame = false;
        COUNT++;
        return Vector2D{ 0, 0 };
    }
        else if (!collidedLastFrame
            && abs(pointy1 - ball.getCenter().y) < ball.getRadius()
            && ball.getCenter().x > pointx1
            && ball.getCenter().x < pointx2
            && COUNT == 1) {
            collidedLastFrame = true;
            return Vector2D{ 0, ball.getVelocity().y * -2 } / collisionTime;
        }
    
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
    
}

Obstacle* Switch::readSwitch(ifstream& Here_Is_obstacle) {

    float SwitchArray[4];
    for (int k = 0; k < 4; k++) {
        Here_Is_obstacle >> SwitchArray[k];
    }
    Switch* Switch1 = new Switch(SwitchArray[0], SwitchArray[1], SwitchArray[2], SwitchArray[3]);
    return Switch1;
}
