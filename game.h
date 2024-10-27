#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"   //"player.h", <string>, <vector>

class Game {
public:
    int PlayersPerTeam;
    int maxBalls;
    int totalPlayers;
    std::string players[11];

    bool isFirstInnings;
    Team teamA, teamB;
    Team *battingTeam, *bowlingTeam; 
    Player *batsman, *bowler;

    Game();
    void displayWelcomeMessage();
    void displayInstructions();
    void showAllPlayers();
    int takeIntegerInput();
    void selectPlayers();
    bool validateSelectPlayer(int);
    void showTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void intializePlayers();
    void bat();

};

#endif // GAME_H
