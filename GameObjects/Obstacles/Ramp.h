#pragma once
#include "Obstacle.h"

class Ramp :public Obstacle
{
private:
	float x1, y1, x2, y2,x3,y3,x4,y4;
	float length;
	float angle;
	bool collidedRamp;
public:
    Ramp(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void draw(Interface& interface) override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	static Obstacle* ReadRamp(ifstream& file);
};
