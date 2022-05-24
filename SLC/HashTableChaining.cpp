#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tableSize = 26;

struct Student{

    char name[255];
    int age;

    Student *next;
} *head[tableSize] = {NULL}, *tail[tableSize] = {NULL};

Student *createStudent(char name[], int age){

    // Allocate memory for new student
    Student *newStudent = (Student*)malloc(sizeof(Student));

    // Store data to struct
    strcpy(newStudent->name, name);
    newStudent->age = age;

    // Set pointers
    newStudent->next = NULL;
    
    return newStudent;
}

int hashFunction(char name[]){
    return (name[0] - 65) % tableSize;
}

void insert(char name[], int age){

    // Get index to store the data
    int index = hashFunction(name);

    // Create new student
    Student *currentStudent = createStudent(name, age);

    // Insert student
    // 1. If there is no data in that position
    if(head[index] == NULL){
        head[index] = tail[index] = currentStudent;
    } else{
        // 2. If there is data
        tail[index]->next = currentStudent;
        tail[index] = currentStudent;
    }
}

void print(){

    for(int index = 0; index < tableSize; index++){

        Student *cursor = head[index];
        printf("%d. ", index);

        // While cursor has data
        while(cursor){
            printf("%s, %d -> ", cursor->name, cursor->age);
            
            // Move cursor to the next data
            cursor = cursor->next;
        }
        printf("\n");
    }
}

int main(){

    insert("Andy", 25);
    insert("Andy", 25);
    insert("Andy", 25);

    print();
    
    return 0;
}