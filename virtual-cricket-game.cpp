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
    
    return 0;
}
