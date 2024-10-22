#include "game.h"

Game::Game() {
    PlayersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Arjun";
    players[1] = "Virat";
    players[2] = "Rohit";
    players[3] = "Dhoni";
    players[4] = "Sachin";
    players[5] = "Dhawan";
    players[6] = "Pant";
    players[7] = "Karthik";
    players[8] = "KLRahul";
    players[9] = "Hardik";
    players[10] = "Jadeja";

    isFirstInnings = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game::displayWelcomeMessage() {
    std::cout << "================================== CRIC-IN ==================================\n";
    std::cout << "                        Welcome to Virtual Cricket Game                       \n";
    
    std::cout << "=============================================================================\n";
    displayInstructions();
}

void Game::displayInstructions() {
    std::cout << "=============================== Instructions ================================\n";
    std::cout << "1. Create 2 teams (Team-A and Team-B with 4 players each) from a given pool of 11 players.\n";
    std::cout << "2. Lead the toss and decide the choice of play.\n";
    std::cout << "3. Each innings will be of 6 balls.\n";
    std::cout << "=============================================================================\n";
}