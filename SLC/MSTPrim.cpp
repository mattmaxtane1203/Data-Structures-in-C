#include <stdio.h>
#include <string.h>
#include <limits.h>

// Define amount of vertices
#define V 5

int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

int main(){

    // Initialize array for visited vertices
    int visited[V];

    memset(visited, false, sizeof(visited)); // Set all values in visited to false

    visited[0] = true; // The first node will always be visited
    int edge = 0; // Define initial amount of edges
    // Edge is made to 0 because no edges set yet

    int min = INT_MAX; // Set minimuim to the highest possible integer
    // In order to be able to be safe when setting the minimum

    int x, y;

    int cost = 0;

    // Loop to find shortest path
    while(edge < V - 1){

        // Reset minimum
        min = INT_MAX;

        // Loop to find unvisited nodes
        for(int i = 0; i < V; i++){
            if(visited[i]){

                for(int j = 0; j < V; j++){
                    if(graph[i][j] && !visited[j]){
                        // If the weight is not 0 and it has not been visited
                        // Check if it is smaller than minimum
                        if(graph[i][j] < min){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = true;
        printf("%d - %d = %d\n", x, y, graph[x][y]);
        cost += graph[x][y];
        edge++;
    }

    printf("Cost = %d", cost);

    return 0;
}