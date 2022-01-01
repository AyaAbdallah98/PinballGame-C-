#include "Score.h"

score::score(Vector2D scenter, float scradius) {
    this->scenter = scenter;
    this->ss = 0;
    this->scradius = scradius;
    sss = "Current Score:";
}

int score::Update_score(int input_score) {
    ss += input_score;
    return ss;
}

void score::draw(Interface& interface)
{
    interface.drawscore(scenter,sss ,ss, scradius );
}

void score::Game_Over(Ball& ball, string sss, Interface& interface) {
    if (ball.getCenter().y > 750) {
        interface.drawscore({350, 375},"Game Over, The final score is:", ss, 200);
    }
}

