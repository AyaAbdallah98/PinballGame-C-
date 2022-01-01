#pragma once

#include "../Drawable.h"
#include "../Collidable.h"
#include <fstream>
#include <iostream>
using namespace std;


// An abstract class representing an obstacle
class Obstacle: public Drawable, public Collidable
{
public:
	virtual int increase_score(Ball & ball) {
		return 0;
	}
};
