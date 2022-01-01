#pragma once
#include "rullovers.h"
#include <iostream>
using namespace std;
class collectables : public rullovers
{
private:
	float rrradius = COLLECTABLES_RADIUS;
	Vector2D center2;
	string A;
	bool color;
	bool collidedcollec;
	bool check = true;
public:
	Vector2D getCenter() const;
	explicit collectables(Vector2D center2, string A );  // Constructor
	void draw(Interface& interface) override;
	void setcolor(bool color);
	int increase_score(Ball& ball)  override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	static Obstacle* ReadCollectables(ifstream& HereIsobstacle);
};

