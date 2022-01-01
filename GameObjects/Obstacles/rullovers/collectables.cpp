#include "collectables.h"

Vector2D collectables::getCenter() const
{
	return center2;
}

collectables::collectables(Vector2D center2, string A)
{
	this->center2 = center2;
	this->A = A;
}

void collectables::setcolor(bool color)
{
    check = color;
}

Vector2D collectables::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = rrradius + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedcollec && PositionSqrt <= totRadiusSqrt)

    {
        collidedcollec = true;
        setcolor(false);
        //cout << "1" << endl;
    }
    else
    {
        setcolor(true);
        collidedcollec = false;
        return { 0, 0 };
    }
}

int collectables::increase_score(Ball& ball) {
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = rrradius + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedcollec && PositionSqrt <= totRadiusSqrt)
    {
        return 100;
    }
    else
    {
        return 0;
    }
}
void collectables::draw(Interface& interface)
{
	interface.drawcollectables(center2, rrradius, A, check);
}

Obstacle* collectables::ReadCollectables(ifstream& Here_Is_obstacle) {

    float CArray[2];
	string Cstring;
    for (int k = 0; k < 2; k++) {
        Here_Is_obstacle >> CArray[k];
    }
	Here_Is_obstacle >> Cstring;
	collectables* collectable1 = new collectables({ CArray[0], CArray[1] }, Cstring);
    return collectable1;
}

