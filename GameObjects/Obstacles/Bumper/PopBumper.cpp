#include "PopBumper.h"

PopBumper::PopBumper(float radius, Vector2D center)
{
    setRadius(radius);
    setCenter(center);
}

void PopBumper::draw(Interface& interface)
{
    interface.drawPopBumper(radius, center);
}

Vector2D PopBumper::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = getRadius() + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedPopBumper && PositionSqrt <= totRadiusSqrt)

    {
        collidedPopBumper = true;
        //cout << "1" << endl;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedPopBumper = false;
        return { 0, 0 };
    }
}


Obstacle* PopBumper::readPopBumper(ifstream& file) {

    float PopArray[3];
    for (int k = 0; k < 3; k++) {
        file >> PopArray[k];
    }
    PopBumper* popBumper = new PopBumper(PopArray[0], { PopArray[1], PopArray[2] }); 
    return popBumper;

}