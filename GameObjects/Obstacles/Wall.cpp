#include "Wall.h"

#include <cmath>
using namespace std;

Wall::Wall(float position): position(position), collidedLastFrame(false) {}

void Wall::draw(Interface & interface)
{
    interface.drawWall(position);
}

Vector2D Wall::collideWith(Ball & ball, float collisionTime)
{
    if(!collidedLastFrame && abs(position - ball.getCenter().x) < ball.getRadius())
    {
        collidedLastFrame = true;
        return Vector2D {ball.getVelocity().x * -2, 0 } / collisionTime; //since the rule of impulse is F*t=m*(v2-v1), a*t=v2-v1
        //v2=-v1, v2-v1=-2v1, ax=-2*v1x/t
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D {0, 0};
    }
}

void Wall::set_wallPosition(float Position) {
    position = Position;
}

Obstacle* Wall::ReadWalls_fromFile(ifstream& Here_Is_obstacle) {

    float wallArr;
        Here_Is_obstacle >> wallArr;
    Wall* Wall1 = new Wall(wallArr);
    return Wall1;
}
