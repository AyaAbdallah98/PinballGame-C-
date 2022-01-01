#include "Ramp.h"

Ramp::Ramp(float x1, float y1, float x2, float y2,float x3, float y3, float x4, float y4)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y2;
	this->x4 = x4;
	this->y4 = y4;
}

void Ramp::draw(Interface& interface)
{
	interface.drawRamp(x1, y1, x2, y2, x3,y3,x4,y4);
}

Vector2D Ramp::collideWith(Ball& ball, float collisionTime)
{
	float positionX = x1 - ball.getCenter().x;
	float positionY = y1 - ball.getCenter().y;
	float PositionSqrt = (positionX * positionX) + (positionY * positionY);
	//float totRadius = getRadius() + ball.getRadius();
	//float totRadiusSqrt = totRadius * totRadius;
	if (PositionSqrt <= ball.getRadius())
	{
		cout << "hello" << endl;
	}
	return Vector2D{ 0,0 };
}

Obstacle* Ramp::ReadRamp(ifstream& file)
{
	float rampArray[8];
	for (int k = 0; k < 5; k++) {
		file >> rampArray[k];
	}
	Ramp* ramp = new Ramp (rampArray[0], rampArray[1], rampArray[2],
		rampArray[3], rampArray[4], rampArray[5], rampArray[6], rampArray[7]);
	return ramp;

}