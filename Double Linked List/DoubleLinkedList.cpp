#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct
struct Student{

    char name[100];
    char NIM[11];
    int age;

    Student *next;
    Student *prev;
} *head, *tail;

// Student *head = NULL;
// Student *tail = NULL;

// Declare constructor
Student *createStudent(char _name[], char _NIM[], int _age){

    // Allocate memory for new student
    Student *newStudent = (Student*)malloc(sizeof(Student));

    // Set new student's information
    strcpy(newStudent->name, _name);
    strcpy(newStudent->NIM, _NIM);
    newStudent->age = _age;

    // Set pointers
    newStudent->next = NULL;
    newStudent->prev = NULL;
}

// Head-related Functions
void pushHead(char name[], char NIM[], int age){

    // Create new student
    Student* newStudent = createStudent(name, NIM, age);

    // If there is no data
    if(head == NULL){

        // Set new student as head and tail
        head = newStudent;
        tail = newStudent;
    } 
    
    // If there is data
    else{

        newStudent->next = head;
        head->prev = newStudent;
        head = head->prev;
    }
}

void popHead(){

    // If there is no data
    if(head == NULL){
        printf("There is no node to remove!\n");
    }

    // If there is only one data
    else if(head == tail){

        // Free the node
        free(head);

        // Set head and tail as null
        head = NULL;
        tail = NULL;
    }

    // If there is data
    else{

        // Set the node after the head as the head
        head = head->next;

        // Free node
        free(head->prev);

        // Set current head's prev as null
        head->prev = NULL;
    }
}

// Tail-related Functions
void pushTail(char name[], char NIM[], int age){

    // Construct new student
    Student* newStudent = createStudent(name, NIM, age);

    // If there is no data
    if(tail == NULL){

        // Set new student as head and tail
        head = newStudent;
        tail = newStudent;

        // // Alternative
        // pushHead(name, NIM, age);
    }

    // If there is more than one data
    else{

        // Set new student as next node of tail
        tail->next = newStudent;

        // Set node previous to new student as the tail
        newStudent->prev = tail;

        // Set new student as tail
        tail = newStudent;
    }
}

void popTail(){

    // If there is no data
    if(tail == NULL){
        printf("There is no node to remove!\n");
    }

    // If there is one data
    else if(head == tail){

        // Pop head
        popHead();
    }

    // If there is more than one data
    else{

        // Move tail to previous node
        tail = tail->prev;

        // Free the node
        free(tail->next);

        // Set node next to tail as null
        tail->next = NULL;
    }
}

// Mid-related functions
void pushMidByName(char name[], char NIM[], int age){

    // Create new student
    Student* newStudent = createStudent(name, NIM, age);

    // If there is no data
    if(head == NULL){
        
        // Set new student as head and tail
        head = newStudent;
        tail = newStudent;
    }

    // If there is data
    else{

        // If name is smaller in ASCII value than head
        if(strcmp(name, head->name) <= 0){
            pushHead(name, NIM, age);
        }

        // If name is larger in ASCII value than tail
        else if(strcmp(name, tail->name) >= 0){
            pushTail(name, NIM, age);
        }

        else {

            // Place cursor on head
            Student* cursor = head;

            // Move cursor while cursor's ASCII value is more
            while(strcmp(name, cursor->name) > 0){
                cursor = cursor->next;
            }

            // Set new student pointers
            newStudent->next = cursor;
            newStudent->prev = cursor->prev;
            cursor->prev->next = newStudent;
            cursor->prev = newStudent;
        }

    }

}

void popMidByName(char name[]){

    // If name is in head
    if(strcmp(name, head->name) == 0){
        popHead();
    }

    // If name is same as the tail
    else if(strcmp(name, tail->name) == 0){
        popTail();
    }

    else{

        // Place cursor
        Student* cursor = head;

        // Move cursor until name is found
        while(strcmp(name, cursor->name) != 0){
            cursor = cursor->next;
        }

        // Make the next node's previous node the node before the cursor
        cursor->next->prev = cursor->prev;

        // Make the previous node's next node the node next to the cursor
        cursor->prev->next = cursor->next;
        
        // Free node
        free(cursor);
    }

}

// Print Double Linked List
void printDLL(){

    if(!head){
        printf("No Data!\n");
        return;
    }

    // Place cursor
    Student* cursor = head;

    // Move cursor while printing
    while(cursor != NULL){
        
        if(cursor->next == NULL){
            printf("(%s, %s, %d)", cursor->name, cursor->NIM, cursor->age);
            break;
        }

        printf("(%s, %s, %d) --> ", cursor->name, cursor->NIM, cursor->age);

        // Increment cursor
        cursor = cursor->next;
    }
}

void popAll(){

    // While there is a head
    Student *cursor = head;
    while(cursor){
        head = head->next;
        free(cursor);
    }
}

int main(){

    pushMidByName("Anderson", "2501968451", 17);
    pushMidByName("Matthew", "2837496753", 19);
    pushMidByName("Wira", "2734993847", 17);
    pushMidByName("Nathan", "2508928746", 19);

    popMidByName("Matthew");

    // popTail();

    printDLL();

    popAll();

    printDLL();

    return 0;
}

// --- END --- //