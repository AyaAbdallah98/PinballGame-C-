#include "VibraniumBumper.h"


VibraniumBumper::VibraniumBumper(float radius, Vector2D center)
{
	setRadius(radius);
	setCenter(center);
}

void VibraniumBumper::draw(Interface& interface)
{
	interface.drawVibraniumBumper(radius, center);
}

Vector2D VibraniumBumper::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = getRadius() + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedVibraniumBumper && PositionSqrt <= totRadiusSqrt)

    {
        collidedVibraniumBumper = true;
       // cout << "3" << endl;
        return Vector2D{ (0-ball.getVelocity().x), (0-ball.getVelocity().y) } / collisionTime;
    }
    else
    {
        collidedVibraniumBumper = false;
        return { 0, 0 };
    }
}


Obstacle* VibraniumBumper::readVibraniumBumper(ifstream& file)
{
	float VibraniumArray[3];
	for (int k = 0; k < 3; k++) {
		file >> VibraniumArray[k];
	}
	VibraniumBumper* vibraniumBumper = new VibraniumBumper(VibraniumArray[0], { VibraniumArray[1], VibraniumArray[2] });
	return vibraniumBumper;

}