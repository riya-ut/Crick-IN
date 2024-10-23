#include "game.h"
using namespace std;

int main() {
    Game game;
    game.displayWelcomeMessage();

    cout <<"\nPress Enter to Continue";
    getchar();

    game.showAllPlayers();
    
    return 0;
}
