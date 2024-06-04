#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "player.hpp"
#include "board.hpp"

using namespace std;

Player::Player(const string& myName,const Board& b) : name(myName), board(b), SettelemntAmount(2), roadAmount(2), points(2) {
    cards[Resource::Wood] = 0;
    cards[Resource::Brick] = 0;
    cards[Resource::Sheep] = 0;
    cards[Resource::Wheat] = 0;
    cards[Resource::Ore] = 0;
}

void Player::addResource(Resource resource, int amount) {
    cards[resource] += amount;
}

const Board& Player::getBoard(){
    return board;
}
const string Player::getName() const{
    return name;
}
void Player::placeSettelemnt(int v,Board board){
    if(strcmp(board.getVertcis()[v].owner.getName().c_str(),"") != 0){ 
        cout << "place is taken" << endl;
        return;
    }
    if(this->SettelemntAmount == 0){
        cout << "no settelments to place" << endl;
        return;
    }
    //board.getVertcis()[v].owner.getName() = name;
    this->SettelemntAmount--;
}

void Player::placeRoad(int edge,Board board){
    if(this->roadAmount == 0){
        cout << "no roads to place" << endl;
        return;
    }
    // if(board.getEdges()[v].owner != ""){
    //     cout << "place is taken" << endl;
    // }
    // board.getEdges()[v].owner = this->name;
    this->roadAmount;
}

bool Player::hasResource(Resource resource, int amount) {
    return cards[resource] >= amount;
}

void Player::removeResource(Resource resource, int amount) {
    if (hasResource(resource, amount)) {
        cards[resource] -= amount;
    }
}

// void Player::addDevelopmentCard(const DevelopmentCard& card) {
//     //developmentCards.push_back(card);
// }

void Player::endTurn(){

}

void Player::trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven){
    Resource tradeResource = stringToResource(tradeCard);
    Resource givenResource = stringToResource(givenCard);

    if (tradeResource == Resource::None || givenResource == Resource::None) {
        cout << "Invalid resource type for trading." << endl;
        return;
    }

    if (p.hasResource(tradeResource, amountTrade)) {
        p.removeResource(tradeResource, amountTrade);
        p.addResource(givenResource, amountGiven);
        cout << "Trade successful: " << amountTrade << " " << tradeCard << " for " << amountGiven << " " << givenCard << endl;
    } else {
        cout << "Trade failed: Not enough resources." << endl;
    }
}

void Player::buyDevelopmentCard(){
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Ore, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Ore, 1);

        // DevelopmentCard newCard("Development Card"); // Assuming all development cards are the same for simplicity.
        // this->addDevelopmentCard(newCard);
        // cout << "Development card purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

void Player::printPoints(){

}

int Player::rollDice(){
    int roll = (rand() % 6 + 1) + (rand() % 6 + 1); // Rolling two six-sided dice
    cout << "Dice roll: " << roll << "\n";
    board.distributeResources(roll);
    return roll;
}
