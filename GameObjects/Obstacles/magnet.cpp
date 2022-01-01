#include "magnet.h"
Vector2D magnet::getCenter() const
{
    return mcenter;
}

magnet::magnet(Vector2D mcenter) : mcenter(mcenter)
{
}

Vector2D magnet::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);

    if (!collidemagnet && PositionSqrt <= 100)

    {
        collidemagnet = true;
        cout << "1" << endl;
        return Vector2D{ ball.getVelocity().x * 2, ball.getVelocity().y * 2 } / collisionTime;
    }
    else
    {
        collidemagnet = false;
        return { 0, 0 };
    }
}


void magnet::draw(Interface& interface)
{
    interface.drawmagnet(mcenter, mradius);
}

Obstacle* magnet::ReadMagnets(ifstream& Here_Is_obstacle) {

    float MagnetsArray[2];
    for (int k = 0; k < 2; k++) {
        Here_Is_obstacle >> MagnetsArray[k];
    }
    magnet* magnet1 = new magnet({ MagnetsArray[0], MagnetsArray[1] });
    return magnet1;
}
