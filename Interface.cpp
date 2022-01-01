#include "Interface.h"
#include<iostream>
#include <sstream>

using namespace std;
Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(true);
}

void Interface::getControls(bool & exit, bool & left, bool & right)
{
    sf::Event event;
    while (window.pollEvent(event));
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                    sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
            };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawCeiling(float position) {
    sf::Vertex line[] =
    {
            sf::Vertex(sf::Vector2f(0, position), outlineColor),
            sf::Vertex(sf::Vector2f(GAME_WIDTH,position), outlineColor)
    };
    window.draw(line, 2, sf::Lines);
}

void Interface::drawKicker(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y ) {
    sf::VertexArray kicker(sf::Triangles, 3);
    kicker[0].position = sf::Vector2f(p1x, p1y);
    kicker[0].color = sf::Color::Red;
    kicker[1].position = sf::Vector2f(p2x, p2y);
    kicker[1].color = sf::Color::Red;
    kicker[2].position = sf::Vector2f(p3x, p3y);
    kicker[2].color = sf::Color::Red; 
    window.draw(kicker);
}

void Interface::drawGate(float point1x, float point1y, float point2x, float point2y) {
    sf::VertexArray gate(sf::Lines, 2);
    gate[0].position = sf::Vector2f(point1x, point1y);
    gate[1].position = sf::Vector2f(point2x, point2y);
    gate[0].color = sf::Color::Red;
    gate[1].color = sf::Color::Yellow;
    window.draw(gate);
}

void Interface::drawPopBumper(float radius, Vector2D center)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setFillColor(popBumperFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}
void Interface::drawThrustBumper(float radius, Vector2D center)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setFillColor(thrustBumperFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawVibraniumBumper(float radius, Vector2D center)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setFillColor(vibraniumBumperFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);
}

void Interface::drawScoreMultiplier(float radius, Vector2D center)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    //circle.setOutlineThickness(outlineThickness);
    //circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);

    window.draw(circle);
}

void Interface::drawSwitch(float pointx1, float pointy1, float pointx2, float pointy2) {
    sf::VertexArray Switch(sf::Lines, 2);
    Switch[0].position = sf::Vector2f(pointx1, pointy1);
    Switch[1].position = sf::Vector2f(pointx2, pointy2);
    Switch[0].color = sf::Color::Green;
    Switch[1].color = sf::Color::Green;
    window.draw(Switch);
}

void Interface::drawBullseye(float P1X, float P1Y, float P2X, float P2Y, float P3X, float P3Y) {
    sf::VertexArray BULLSEYE(sf::Triangles, 3);
    BULLSEYE[0].position = sf::Vector2f(P1X, P1Y);
    BULLSEYE[0].color = sf::Color::Green;
    BULLSEYE[1].position = sf::Vector2f(P2X, P2Y);
    BULLSEYE[1].color = sf::Color::Yellow;
    BULLSEYE[2].position = sf::Vector2f(P3X, P3Y);
    BULLSEYE[2].color = sf::Color::Green;
    window.draw(BULLSEYE);
}

void Interface::drawspeedboosters(Vector2D center1, float rradius)
{
    sf::CircleShape circle(rradius);
    circle.setOrigin(rradius, rradius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(center1.x, center1.y);
    window.draw(circle);

}
void Interface::drawcollectables(Vector2D center2, float rrradius, string A, bool check)
{
    sf::CircleShape circle(rrradius);
    circle.setOrigin(rrradius, rrradius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    if (check == true) 
    {
        circle.setFillColor(sf::Color::Yellow);
    }
    else
    {
        circle.setFillColor(sf::Color::Green);
    }
    circle.setPosition(center2.x, center2.y);
    window.draw(circle);
    sf::Font font;
    if (!font.loadFromFile("BebasNeueRegular.ttf"))
    {
        cout << "error loading from file" << endl;

    }
    sf::Text text;
    text.setFont(font);
    text.setString(A);
    text.setFillColor(sf::Color::Red);
    sf::FloatRect x = text.getGlobalBounds();
    text.setOrigin(x.left + x.width / 2.0f, x.top + x.height / 2.0f);
    text.setPosition(center2.x, center2.y);

    window.draw(text);
}
void Interface::drawscore(Vector2D scenter,string sss, int ss,float scradius)
{
    sf::CircleShape circle(scradius);
    circle.setOrigin(scradius, scradius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(scenter.x, scenter.y);
    window.draw(circle);
    sf::Font font;
    if (!font.loadFromFile("BebasNeueRegular.ttf"))
    {
        cout << "error loading from file" << endl;

    }
    sf::Text text1;
    text1.setFont(font);
    text1.setString(sss);
    text1.setFillColor(sf::Color::Red);
    sf::FloatRect x = text1.getGlobalBounds();
    text1.setOrigin(x.left + x.width / 2.0f, x.top + x.height / 2.0f);
    text1.setPosition(scenter.x, scenter.y);
    window.draw(text1);
    sf::Text text;
    std::stringstream string_score;
    string_score << ss;
    text.setFont(font);
    text.setString(string_score.str().c_str());
    text.setFillColor(sf::Color::Red);
    sf::FloatRect x1 = text.getGlobalBounds();
    text.setOrigin(x1.left + x1.width / 2.0f, x1.top + x1.height / 2.0f);
    text.setPosition(scenter.x, scenter.y +30);
    window.draw(text); 

}
void Interface::drawmagnet(Vector2D mcenter, float mradius)
{
    sf::CircleShape circle(mradius);
    circle.setOrigin(mradius, mradius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(mcenter.x, mcenter.y);
    window.draw(circle);
}
void Interface::drawcaptives(Vector2D cacenter, float cradius)
{
    sf::CircleShape circle(cradius);
    circle.setOrigin(cradius, cradius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(cacenter.x, cacenter.y);
    window.draw(circle);
}

void Interface::drawportals(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2) {
    sf::VertexArray portals(sf::Lines, 4);
    portals[0].position = sf::Vector2f(point1x1, point1y1);
    portals[1].position = sf::Vector2f(point1x2, point1y2);
    portals[2].position = sf::Vector2f(point2x1, point2y1);
    portals[3].position = sf::Vector2f(point2x2, point2y2);
    window.draw(portals);

}

void Interface::drawLanes(float point1x1, float point1x2, float point1y1, float point1y2, float point2x1, float point2x2, float point2y1, float point2y2) {
    sf::VertexArray lanes(sf::Lines, 4);
    lanes[0].position = sf::Vector2f(point1x1, point1y1);
    lanes[1].position = sf::Vector2f(point1x2, point1y2);
    lanes[2].position = sf::Vector2f(point2x1, point2y1);
    lanes[3].position = sf::Vector2f(point2x2, point2y2);
    lanes[0].color = sf::Color::Cyan;
    lanes[1].color = sf::Color::Cyan;
    lanes[2].color = sf::Color::Cyan;
    lanes[3].color = sf::Color::Cyan;
    window.draw(lanes);

}

void Interface::drawRamp(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    sf::ConvexShape ramp(4);
    ramp.setPoint(0, sf::Vector2f(x1, y1));
    ramp.setPoint(1, sf::Vector2f(x2, y2));
    ramp.setPoint(2, sf::Vector2f(x3, y3));
    ramp.setPoint(3, sf::Vector2f(x4, y4));
    ramp.setFillColor(sf::Color::White);
    window.draw(ramp);

}

