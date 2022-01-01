#include "portals.h"
#include <cmath>
using namespace std;
portals::portals(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2) : collidedLastFrame(false) {
	this->point1x1 = point1x1;
	this->point1y1 = point1y1;
	this->point1x2 = point1x2;
	this->point1y2 = point1y2;
	this->point2x1 = point2x1;
	this->point2y1 = point2y1;
	this->point2x2 = point2x2;
	this->point2y2 = point2y2;
}
void portals::draw(Interface& interface)
{
	interface.drawportals(point1x1, point1x2, point1y1, point1y2, point2x1, point2x2, point2y1, point2y2);
}

Vector2D portals::collideWith(Ball& ball, float collisionTime)
{
	if (!collidedLastFrame
		&& ball.getCenter().x == point1x1
		&& ball.getCenter().y > point1y1
		&& ball.getCenter().y < point1y2) 
	{
		cout << "hi";
		ball.setCenter({ point2x1, (point2y1 + point2y2) / 2 });
		collidedLastFrame = true;
		return Vector2D{ 0, 0 };
	}
	else if (!collidedLastFrame
		&& ball.getCenter().x == point2x1
		&& ball.getCenter().y > point2y1
		&& ball.getCenter().y < point2y2)
	{
		cout << "Touka";
		ball.setCenter({ point1x1, (point1y1 + point1y2) / 2 });
		collidedLastFrame = true;
		return Vector2D{ 0, 0 };
	}
	else 
	{
		collidedLastFrame = false;
		return Vector2D{ 0, 0 };
	}

}

Obstacle* portals::ReadPortals(ifstream& Here_Is_obstacle) {

	float portalsArray[8];
	for (int k = 0; k < 8; k++) {
		Here_Is_obstacle >> portalsArray[k];
	}
	portals* portal1 = new portals(portalsArray[0], portalsArray[1], portalsArray[2], portalsArray[3], portalsArray[4], portalsArray[5], portalsArray[6], portalsArray[7]);
	return portal1;
}