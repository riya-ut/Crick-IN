#include <iostream>
#include "game.h"
using namespace std;

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
    players[8] = "KLRahu";
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

void Game:: showAllPlayers() {

    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "=========Pool of Players==========" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < totalPlayers; i++)
    {
        cout <<"\t\t["<< i << "]" << players [i] << endl;
    }
}

int Game :: takeIntegerInput() {

    int n;

    while (!(cin >> n))
    {
        cin.clear();            // Clear any error flags that may have been set on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        // Clear input buffer until newline
        cout << "Invalid input! Please try again with a valid input: ";
    }

    return n; 
    
}

void Game::selectPlayers() {
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "|========== Create Team-A and Team-B ==========|" << endl;
    cout << "------------------------------------------------" << endl;
    
    for (int i = 0; i < PlayersPerTeam; i++)
    
        {
        //Add player to TeamA 

        teamASelection:
            cout << endl << "Select players" << i + 1 << "of Team A-";

            int playerIndexTeamA = takeIntegerInput ();

            if (playerIndexTeamA < 0 || playerIndexTeamA >10)
            {
                cout << endl << "Please select from the given players" << endl;
                goto teamASelection;
            } else if (!validateSelectPlayer (playerIndexTeamA))
            {
                cout << endl << "Please select from the given players" << endl;
                goto teamASelection;
            }
            
            else {
                Player teamAPlayer;
                teamAPlayer.id = playerIndexTeamA;
                teamAPlayer.name = players [playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);

            }

            // Add player to team B 
            
            teamBSelection:
            cout << endl << "Select player" << i+1 << " of team B-";
            int playerIndexTeamB = takeIntegerInput ();
             if (playerIndexTeamB < 0 || playerIndexTeamB >10)
            {
                cout << endl << "Please select from the given players" << endl;
                goto teamBSelection;
            } else if (!validateSelectPlayer (playerIndexTeamA))
            {
                cout << endl << "Please select from the given players" << endl;
                goto teamBSelection;
            }
             else {
                Player teamBPlayer;
                teamBPlayer.id = playerIndexTeamB;
                teamBPlayer.name = players [playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
                    
            }

    }
    
}





