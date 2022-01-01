#pragma once
#include "Obstacle.h"

//It represents a Bullseye, which is like a right angled triangle.

class Bullseye :  public Obstacle 
{
private:
    float P1X, P1Y, P2X, P2Y, P3X, P3Y;  // The position of the three points that form the triangle 
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)

public:
    explicit Bullseye(float P1X, float P1Y, float P2X, float P2Y, float P3X, float P3Y);
    void draw(Interface& interface) override;
    int increase_score(Ball& ball)  override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadBullseye_fromFile(ifstream& HereIsobstacle);
};

