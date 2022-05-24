#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int tableSize = 26;

// Create structure
struct Student{

    char name[100];
    int age;

    Student *next;
} *head[tableSize] = {NULL}, *tail[tableSize] = {NULL};

Student *createStudent(char _name[], int _age){

    // Allocate memory for new student
    Student *newStudent = (Student*)calloc(1, sizeof(Student));

    // Store data
    strcpy(newStudent->name, _name);
    newStudent->age = _age;

    // Set pointers
    newStudent->next = NULL;

    return newStudent;
}

// Create function to hash the name
int hash(char _name[]){

    return (_name[0] - 65) % tableSize;
}

void insert(char _name[], int _age){

    // ... Hash function the name
    int index = hash(_name);

    // Create new student
    Student *newStudent = createStudent(_name, _age);

    // If there is position has no data
    if(head[index] == NULL){
        head[index] = tail[index] = newStudent;
        return;
    }

    // If there is data in that position
    tail[index]->next = newStudent;
    tail[index] = newStudent;
}

void deletes(char _name[]){

    // Hash to get index
    int index = hash(_name);

    // If to delete is same as head
    if(strcmp(head[index]->name, _name) == 0){
        Student *toBeFreed = head[index];
        head[index] = head[index]->next;
        free(toBeFreed);
        return;
    }

    // Place cursor at head
    Student *cursor = head[index];

    // Initialize prev to record previous data
    Student *prev = NULL;
    while(cursor != NULL && strcmp(cursor->name, _name) != 0){
        prev = cursor;
        cursor = cursor->next;
    }

    if(cursor != NULL){
        free(cursor);
        prev->next = NULL;
        return;
    }

    // Print message saying name not found
    printf("%s not found\n", _name);
}

// Print function
void printHashTable(){

    for(int index = 0; index < tableSize; index++){

        // Place cursor
        Student *cursor = head[index];
        printf("%d. ", index + 1);

        // Print and move cursor forward while cursor has data
        while(cursor != NULL){

            // Print
            printf("%s %d --> ", cursor->name, cursor->age);

            // Move cursor forward
            cursor = cursor->next;
        }

        // Line break
        printf("\n");
    }
}

int main(){

    insert("Matthew", 19);
    insert("Anselmus", 18);
    insert("Anderson", 21);

    printHashTable();

    deletes("Anderson");

    printHashTable();

    return 0;
}