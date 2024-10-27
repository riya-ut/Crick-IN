#include "game.h"
using namespace std;

int main() {
    Game game;
    game.displayWelcomeMessage();

    cout <<"\nPress Enter to Continue";
    getchar();

    game.showAllPlayers();

    cout <<"\nPress Enter to Continue";
    getchar();

    game.selectPlayers();
    game.showTeamPlayers();
    
    cin.ignore (numeric_limits<streamsize>::max(), '\n');

    cout << "\nPress Enter to toss";
    getchar();

    game.toss();

    game.startFirstInnings();
    
    return 0;
}
