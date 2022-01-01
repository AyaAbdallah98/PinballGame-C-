#include "Lanes.h"
#include <cmath>
using namespace std;
Lanes::Lanes(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2) : collidedLastFrame(false) {
	this->point1x1 = point1x1;
	this->point1y1 = point1y1;
	this->point1x2 = point1x2;
	this->point1y2 = point1y2;
	this->point2x1 = point2x1;
	this->point2y1 = point2y1;
	this->point2x2 = point2x2;
	this->point2y2 = point2y2;
}
void Lanes::draw(Interface& interface)
{
	interface.drawLanes(point1x1, point1y1, point1x2, point1y2, point2x1, point2y1, point2x2, point2y2);
}

Vector2D Lanes::collideWith(Ball& ball, float collisionTime)
{
	if (!collidedLastFrame && ball.getCenter().x > point1x1
		&& ball.getCenter().x < point1x2 
		&& ball.getCenter().y < point1y1
		&& ball.getCenter().y > point2y2)
	{
		//cout << "y" << endl;
		ball.setCenter({ball.getCenter().x, (point1y1 + point2y2)/2});
		collidedLastFrame = true;
		return Vector2D{ 0 , -1 * ball.getVelocity().y } / collisionTime;
	}
	else 
	{
		collidedLastFrame = false;
		return Vector2D{ 0, 0 };
	}
}

Obstacle* Lanes::ReadLanes(ifstream& Here_Is_obstacle) {

	float LanesArray[8];
	for (int k = 0; k < 8; k++) {
		Here_Is_obstacle >> LanesArray[k];
	}
	Lanes* Lane1 = new Lanes(LanesArray[0], LanesArray[1], LanesArray[2], LanesArray[3], LanesArray[4], LanesArray[5], LanesArray[6], LanesArray[7]);
	return Lane1;
}