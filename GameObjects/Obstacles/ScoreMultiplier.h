#pragma once
#include "Obstacle.h"

class ScoreMultiplier : public Obstacle
{
private:
	float radius;
	Vector2D center;
	bool collidedScoreMultiplier;
public:
	ScoreMultiplier(float radius, Vector2D center);
	void draw(Interface& interface);
	Vector2D getCenter();
	float getRadius();
	int increase_score(Ball& ball)  override;
	Vector2D collideWith(Ball& ball, float collisionTime) override;
	static Obstacle* readScoreMultiplier(ifstream& file);
};