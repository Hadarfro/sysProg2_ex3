#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <string>
#include <cstdlib>
#include "catan.hpp"
#include "resource.hpp"
#include "player.hpp"
#include "board.hpp"

class Player;
using namespace std;


// Tile class
class Tile {
    public:
        Resource resource;
        int number;
        vector<Tile> neighbors;
        vector<int> vertcies;
        Tile(Resource resource, int number = 0,vector<Tile> myneighbors = {},vector<int> myvertcies = {}) : resource(resource), number(number) {
            neighbors = myneighbors;
            vertcies = myvertcies;
        }
        int getNumber() const{
            return number;
        }
};

// Vertex class
class Vertex {  
    public:
        string ownerName;
        vector<Tile> adjacentTiles;
        void addAdjacentTile(vector<Tile> tile) {
            for(size_t i = 0;i < tile.size();i++){
                adjacentTiles.push_back(tile[i]);
            }
        }
        Vertex(string o = "", vector<Tile> adjacentTiles = {})
        : adjacentTiles(adjacentTiles), ownerName(o) {
            // owner is not initialized here
        }
};

// Edge class
class Edge {
    public:
        int id;
        int vertex1;
        int vertex2;
        Edge(int id, int vertex1, int vertex2)
            : id(id), vertex1(vertex1), vertex2(vertex2) {}
    };

// Board class
class Board {
    private:
        vector<Tile> tiles;
        vector<Vertex> vertices;
    public:
        Board();

        vector<Tile>& getTiles(){
            return tiles;
        }

        vector<Vertex>& getVertcis(){
            return vertices;
        }


        void printBoard() const {
            for (const auto& tile : tiles) {
                //std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
            }
        }
        void distributeResources(int roll,Player* p) const; 
};
