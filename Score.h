#pragma once
#include "GameObjects/Obstacles/Obstacle.h"


class score : Drawable {
private:
	int ss;
	Vector2D scenter;
	float scradius;
	float x, y;
	string sss;

public:
	explicit score(Vector2D scenter, float scradius);
	void draw(Interface& interface) override;
	int Update_score(int input_score);
	void Game_Over(Ball& ball, string sss, Interface& interface);
};