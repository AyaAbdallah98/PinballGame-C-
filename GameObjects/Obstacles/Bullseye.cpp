#include "Bullseye.h"
#include <cmath>

using namespace std;

Bullseye::Bullseye(float P1X, float P1Y, float P2X, float P2Y, float P3X, float P3Y) : collidedLastFrame(false) {
    this->P1X = P1X;
    this->P1Y = P1Y;
    this->P2X = P2X;
    this->P2Y = P2Y;
    this->P3X = P3X;
    this->P3Y = P3Y;
}

void Bullseye::draw(Interface& interface)
{
    interface.drawBullseye(P1X, P1Y, P2X, P2Y, P3X, P3Y);
}

Vector2D Bullseye::collideWith(Ball& ball, float collisionTime) {
    if (!collidedLastFrame && abs(P1Y - ball.getCenter().y) < ball.getRadius() && P1X < ball.getCenter().x && ball.getCenter().x < P2X) //collided with the base
    {
        collidedLastFrame = true;
        return Vector2D{ 0 , ball.getVelocity().y * -2 } / collisionTime;
    }
    else if (!collidedLastFrame 
        && abs(P3X - ball.getCenter().x) < ball.getRadius() 
        && P1Y < ball.getCenter().y 
        && ball.getCenter().y < P3Y) { //collided with the vertical side
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2  , 0 } / collisionTime;
    }
    else if (!collidedLastFrame && P1Y > ball.getCenter().y && ball.getCenter().y > P3Y && P1X < ball.getCenter().x && ball.getCenter().x < P2X && (ball.getCenter().y - ((ball.getCenter().x) * ((abs(P3Y - P1Y)) / (abs(P1X - P2X))))) < ball.getRadius()) {
        collidedLastFrame = true;
        return Vector2D{ ball.getVelocity().x * -2  , ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedLastFrame = false;
        return Vector2D{ 0, 0 };
    }
   
}

int Bullseye::increase_score(Ball& ball) {
    if (!collidedLastFrame && abs(P1Y - ball.getCenter().y) < ball.getRadius() && P1X < ball.getCenter().x && ball.getCenter().x < P2X) //collided with the base 
    { 
        return 200;
    }
    else if (!collidedLastFrame 
        && abs(P3X - ball.getCenter().x) < ball.getRadius() 
        && P1Y < ball.getCenter().y&& ball.getCenter().y < P3Y)  { //collided with the vertical side
        return 200;
    }
    else if (!collidedLastFrame && P1Y > ball.getCenter().y&& ball.getCenter().y > P3Y&& P1X < ball.getCenter().x && ball.getCenter().x < P2X && (ball.getCenter().y - ((ball.getCenter().x) * ((abs(P3Y - P1Y)) / (abs(P1X - P2X))))) < ball.getRadius()) {
        return 100;
    }
    else
    {
        return 0;
    }
}

Obstacle* Bullseye::ReadBullseye_fromFile(ifstream& Here_Is_obstacle) {

    float BullseyeArray[6];
    for (int k = 0; k < 6; k++) {
        Here_Is_obstacle >> BullseyeArray[k];
    }
    Bullseye* Bullseye1 = new Bullseye(BullseyeArray[0], BullseyeArray[1], BullseyeArray[2], BullseyeArray[3], BullseyeArray[4], BullseyeArray[5]);
    return Bullseye1;


}



