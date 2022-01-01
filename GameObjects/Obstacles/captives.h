#pragma once
#include "Obstacle.h"
class captives : public Obstacle , public Ball
{
private:
    float cradius = CAPTIVE_RADIUS;
    Vector2D cacenter;
    Vector2D velocity;
public:
    Vector2D getCenter() const;
    explicit captives(Vector2D mcenter);  // Constructor
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadCaptives(ifstream& HereIsobstacle);
};