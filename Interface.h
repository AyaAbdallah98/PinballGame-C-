#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Defs.h"
using namespace std;
#include <iostream>
// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
    sf::RenderWindow window;  // Represents the game window
    const sf::Color  // Colors used for drawing (can change the whole theme of the game)
        backgroundColor = sf::Color::Black,
        outlineColor = sf::Color::White,
        ballFillColor = sf::Color::Yellow,
        flipperFillColor = sf::Color::Red,
        popBumperFillColor = sf::Color::Red,
        thrustBumperFillColor = sf::Color::Magenta,
        vibraniumBumperFillColor = sf::Color::Blue,
        scoreMultiplierFillColor = sf::Color::Yellow;
    const float outlineThickness = -2.0f;  // Negative sign means inwards

public:
    Interface();  // Constructor
    void getControls(bool & exit, bool & left, bool & right);  // Detects the buttons pressed

    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, float radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius);  // Draws a flipper
    void drawWall(float position);  // Draws a vertical wall
    void drawCeiling(float position); //Draws a horizontal wall (Hopefully a Ceiling)
    void drawKicker(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y); //draws a kicker (right angled triangle)
    void drawGate(float point1x, float point1y, float point2x, float point2y); //draws a line segment (Gate)
    void drawPopBumper(float radius, Vector2D center);  //draw popBumpers
    void drawThrustBumper(float radius, Vector2D center);  //draw thrustBumpers
    void drawVibraniumBumper(float radius, Vector2D center);  //draw vibraniumBumpers
    void drawScoreMultiplier(float radius, Vector2D center);
    void drawSwitch(float pointx1, float pointy1, float pointx2, float pointy2);
    void drawBullseye(float P1X, float P1Y, float P2X, float P2Y, float P3X, float P3Y);
    void drawspeedboosters(Vector2D center1, float radius);
    void drawcollectables(Vector2D center2, float rrradius, string A, bool check);    void drawmagnet(Vector2D mcenter, float mradius);
    void drawcaptives(Vector2D cacenter, float cradius);
    void drawscore(Vector2D scenter,string sss, int ss,float scradius);
    void drawportals(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2);
    void drawLanes(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2);
    void drawRamp(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
};
