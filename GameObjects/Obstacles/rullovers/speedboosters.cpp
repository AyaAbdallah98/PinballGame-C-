#include "speedboosters.h"

Vector2D speedboosters::getCenter() const
{
    return center1;
}

speedboosters::speedboosters(Vector2D center1) : center1(center1)
{
}

Vector2D speedboosters::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = rradius + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;

    if (!collidespeed && PositionSqrt <= totRadiusSqrt)

    {
        collidespeed = true;
        cout << "1" << endl;
        return Vector2D{ ball.getVelocity().x * 2, ball.getVelocity().y * 2 } / collisionTime;
    }
    else
    {
        collidespeed = false;
        return { 0, 0 };
    }
}

void speedboosters::draw(Interface& interface)
{
    interface.drawspeedboosters(center1, rradius);
}

Obstacle* speedboosters::ReadSpeedBoosters(ifstream& Here_Is_obstacle) {

    float SpeedBArray[2];
    for (int k = 0; k < 2; k++) {
        Here_Is_obstacle >> SpeedBArray[k];
    }
    speedboosters* SpeedBooster1 = new speedboosters({ SpeedBArray[0], SpeedBArray[1] });
    return SpeedBooster1;
}
