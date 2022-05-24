#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tableSize = 26;

struct Student{

    char name[100];
    int age;

    Student *next;

} *table[tableSize];

Student *createStudent(const char name[], int age){

    // Allocate memory for new student
    Student *newStudent = (Student*)malloc(sizeof(Student));

    // Store new data
    strcpy(newStudent->name, name);
    newStudent->age = age;

    // Set pointers to null
    newStudent->next = NULL;

    return newStudent;
}

int hash(char name[]){
    return ((int)name[0] - 65) % tableSize;
}

void insert(char name[], int age){

    // Make index the hash function of the name
    int index = hash(name);

    // If the table has no data
    if(table[index] == NULL){
        table[index] = createStudent(name, age);
        return;
    }

    
    int point = index + 1;
    while(point != index){

        if(table[point] == NULL){
            table[point] = createStudent(name, age);
            return;
        }
        point = (point + 1) % tableSize;
    }
    printf("Table is full!\n");
}

void view(){

    for(int index = 0; index < tableSize; index++){

        if(table[index] == NULL){
            printf("%d. -\n", index);
        } else{
            printf("%d. %s (%d)\n", index, table[index]->name, table[index]->age);
        }
    }
}

void deleteStudent(char name[]){

    int index = hash(name);
    if(table[index] != NULL && strcmp(table[index]->name, name) == 0){
        free(table[index]);
        table[index] = NULL;
        return;
    }

    int point = index + 1;
    while(index != point){
        if(table[index] != NULL && strcmp(table[index]->name, name)){
            free(table[point]);
            table[point] = NULL;
            return;
        }
        point = (point + 1)  % tableSize;
    }
    printf("%s not found!\n", name);
}

int main(){

    insert("Albert", 22);
    insert("Albertus", 22);
    insert("Vito", 22);
    insert("Budi", 23);
    insert("Krisandy", 24);
    insert("Bella", 25);

    deleteStudent("Maverick");

    view();

    return 0;
}