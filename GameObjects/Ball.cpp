#include "Ball.h"


Ball::Ball(Vector2D center, Vector2D velocity): center(center), velocity(velocity) {
    //center = { BallParameters[0],BallParameters[1] };
    //velocity = { BallParameters[2],BallParameters[3] };
   // 150 20
   //-500 0
}

float Ball::getRadius() const
{
    return radius;
}

Vector2D Ball::getCenter() const 
{
    return center;
}

Vector2D Ball::getVelocity() const
{
    return velocity;
}

void Ball::setCenter(Vector2D Center) {
    center = Center;
}

void Ball::move(Vector2D acceleration, float time)
{
    // Kinematic equations for planar motion of a particle
    velocity += acceleration * time;
    center += velocity * time - acceleration * time * time * 0.5;
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius);
}

Ball* Ball::readBall(ifstream& file)
{
    float BallArray[4];
    for (int k = 0; k < 4; k++) {
        file >> BallArray[k];
    }
    Ball* ball = new Ball({ BallArray[0], BallArray[1] }, { BallArray[2], BallArray[3] });
    return ball;

}
