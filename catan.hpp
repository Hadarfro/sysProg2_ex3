#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"


using namespace std;

class Catan {
    private:
        Board board;
        vector<Player> players;
        size_t currentPlayer;
        int numPlayers;

    public:
        Catan(Player p1,Player p2, Player p3 = Player(), Player p4 = Player());
        void ChooseStartingPlayer();
        Board getBoard();
        void printWinner();
        void printGameState() const;
        void takeCards(int roll);
};
