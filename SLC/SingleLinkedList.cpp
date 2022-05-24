#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{

    char name[100];
    int age;

    Student *next;

} *head, *tail;

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

void pushHead(const char name[], int age){

    // Create new student
    Student *newStudent = createStudent(name, age);

    // 1. If no data
    // Head = NULL
    if(head == NULL){
        head = newStudent;
        tail = newStudent;
    } else{

        // 2. If there is data
        // Head != NULL
        newStudent->next = head;
        head = newStudent;
    }
}

void pushTail(const char name[], int age){

    // Create student
    Student *newStudent = createStudent(name, age);

    // 1. If there is no data
    // head = NULL
    if(head = NULL){

        head = newStudent;
        tail = newStudent;
    } else{

        // 2. If there is data
        tail->next = newStudent;
        tail = newStudent;
    }
}

void pushMidByName(const char name[], int age){

    // Create new student
    Student *newStudent = createStudent(name, age);

    // 1. If there is no data
    // head = NULL
    if(head == NULL){
        head = newStudent;
        tail = newStudent;
    } else{

        // 2. If there is data

    }
}

void pushMidByAge(){


}

// Pop Functions //

void popHead(){

    // 1. If there is no data
    if(head == NULL){

        return;
    } else if(head == tail){

        // 2. If there is only one data
        free(head);
        head = tail = NULL;
    } else{

        // 3. If there is more than one data
        Student *toBeDeleted = head;
        head = head->next;
        free(toBeDeleted);
        toBeDeleted = NULL;
    }

}

void popTail(){

    // 1. If there is no data
    if(head == NULL){

        return;
    } else if(head == tail){

        // 2. If there is only one data
        free(head);
        head = tail = NULL;
    } else{

        // 3. If there is more than one data
        Student *cursor = head;
        while(cursor->next != tail){
            cursor = cursor->next;
        }

        tail = cursor;
        free(tail->next);
        tail->next = NULL;
    }
}

void popByName(const char name[]){

    if(head == NULL){
        return;
    } else if(strcmp(name, head->name) == 0){
        popHead();
    } else if(strcmp(name, head->name) == 0){
        popTail();
    } else{

        Student *cursor = head;
        while(cursor != tail && strcmp(cursor->next->name, name) != 0){
            cursor = cursor->next;
        }

        if(cursor == tail){
            printf("%s not found\n", name);
        }

        Student *toBeDeleted = cursor->next;
        cursor->next = toBeDeleted->next;
        free(toBeDeleted);
        toBeDeleted = NULL;
    }
}

// Other Functions //

Student *search(const char name[]){

    Student *cursor = head;
    while(cursor != NULL){
        cursor = cursor->next;

        if(strcmp(cursor->name, name) != 0){
            return cursor;
        }
    }

    return NULL;
}

void updateValue(const char name[], const char newName[], int age){

    if(head == NULL){
        return;
    }
    Student *cursor = head;
    while(cursor != NULL){
        if(strcmp(cursor->name, name) == 0){
            strcpy(cursor->name, newName);
            cursor->age = age;
            return;
        }
        cursor = cursor->next;
    }
}

int main(){

    pushHead("Renaldi", 19);
    pushHead("Erwin", 20);
    pushHead("Farhan", 25);
    pushHead("Greg", 17);

    Student *searchingFor = search("Erwin");
    if(searchingFor != NULL){
        printf("Found %s\n", searchingFor->name);
    } else{
        printf("Not found!\n");
    }

    updateValue("Farhan", "Nyoman", 29);

    return 0;
}
