#include "Flipper.h"
#include <cmath>

Flipper::Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius) {
    collidedFlipper = false;
}

Vector2D Flipper::collideWith(Ball& ball, float collisionTime)
{
    float positionX = (center.x + ((length- majorRadius-minorRadius) * cos(angle))) - ball.getCenter().x;
    float positionY = (center.y + ((length - majorRadius - minorRadius) * sin(angle))) - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = minorRadius + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;

    float position2X = (center.x - ((length - majorRadius - minorRadius) * cos(angle))) - ball.getCenter().x;
    float position2Y = (center.y - ((length - majorRadius - minorRadius) * sin(angle))) - ball.getCenter().y;
    float PositionSqrt2 = (position2X * position2X) + (position2Y * position2Y);
        
    if (!collidedFlipper && PositionSqrt <= totRadiusSqrt)
    {
        collidedFlipper = true;
        cout << "Flipper" << endl;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else if (!collidedFlipper && PositionSqrt2 <= totRadiusSqrt) {
        collidedFlipper = true;
        cout << "Aya" << endl;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else {
        collidedFlipper = false;
        return Vector2D{ 0, 0 };
    } // Should be replaced with the actual collision logic
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}

void Flipper::move(bool control)
{
    if (control)
    {
        if (type == LEFT)
        {
            if (angle >= -60.0)
                angle = angle - 3.0;
            else
                angle = angle;

        }
        else
        {
            if (angle <= 60.0)
                angle = angle + 3.0;
            else
                angle = angle;
        }

    }
    else
    {
        if (type == LEFT)
        {
            if (angle < 15.0)
                angle = angle + 3.0;
            else
                angle = angle;

        }
        else
        {
            if (angle > -15.0)
                angle = angle - 3.0;
            else
                angle = angle;
        }
    }
}
