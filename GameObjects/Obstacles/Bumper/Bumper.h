#pragma once
#include "../Obstacle.h"
#include <fstream>

class Bumper : public Obstacle    //abstract class
{
protected:
	float radius;
	Vector2D center;

public:
	Bumper();
	void setRadius(float radius);
	void setCenter(Vector2D center);
	Vector2D getCenter();
	float getRadius();
	virtual void draw(Interface& interface) = 0;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
};