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

bool Game:: validateSelectPlayer(int index) {
    int n;
    vector <Player>players;

    players = teamA.players;
    n= players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
      
    }
    
    players = teamB.players;
    n= players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
      
    }

    return true;
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
            int playerIndexTeamA = takeIntegerInput();

            if (playerIndexTeamA < 0 || playerIndexTeamA >10)
            {
                cout << endl << "Please select from the given players" << endl;
                goto teamASelection;
            } else if (!validateSelectPlayer (playerIndexTeamA))
            {
                cout << endl << "Player has been already selected. Please select other player" << endl;
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
            } else if (!validateSelectPlayer (playerIndexTeamB))
            {
                cout << endl << "Player has been already selected. Please select other player" << endl;
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

void Game::showTeamPlayers() {

    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < PlayersPerTeam; i++) {
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}

void Game::toss() {
    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "|========== Lets's Toss ==========|" << endl;
    cout << "-----------------------------------" << endl;

    cout << "Tossing the coin...." << endl << endl;

    srand(time (NULL));
    int randomValue = rand() % 2;   //0 or 1

    switch ( randomValue)
    {
    case 0:
        cout << "Team-A won the toss" << endl << endl;
        tossChoice(teamA);
        break;
    
    case 1:
    cout << "Team-B won the toss" << endl << endl;
    tossChoice(teamB);
    break;
    }

}

void Game::tossChoice(Team tossWinnerTeam){

cout << "Enter 1 to bat or 2 to bowl first. " << endl
     << "1. Bat" << endl
     << "2. Bowl" << endl;

int tossInput = takeIntegerInput();

cin.ignore (numeric_limits<streamsize>::max(), '\n');

switch (tossInput)
{
case 1:
    cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl<< endl;
    
    if (tossWinnerTeam.name.compare("Team-A") == 0)
    {       //if Team-A is the toss winner
        battingTeam = &teamA;
        bowlingTeam = &teamB;
    } else {    //else Team-B is the toss winner
        battingTeam = &teamB;
        bowlingTeam = &teamA;
    }
    
    break;

case 2:
    cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl<< endl;
    
    if (tossWinnerTeam.name.compare("Team-A") == 0)
    {       //if Team-A is the toss winner
        battingTeam = &teamA;
        bowlingTeam = &teamB;
    } else {    //else Team-B is the toss winner
        battingTeam = &teamB;
        bowlingTeam = &teamA;
    }
    break;
default:
    cout << endl << "Invalid input please try again" << endl << endl;
    tossChoice(tossWinnerTeam);
    break;
}

}

void Game::startFirstInnings() {
    cout << "\t\t ||| FIRST INNINGS START ||| " << endl << endl;
    isFirstInnings = true;
    intializePlayers();
    playInnings();
}

void Game::intializePlayers() {
    // Choose batsman and bowler: Intialize *batsman and *bowler
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam-> players[0];
    cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}
void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bat();
		
	    if (!validateInningsScore()) {
	    	break;
	    }
	}

}

void Game::bat() {
    srand(time(NULL));
	int runsScored = rand() % 7;
    // Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->ballsBowled = bowlingTeam->ballsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
    cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

}







bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == PlayersPerTeam || bowlingTeam->ballsBowled == maxBalls) {
			
			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;
			
			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->ballsBowled
					<< ")" << endl;
			
			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings

    }

	return true;
}













