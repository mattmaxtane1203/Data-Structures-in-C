// Hash Table //

// Hash Map
    // Data is processed by hash mapping using hash function
        // Results in an index

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

// Counter for how much data is in our table //
int counter = 0;

// Initialize struct //
struct NODE{
    char name[100];
    int age;
}*table[SIZE] = {NULL};

// Functions to make our nodes //
NODE* createNode(char _name[], int _age){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    strcpy(newNode->name, _name);
    newNode->age = _age;

    return newNode;
}

int hashFunc(char _c){
    return (_c - 'A') % SIZE;
}

void insert(char _name[], int _age){
    int hashKey = hashFunc(_name[0]);
    int position = hashKey;
    
    // Check if the table is full or not //
    if(counter == SIZE){
        printf("Table is full!\n");
        return;
    }

    // Find empty space //
    while(table[position] != NULL)
        position = (position + 1) % SIZE; // Modulus to loop from the start if it reaches the end //
    

    // If empty space is found
    table[position] = createNode(_name, _age);
    counter++;
}

NODE* searchNode(char _name[]){
    int hashKey = hashFunc(_name[0]);
    int position = hashKey;

    do{
        if(table[position] != NULL && strcmp(table[position]->name, _name) == 0){
            return table[position];
        }
        position = (position + 1) % SIZE;
    } while(position != hashKey);

    return NULL;
}

void printSearchResult(char _name[]){
    NODE* search = searchNode(_name);

    if(search != NULL){
        printf("Data ketemu : %s - %d\n", search->name, search->age);
    } else{
        printf("Data tidak ketemu\n");
    }
}

void deleteNode(char _name[]){
    int hashKey = hashFunc(_name[0]);
    int position = hashKey;

    do{
        if(table[position] != NULL && strcmp(table[position]->name, _name) == 0){
            free(table[position]);
            table[position] = NULL;
            return;
        }
        position = (position + 1) % SIZE;
    } while(position != hashKey);

    return;
}

void printAll(){
    
    for(int index = 0; index < SIZE; index++){
        if(table[index] != NULL){
            printf("%d. %s | %d\n", index, table[index]->name, table[index]->age);
        } else{
            printf("%d. \n", index);
        }
    }
}

int main(){

    insert("Andy", 25);
    insert("Budy", 10);
    insert("Any", 14);
    insert("Ziggy", 30);
    insert("Zzordy", 20);

    return 0;
}