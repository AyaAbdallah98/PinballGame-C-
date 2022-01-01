
#include "Game.h"
#include <fstream>
#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 15.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
    rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, -15.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
    score1({600, 100},  80.0f)
{
    targets = new Obstacle * [8];
    lastFrame = high_resolution_clock::now();
    exit = left = right = false;
    ifstream dataArray("Data.txt");
    while (!dataArray.eof()) {
        ball= Ball::readBall(dataArray);
        
        dataArray >> NumOfObstacles;
        obstacles = new Obstacle * [NumOfObstacles];
       
        dataArray >> ObstacleType;
        while (ObstacleType == "Kickers") {
            dataArray >> NumOfKickers;
            for (count; count < NumOfKickers; count++) {
                obstacles[count] = Kicker::ReadKickers_fromFile(dataArray);
                Num_Of_Current_Obstacles++;
            }
            break;
        }
        dataArray >> ObstacleType;
        
          while (ObstacleType == "Wall") {
            dataArray >> NumOfWalls;
            for (count; count < NumOfKickers+ NumOfWalls; count++) {
                obstacles[count] = Wall::ReadWalls_fromFile(dataArray);
                Num_Of_Current_Obstacles++;
            }
            break;
        }
          dataArray >> ObstacleType;
          while  (ObstacleType == "Gates") {
              dataArray >> NumOfGates;
              for (count; count < NumOfKickers + NumOfWalls + NumOfGates; count++) {
                  obstacles[count] = Gate::ReadGates_fromFile(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }
          dataArray >> ObstacleType;
          while (ObstacleType == "Ceiling") {
              dataArray >> NumOfCeilings;
              for (count; count < NumOfKickers + NumOfWalls + NumOfGates+ NumOfCeilings; count++) {
                  obstacles[count] = Ceiling::ReadCeiling_fromFile(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "PopBumpers") {
              dataArray >> NumOfPop;
              for (count; count < NumOfKickers + NumOfWalls + NumOfGates + NumOfCeilings+NumOfPop; count++) {
                  obstacles[count] = PopBumper::readPopBumper(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "ThrustBumpers") {
              dataArray >> NumOfThrust;
              for (count; count < NumOfKickers +NumOfThrust+ NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = ThrustBumper::readThrustBumper(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Vibranium") {
              dataArray >> NumOfVibranium;
              for (count; count < NumOfKickers +NumOfVibranium+ NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = VibraniumBumper::readVibraniumBumper(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "ScoreMultipliers") {
              dataArray >> NumOfMultipliers;
              for (count; count < NumOfKickers+ NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = ScoreMultiplier::readScoreMultiplier(dataArray);
                  targets[0] = obstacles[count];
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Switches") {
              dataArray >> NumOfSwitch;
              for (count; count < NumOfKickers +NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = Switch::readSwitch(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Bullseye") {
              dataArray >> NumOfBULL;
              for (count; count < NumOfKickers+NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = Bullseye::ReadBullseye_fromFile(dataArray);
                  targets[1] = obstacles[count];
                  Num_Of_Current_Obstacles++;
              }
              
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Collectables") {
              dataArray >> NumOfCollectables;
              for (count; count < NumOfKickers+ NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = collectables::ReadCollectables(dataArray);
                  targets[count-14] = obstacles[count]; 
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "speedBoosters") {
              dataArray >> NumOfSpeedB;
              for (count; count < NumOfKickers+NumOfSpeedB + NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = speedboosters::ReadSpeedBoosters(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Magnets") {
              dataArray >> NumOfMagnets;
              for (count; count < NumOfKickers+NumOfMagnets + NumOfSpeedB + NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = magnet::ReadMagnets(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Captives") {
              dataArray >> NumOfCaptives;
              for (count; count < NumOfKickers+NumOfCaptives + NumOfMagnets + NumOfSpeedB + NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = captives::ReadCaptives(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Portals") {
              dataArray >> NumOfPortals;
              for (count; count < NumOfKickers+NumOfPortals + NumOfCaptives + NumOfMagnets + NumOfSpeedB + NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = portals::ReadPortals(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Lanes") {
              dataArray >> NumOfLanes;
              for (count; count < NumOfKickers +NumOfLanes + NumOfPortals + NumOfCaptives + NumOfMagnets + NumOfSpeedB + NumOfCollectables + NumOfBULL + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = Lanes::ReadLanes(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }

          dataArray >> ObstacleType;
          while (ObstacleType == "Ramps") {
              dataArray >> NumOfRamps;
              for (count; count < NumOfRamps + NumOfKickers + NumOfPortals + NumOfCaptives
                  + NumOfMagnets + NumOfSpeedB + NumOfCollectables + NumOfBULL
                  + NumOfSwitch + NumOfMultipliers + NumOfVibranium + NumOfThrust
                  + NumOfWalls + NumOfGates + NumOfCeilings + NumOfPop; count++) {
                  obstacles[count] = Ramp::ReadRamp(dataArray);
                  Num_Of_Current_Obstacles++;
              }
              break;
          }
          break;
        }
        }
    
        
    



void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right);
}

void Game::simulate()
{
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point thisFrame = high_resolution_clock::now();
    duration<float> timeSpan = duration_cast<duration<float>>(thisFrame - lastFrame);
    lastFrame = thisFrame;
    float deltaTime = timeSpan.count();  // Delta time in seconds

    Vector2D resultantAcceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer
    for (int m = 0; m < Num_Of_Current_Obstacles; m++) {
        Vector2D NewAcceleration=obstacles[m]->collideWith(*ball, deltaTime); 
        resultantAcceleration += NewAcceleration;
    }
    Vector2D L_FlipperAcc = leftFlipper.collideWith(*ball, deltaTime);
    Vector2D R_FlipperAcc = rightFlipper.collideWith(*ball, deltaTime);

    resultantAcceleration += L_FlipperAcc;
    resultantAcceleration += R_FlipperAcc;

    ball->move(resultantAcceleration, deltaTime);

    int Add_Score = 0;
    for (int n = 1; n < 8; n++) {
        int New_Score = targets[n]->increase_score(*ball);
        Add_Score += New_Score;
    }
    int Multiply_Score= targets[0]->increase_score(*ball);
    Add_Score = Add_Score * Multiply_Score;

    score1.Update_score(Add_Score);

    leftFlipper.move(left);
    rightFlipper.move(right);
}

void Game::updateInterfaceOutput()
{
    interface.clear();
    ball->draw(interface);

    leftFlipper.draw(interface);
    rightFlipper.draw(interface);

    for (int m = 0; m < Num_Of_Current_Obstacles; m++) {
            obstacles[m]->draw(interface);
        }
   
    score1.draw(interface);
    score1.Game_Over(*ball, "Game Over, The final score is", interface);


    interface.display();
}
bool Game::exited()
{
    return exit;
} 
Game::~Game() {
    for (int m = 0; m < Num_Of_Current_Obstacles; m++) {
        delete[] obstacles[m];
        delete[] obstacles;
    }
    for (int n = 0; n < 8; n++) {
        delete[] targets[n];
        delete[] targets;
    }
}

