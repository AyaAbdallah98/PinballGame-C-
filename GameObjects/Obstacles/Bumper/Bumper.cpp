#include "Bumper.h"

Bumper::Bumper()
{
	radius = 5;
	center = { 50.0f, 50.0f };
}

void Bumper::setRadius(float radius)
{
	this->radius = radius;
}

void Bumper::setCenter(Vector2D center)
{
	this->center = center;
}

float Bumper::getRadius()
{
	return radius;
}

Vector2D Bumper::getCenter()
{
	return center;
}
/*void Bumper::draw(Interface & interface)
{
	interface.drawBumper(x, y, radius);
} */

Vector2D Bumper::collideWith(Ball& ball, float collisionTime)
{
	return Vector2D{ 0, 0 };
}
