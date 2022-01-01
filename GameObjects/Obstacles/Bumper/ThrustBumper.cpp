#include "ThrustBumper.h"

ThrustBumper::ThrustBumper(float radius, Vector2D center)
{
	setRadius(radius);
	setCenter(center);
}

void ThrustBumper::draw(Interface& interface)
{
	interface.drawThrustBumper(radius, center);
}

Vector2D ThrustBumper::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = getRadius() + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedThrustBumper && PositionSqrt <= totRadiusSqrt)

    {
        collidedThrustBumper = true;
       // cout << "2" << endl;
        return Vector2D{ ball.getVelocity().x * -4, ball.getVelocity().y * -4 } / collisionTime;
    }
    else
    {
        collidedThrustBumper = false;
        return { 0, 0 };
    }
}


Obstacle* ThrustBumper::readThrustBumper(ifstream& file)
{
	float ThrustArray[3];
	for (int k = 0; k < 3; k++) {
		file >> ThrustArray[k];
	}
	ThrustBumper* thrustBumper = new ThrustBumper(ThrustArray[0], { ThrustArray[1], ThrustArray[2] }); 
	return thrustBumper;

}