#include <stdio.h>

// Define amount of vertices
#define V 5

typedef struct Edge{

    int source;
    int destination;
    int weight;

} Edge;

typedef struct Edge_List{

    // To store the edges
    Edge data[30];
    int size;
    int edges;

} Edge_List;

Edge_List tree;
Edge_List mst;

int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

void sort(){

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V - 1; j++){

            if(tree.data[j].weight > tree.data[j + 1].weight){
                Edge temp = tree.data[i];
                tree.data[j] = tree.data[j + 1];
                tree.data[j+1] = temp;
            }
        }
    }
}

void setUnion(int parents[], int parents1, int parents2){

    for(int i = 0; i < V; i++){
        if(parents[i] == parents2){
            parents[i] = parents1;
        }
    }
}

void kruskal(){
    tree.edges = 0;
    for(int i = 1; i < V; i++){
        for(int j = 0; j < i; j++){
            // printf("%d %d\n", i, j);
            if(graph[i][j]){
                tree.data[tree.edges].source = i;
                tree.data[tree.edges].destination = j;
                tree.data[tree.edges].weight = graph[i][j];
                tree.edges++;
            }
        }
    }
    
    // Make MST
    sort();
    int parents[V];
    for(int i = 0; i < V; i++){
        parents[i] = i;
    }

    mst.edges = 0;

    int parents1, parents2;
    for(int i = 0; i < V; i++){
        parents1 = parents[tree.data[i].source];
        parents2 = parents[tree.data[i].destination];

        if(parents1 != parents2){
            mst.data[mst.edges] = tree.data[i];
            mst.edges++;
            setUnion(parents, parents1, parents2);
        }
    }

}

int main(){


    return 0;
}
