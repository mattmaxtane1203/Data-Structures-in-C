#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define INFINITE INT_MAX

using namespace std;

char map[MAP_HEIGHT + 1][MAP_WIDTH + 1] = {
	"####################",
	"#      #           #",
	"#      #           #",
	"#      #           #",
	"#      #      #    #",
	"#      #      #    #",
	"#             #    #",
	"#             #    #",
	"#             #    #",
	"####################"
};

struct Tile{

    // Position information
    int x;
    int y;

    // Parent information
    Tile *parent;

    // Visited or not
    bool visited;

    // Cost of tile
    int cost;

    // What symbol represents the tile in the map
    char symbol;

    // Make constructor
    Tile (int x, int y, char symbol){

        // Store data into variables
        this->x = x;
        this->y = y;
        this->parent = NULL; // Parent stil unknown
        this->visited = false; // Has not been visited yet
        this->cost = INFINITE; // Cost still unknown
        this->symbol = symbol;
    }

} *tileMap[MAP_HEIGHT + 1][MAP_WIDTH + 1]; // Make it a pointer

// Initialize start and end point
int startX, startY, endX, endY;

// Make Tile Queue
vector<Tile*> tileQueue;

// Make function to intialize and set the map
void initializeMap(){

    for(int row = 0; row < MAP_HEIGHT; row++){
        for(int column = 0; column < MAP_WIDTH; column++){

            // Create a new tile
            tileMap[row][column] = new Tile(column, row, map[row][column]);
        }
    }

    // Set start and end position
    startX = 3;
    startY = 2;

    endX = 16;
    endY = 7;

    // Set cost of starting position to 0
    tileMap[startY][startX]->cost = 0;

    // Insert starting tile to queue
    tileQueue.push_back(tileMap[startY][startX]);
}

// Make function to print the map
void printMap(){

    for(int row = 0; row < MAP_HEIGHT; row++){
        for(int column = 0; column < MAP_WIDTH; column++){

            if(row == startY && column == startX){
                printf("S"); // To symbolize starting position
            } else if(row == endY && column == endX){
                printf("E"); // To symbolize end position
            } else{
                printf("%c", tileMap[row][column]->symbol); // Print corresponding symbol
            }
        }
        puts("");
    }
}

void dijkstra(){

    // Do dijkstra while the tile queue is not empty and the end tile is not visited
    while(!tileQueue.empty() && !tileMap[endY][endX]->visited){

        // Initialize and set minimum index and cost
        int minIndex = 0;
        int minCost = tileQueue[0]->cost; // Set cost of first tile as minimum cost

        // Loop to find minimum cost from all tile queues
        for(int queueIndex = 0; queueIndex < tileQueue.size(); queueIndex++){

            if(tileQueue[queueIndex]->cost < minCost){
                minCost = tileQueue[queueIndex]->cost;
                minIndex = queueIndex;
            }
        }

        Tile *currentTile = tileQueue[minIndex];
        int currentX = currentTile->x;
        int currentY = currentTile->y;

        // If current tile has been visited, delete tile from queue and continue
        if(tileMap[currentY][currentX]->visited){
            tileQueue.erase(tileQueue.begin() + minIndex);
            continue;
        } else{ // Else, move

            // Use coordinates to move
            int xDirection[4] = {1, -1, 0, 0};
            int yDirection[4] = {0, 0, 1, -1};

            for(int index = 0; index < 4; index++){
                
                // Move if the next tile is not visited and not a wall
                if(tileMap[currentY + yDirection[index]][currentX + xDirection[index]]->visited && tileMap[currentY + yDirection[index]][currentX + xDirection[index]] != '#' && tileMap[currentY + yDirection[index]][currentX + xDirection[index]]->cost < tileMap[currentY][currentX]->cost + 1)
            }
        }
    }
}

int main(){

    initializeMap();

    printMap();

    return 0;
}
