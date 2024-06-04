#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "board.hpp"
#include "player.hpp"


// Constructor with default arguments
Catan::Catan(const Player& p1,const Player& p2,const Player& p3 = Player(),const Player& p4 = Player()) {
    players[0] = NULL;  // Initialize all players to default Player objects
    players[1] = p1;
    players[2] = p2;
    if (p3.getName() != "") {  // Check if a fourth player is provided
        players[3] = p3;
        numPlayers = 3;
    } 
    else if (p4.getName() != "") {  // Check if a third player is provided
        players[4] = p4;
        numPlayers = 4;
    } 
    else {  // Only two players provided
        numPlayers = 2;
    }
}

void Catan::printGameState() const {
    cout << "Current player: " << players[currentPlayer].getName() << "\n";
    board.printBoard();
    for (const auto& player : players) {
        player.printResources();
    }
}

void Catan::ChooseStartingPlayer(){
    // Generate a random number between 1 and 3
    size_t i = rand() % 3 + 1;
    cout << players[i].getName() << endl;
}

Board Catan::getBoard(){
    return board;
}

void Catan::printWinner(){

}

void Catan::takeCards(int roll){

    for (const auto& tile : board.getTiles()) {
        if (tile.number == roll) {
            for (size_t i = 0;i < 3;i++) {
                players[i].addResource(tile.resource,1); // Simplified resource distribution
            }
        }
    }
}
