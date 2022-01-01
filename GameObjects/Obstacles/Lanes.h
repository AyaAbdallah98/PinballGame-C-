#pragma once
#include "Obstacle.h"
//represents the Lane, which represents two parallel lines, separated by the ball diameter. 
class Lanes :public Obstacle
{
private:
    float point1x1, point1x2, point1y1, point1y2, point2x1, point2x2, point2y1, point2y2;//four points; each two form a line
    bool collidedLastFrame;

public:
    explicit Lanes(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadLanes(ifstream& HereIsobstacle);
};