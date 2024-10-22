#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "player.h" 
class Team {
public:
    std::string name;
    std::vector<Player> players;
    int totalRunsScored;
    int wicketsLost;
    int ballsBowled;

    Team(); 
};

#endif // TEAM_H
