#include "ScoreMultiplier.h"


ScoreMultiplier::ScoreMultiplier(float radius, Vector2D center)
{
	this->radius = radius;
	this->center = center;
}
void ScoreMultiplier::draw(Interface& interface)
{
	interface.drawScoreMultiplier(radius, center);
}

Vector2D ScoreMultiplier::collideWith(Ball& ball, float collisionTime)
{
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = getRadius() + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedScoreMultiplier && PositionSqrt <= totRadiusSqrt)

    {
        collidedScoreMultiplier = true;
        cout << "1" << endl;
        return Vector2D{ ball.getVelocity().x * -2, ball.getVelocity().y * -2 } / collisionTime;
    }
    else
    {
        collidedScoreMultiplier = false;
        return { 0, 0 };
    }
}

Vector2D ScoreMultiplier::getCenter()
{
	return center;
}

float ScoreMultiplier::getRadius()
{
    return radius;
}

int ScoreMultiplier::increase_score(Ball& ball)
{
    int score = 0;
    float positionX = getCenter().x - ball.getCenter().x;
    float positionY = getCenter().y - ball.getCenter().y;
    float PositionSqrt = (positionX * positionX) + (positionY * positionY);
    float totRadius = getRadius() + ball.getRadius();
    float totRadiusSqrt = totRadius * totRadius;
    if (!collidedScoreMultiplier && PositionSqrt <= totRadiusSqrt)
    {
        collidedScoreMultiplier = true;
        return 2;
    }
    else
    {
        collidedScoreMultiplier = false;
        return 1;
    }
}
Obstacle* ScoreMultiplier::readScoreMultiplier(ifstream& file)
{
	float ScoreArray[3];
	for (int k = 0; k < 3; k++) {
		file >> ScoreArray[k];
	}
	ScoreMultiplier* scoreMultiplier = new ScoreMultiplier(ScoreArray[0], { ScoreArray[1], ScoreArray[2] } );
	return scoreMultiplier;

}
