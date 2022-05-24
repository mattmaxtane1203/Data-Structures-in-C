#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct
struct Student{

    char nama[31];
    int usia;

    Student *next = NULL;
    Student *prev = NULL;
} *head, *tail;

// Declare constructor
Student *createStudent(char _nama[], int _usia){

    // Alokasi memori
    Student *newStudent = (Student*)malloc(sizeof(Student));

    // Simpan data ke variabel
    strcpy(newStudent->nama, _nama);
    newStudent->usia = _usia;

    newStudent->next = NULL;
    newStudent->prev = NULL;
}

void enQueue(char _nama[], int _usia){ // PUSH HEAD

    // Bikin mhs
    Student *newStudent = createStudent(_nama, _usia);

    // Kalo tidak ada node
    if(head == NULL){

        head = tail = newStudent;
        // head = newStudent;
        // tail = newStudent;
        return;
    }

    // Kalo ada data
    newStudent->next = head;
    head->prev = newStudent;
    head = head->prev;
}

void deQueue(){ // POP TAIL

    // Kalo tidak ada data
    if(tail == NULL){
        printf("Tidak ada data\n");
        return;
    }

    // Kalo ada data
    tail = tail->prev;
    free(tail->next);
    tail->next = NULL;
}

void printQueue(){

    // Taro kursor
    Student *cursor = head;

    // Print nodenya dan majuin kursor
    while(cursor != NULL){

        printf("(%s, %d) --> ", cursor->nama, cursor->usia);

        cursor = cursor->next;
    }

}

int main(){

    enQueue("Matthew", 19);
    enQueue("Daniel", 18);
    enQueue("Nathan", 20);

    deQueue();

    printQueue();
    
    return 0;
}
