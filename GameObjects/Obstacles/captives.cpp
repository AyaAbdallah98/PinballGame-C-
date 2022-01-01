#include "captives.h"
Vector2D captives::getCenter() const
{
    return cacenter;
}

captives::captives(Vector2D cacenter) :Ball(cacenter, velocity) 
{
    velocity = {0,0};
    this->cacenter = cacenter;
}

Vector2D captives::collideWith(Ball& ball, float collisionTime)
{

    return Vector2D();
}

void captives::draw(Interface& interface)
{
    interface.drawcaptives(cacenter, cradius);
}

Obstacle* captives::ReadCaptives(ifstream& Here_Is_obstacle) {

    float CaptivesArray[2];
    for (int k = 0; k < 2; k++) {
        Here_Is_obstacle >> CaptivesArray[k];
    }
    captives* captive1 = new captives({ CaptivesArray[0], CaptivesArray[1] });
    return captive1;
}
