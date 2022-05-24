// Double Linked List //
    // Can point both forward and backwards in their data

// Stack
    // Last In, First Out (LIFO)
    // Similar to a stack of books
        // The last stack is on top, which means to rearrange, that one goes out first
    // Mix of push tail and pop tail
// Queue
    // First In, First Out (FIFO)
    // Similar to a queue
    // Mix of push tail and pop head

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct declaration //
struct STUDENT{
    // Attributes //
    char name[64];
    int age;
    double ipk;

    // Pointers //
    STUDENT* next;
    STUDENT* prev;
};

// Head and Tail declaration //
STUDENT* head = NULL;
STUDENT* tail = NULL;

// Custom Constructor declaration //
STUDENT* createStudent(char _name[], int _age, double _ipk){

    // Memory Allocation for new student //
    STUDENT* newStudent = (STUDENT*)malloc(sizeof(STUDENT));

    // Build student attributes //
    strcpy(newStudent->name, _name);
    newStudent->age = _age;
    newStudent->ipk = _ipk;

    // Set pointer to NULL //
    newStudent->next = NULL;
    newStudent->prev = NULL;

    return newStudent;
}

// Push Head
void pushHead(STUDENT* newStudent){
    if(head == NULL){
        head = newStudent;
        tail = newStudent;
    } else{
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
    }
}

// Push Tail
void pushTail(STUDENT* newStudent){
    if (tail == NULL){
        head = newStudent;
        tail = newStudent;
    } else{
        newStudent->prev = tail;
        tail->next = newStudent;
        tail = newStudent;
    }
}

// Push Mid //
void pushMidByName(STUDENT* newStudent){ // Insert data sorted by name in ascending order //
    if(head == NULL){ // 1. If there is no data
        head = newStudent;
        tail = newStudent;
    } else{ // 2. If there is data
        if(strcmp(newStudent->name, head->name) <= 0){ // If new value <= head value
            pushHead(newStudent); //TODO: Implement pushHead();

        } else if(strcmp(newStudent->name, tail->name) >= 0){ // if new value >= tail value
            pushTail(newStudent); //TODO: Implement pushTail();

        } else{ // else
            STUDENT* cursor = head;

            while(strcmp(newStudent->name, cursor->name) > 0){
                cursor = cursor->next;
            }

            newStudent->next = cursor;
            newStudent->prev = cursor->prev;
            cursor->prev->next = newStudent;
            cursor->prev = newStudent;
        }
    }
}

// Pop Head //
void popHead(){
    if(head == NULL){
        printf("No data!\n");
    } else if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
    } else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}

// Pop Tail //
void popTail(){
    if(head == NULL){
        printf("No data!\n");
    } else if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
    } else{
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
}

// Pop Mid //
void popMidByName(char _name[]){
    if(head == NULL){
        printf("No Data!\n");
    } else{
        if(strcmp(_name, head->name) == 0){
            popHead(); //TODO: implement
        } else if(strcmp(_name, tail->name) == 0){
            popTail(); //TODO: implement
        } else{
            STUDENT* cursor = head->next;

            while(cursor != NULL && strcmp(_name, cursor->name) != 0){
                cursor = cursor->next;
            }

            if(cursor == NULL){
                printf("Data not found!\n");
            } else{
                cursor->next->prev = cursor->prev;
                cursor->prev->next = cursor->next;
                free(cursor);
            }
        }
    }
}

// Pop All //
void popAll(){
    while(head != NULL){
        popHead();
    }
}

void printAll(){
    STUDENT* cursor = head;

    while(cursor != NULL){
        printf("Name: %s\n", cursor->name);
        printf("Age: %d\n", cursor->age);
        printf("IPK: %.2lf\n", cursor->ipk);
        printf("\n");

        cursor = cursor->next;
    }
}

// Main function //
int main(){
    pushMidByName(createStudent("Charlie", 24, 2.9));
    pushMidByName(createStudent("Boris", 21, 3.4));
    pushMidByName(createStudent("Emily", 24, 4.0));
    pushMidByName(createStudent("Dawson", 14, 0.1));

    popAll();

    printAll();

    return 0;
}
