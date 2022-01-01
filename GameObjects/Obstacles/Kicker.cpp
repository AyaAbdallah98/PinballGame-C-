#include "Kicker.h"
#include <cmath>

using namespace std;


Kicker::Kicker(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) : collidedLastFrame(false) {
    this-> p1x = p1x;
    this-> p1y = p1y;
    this-> p2x = p2x;
    this-> p2y = p2y;
    this-> p3x = p3x;
    this-> p3y = p3y;
}

float Kicker::get_p1x() {
    return p1x;
}
float Kicker::get_p1y() {
    return p1y;
}
float Kicker::get_p2x() {
    return p2x;
}
float Kicker::get_p2y() {
    return p2y;
}
float Kicker::get_p3x() {
    return p3x;
}
float Kicker::get_p3y() {
    return p3y;
}
void Kicker::set_p1x(float x1) {
    p1x = x1;
}
void Kicker::set_p1y(float y1) {
    p1y = y1;
}
void Kicker::set_p2x(float x2) {
    p2x = x2;
}
void Kicker::set_p2y(float y2) {
    p2y = y2;
}
void Kicker::set_p3x(float x3) {
    p3x = x3;
}
void Kicker::set_p3y(float y3) {
    p3y = y3;
}

void Kicker::draw(Interface& interface)
{
   interface.drawKicker(p1x, p1y, p2x, p2y, p3x, p3y );
}

Vector2D Kicker::collideWith(Ball& ball, float collisionTime)  {
    if (!collidedLastFrame && abs(p1y - ball.getCenter().y) < ball.getRadius() && p1x < ball.getCenter().x && ball.getCenter().x  < p2x) //collided with the base
    {
        collidedLastFrame = true;
        return Vector2D{ 0 , ball.getVelocity().y * -2 } / collisionTime;
    }
    else if (!collidedLastFrame && abs(p3x - ball.getCenter().x) < ball.getRadius() && p1y > ball.getCenter().y && ball.getCenter().y > p3y) { //collided with the vertical side
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2  , 0} / collisionTime;
    }
    else if (!collidedLastFrame &&
        p1y > ball.getCenter().y &&
        ball.getCenter().y > p3y &&
        p1x < ball.getCenter().x &&
        ball.getCenter().x < p2x &&
        (ball.getCenter().y - ((ball.getCenter().x)*((abs(p3y-p1y))/(abs(p1x-p2x))))) < ball.getRadius()) {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2  , ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
}


Obstacle* Kicker::ReadKickers_fromFile(ifstream& Here_Is_obstacle) {
   
        float FillArray[6];
        for (int k = 0; k < 6; k++) {
            Here_Is_obstacle >> FillArray[k];
        }
        Kicker* kicker1 = new Kicker(FillArray[0], FillArray[1], FillArray[2], FillArray[3], FillArray[4], FillArray[5]);
        return kicker1;
}
    
   

    