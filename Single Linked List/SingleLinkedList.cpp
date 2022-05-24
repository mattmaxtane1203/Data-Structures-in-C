#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare struct for student
struct Student{

    char name[100];
    char NIM[10];
    int age;

    Student* next;
} *head, *tail; // Set head and tail of the list as NULL
// 
// Declare constructor
Student* createStudent(char _name[], char _NIM[], int _age){

    // Allocate memory for new student
    Student* newStudent = (Student*)malloc(sizeof(Student));

    // Copy all information
    strcpy(newStudent->name, _name);
    strcpy(newStudent->NIM, _NIM);
    newStudent->age = _age;

    // Set it's next node as NULL
    newStudent->next = NULL;
}

// Push node at head function
void pushHead(Student* newStudent){

    // If there is no head node
    if(head == NULL){

        // Set new student as head and tail
        head = newStudent;
        tail = newStudent;
    } 
    
    // If there is a node
    else{

        // Set the current head as the node next to the new student
        newStudent->next = head;

        // Set new student as head
        head = newStudent;
    }
}

// Push node at tail
void pushTail(Student* newStudent){

    // If there is no tail
    if(tail == NULL){

        // Set new student as head and tail
        head = newStudent;
        tail = newStudent;
    } 
    
    // If there is a tail node already
    else{

        // Set the next node of current tail as the new student
        tail->next = newStudent;

        // Set new student as the tail
        tail = tail->next;
    }
}

// Pop node at head
void popHead(){

    // If there is no head
    if(head == NULL){
        printf("There is no node to delete!\n");
    } 
    
    // If there is only one node
    else if(head == tail){
        
        // Set head and tail to null
        free(head);
        head = NULL;
        tail = NULL;
    } 
    
    // If there is more than one node
    else{

        // Set current head as the node to be deleted
        Student* toBeDeleted = head;

        // Set the node next to head as the head
        head = head->next;

        // Free the node to be deleted
        free(toBeDeleted);
    }
}

// Pop node at the tail of the list
void popTail(){

    // If there is only one data
    if(tail == NULL){
        popHead();
    } 
    
    // If there is more than one data
    else{

        // Set head as the node to be deleted temporarily
        Student* nodeBeforeTail = head;

        // Find node before tail
        while(nodeBeforeTail->next != tail){

            // Set to be deleted as the next node of the temporary node
            nodeBeforeTail = nodeBeforeTail->next;
        }

        // Set the node before tail as the tail
        tail = nodeBeforeTail;

        // Free the node next to tail
        free(tail->next);

        // Set the node next to the tail as NULL
        tail->next = NULL;
    }
}

// Push node in the middle, sorted by age in ascending order
void pushMid(Student* newStudent){

    // If there is no data
    if(head == NULL){
        
        // Set head and tail
        head = newStudent;
        tail = newStudent;
    } 
    
    // If there is data
    else{

        // If new student's name is smaller than head
        if(strcmp(newStudent->name, head->name) <= 0){
            pushHead(newStudent);
        } 

        // If new student's name is larger than tail
        else if(strcmp(newStudent->name, tail->name) >= 0){
            pushTail(newStudent);
        }

        // If new student's name is in the middle
        else{

            // Place a cursor at head
            Student* cursor = head;

            // Move cursor and store previous studen'ts information while new student's name is larger than cursor's name
            Student* prev = NULL;
            while(strcmp(newStudent->name, cursor->name) > 0){
                prev = cursor;
                cursor = cursor->next;
            }

            // Set the next node of new student as cursor
            newStudent->next = cursor;
            prev->next = newStudent;
        }
    }
}

// Pop mid by searching for name
void popMidByName(char _name[]){

    // If there is no data
    if(head == NULL){
        printf("There is no node to delete!\n");
    } 
    
    // If there is data
    else{

        // If the name is the same as head
        if(strcmp(_name, head->name) == 0){
            popHead();
        }

        // If the name is the same as tail
        else if(strcmp(_name, tail->name) == 0){
            popTail();
        }

        // If the name lies in the middle
        else{

            // Place a cursor by head
            Student* cursor = head;

            // Find the node before the node with the inserted name by moving the cursor forward
            // Move cursor while it is not the last node and the name of the node is not the same
            while(cursor->next != NULL && strcmp(_name, cursor->next->name) != 0){
                cursor = cursor->next;
            }

            // Display message if node with name is not found
            if(cursor->next == NULL){ // Cursor is on the last node
                printf("Name not found!\n");
            } 
            
            // If the node next to cursor is the inserted name
            else{

                // Set node next to cursor as the node to be deleted
                Student* toBeDeleted = cursor->next;

                // Set the node next to cursor as the node next to be the one to be deleted
                cursor->next = toBeDeleted->next;

                // Free node
                free(toBeDeleted);
            }
        }
    }
}

// Print the single linked list
void printSLL(){

    // Set cursor at head
    Student* cursor = head;

    // Do not execute if cursor is NULL
    while(cursor != NULL){

        // Print data
        printf("Nama : %s\n", cursor->name);
        printf("NIM : %s\n", cursor->NIM);
        printf("Usia : %d\n", cursor->age);
        puts("\n");

        // Move cursor to the next node
        cursor = cursor->next;
    }
}

int main(){

    pushMid(createStudent("Abraham", "2501968451", 19));
    pushMid(createStudent("Ciu", "2501968453", 19));
    pushMid(createStudent("Bernard", "2501968454", 20));

    printSLL();

    popTail();
    printSLL();

    return 0;
}