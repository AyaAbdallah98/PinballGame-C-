#pragma once
#include "Obstacle.h"
class magnet : public Obstacle
{
private:
    float mradius = MAGNET_RADIUS;
    Vector2D mcenter;
    bool collidemagnet;

public:
    Vector2D getCenter() const;
    explicit magnet(Vector2D mcenter);  // Constructor
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadMagnets(ifstream& HereIsobstacle);
};