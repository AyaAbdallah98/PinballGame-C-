#pragma once
#include "rullovers.h"
class speedboosters : public rullovers
{
private:
    float rradius = SPEEDBOOSTERS_RADIUS;  
    Vector2D center1;  
    bool collidespeed;
   
public:
    Vector2D getCenter() const;
    explicit speedboosters(Vector2D center1 );  // Constructor
	void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collisionTime) override;
    static Obstacle* ReadSpeedBoosters(ifstream& HereIsobstacle);
};

