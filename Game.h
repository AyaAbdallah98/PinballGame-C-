#pragma once

#include <chrono>
using namespace std::chrono;

#include <string>
using namespace std;

#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Obstacles/Ceiling.h" 
#include "GameObjects/Flipper.h"
#include "GameObjects/Obstacles/Kicker.h"
#include "GameObjects/Obstacles/Gate.h"
#include "GameObjects/Obstacles/Bumper/Bumper.h"
#include "GameObjects/Obstacles/Bumper/PopBumper.h"
#include "GameObjects/Obstacles/Bumper/ThrustBumper.h"
#include "GameObjects/Obstacles/Bumper/VibraniumBumper.h"
#include "GameObjects/Obstacles/ScoreMultiplier.h"
#include "GameObjects/Obstacles/Switch.h"
#include "GameObjects/Obstacles/Bullseye.h"
#include "GameObjects/Obstacles/rullovers/speedboosters.h"
#include "GameObjects/Obstacles/rullovers/collectables.h"
#include "GameObjects/Obstacles/magnet.h"
#include "GameObjects/Obstacles/captives.h"
#include "Score.h"
#include "GameObjects/Obstacles/portals.h"
#include "GameObjects/Obstacles/Lanes.h"
#include "GameObjects/Obstacles/Ramp.h"





// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point lastFrame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls

    Ball* ball;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    int NumOfObstacles;
    Obstacle** obstacles;
    Obstacle** targets;
    int count = 0;
    int Num_Of_Current_Obstacles = 0;
    int NumOfKickers, NumOfWalls, NumOfGates, NumOfCeilings, NumOfPop, NumOfThrust, NumOfVibranium, NumOfMultipliers, NumOfSwitch, NumOfBULL, NumOfCollectables, NumOfSpeedB, NumOfMagnets, NumOfCaptives, NumOfPortals, NumOfLanes, NumOfRamps;
    string ObstacleType;
    score score1;
public:
    Game();
    ~Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    bool exited();
};
