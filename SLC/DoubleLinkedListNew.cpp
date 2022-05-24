#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	
	char name[100];
	int age;
	
	Student *next;
	Student *prev;
	
} *head, *tail;

Student *createStudent(const char name[], int age){
	
	// Allocate memory for new student
	Student *newStudent = (Student*)malloc(sizeof(Student));
	
	// Store new variables
	strcpy(newStudent->name, name);
	newStudent->age = age;
	
	// Set pointers to null
	newStudent->next = NULL;
	newStudent->prev = NULL;
	
	return newStudent;
}

void pushHead(const char name[], int age){
	
	// Create new student
    Student *newStudent = createStudent(name, age);

    // 1. If no data
    // Head = NULL
    if(head = NULL){
        head = newStudent;
        tail = newStudent;
    } else{

        // 2. If there is data
        // Head != NULL
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
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
        head = head->next;
        free(head->prev);
        head->prev = NULL;
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

        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
}

void view(){

	Student *cursor = head;
	while(cursor){
		printf("Name: %s Age: %d", cursor->name, cursor->age);
		cursor = cursor->next;
	}
}

int main(){
	
	pushHead("Matthew", 20);
	view();
	
	return 0;
}
