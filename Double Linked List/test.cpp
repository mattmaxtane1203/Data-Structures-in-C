#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bikin struct mahasiswa
struct Student{

    char nama[31];
    int usia;

    Student *next = NULL;
    Student *prev = NULL;
} *head, *tail;

// Student *head = NULL;
// Student *tail = NULL;

Student *createStudent(char _nama[], int _usia){

    // Alokasi memori
    Student *newStudent = (Student*)malloc(sizeof(Student));

    // Simpan data ke variabel
    strcpy(newStudent->nama, _nama);
    newStudent->usia = _usia;

    newStudent->next = NULL;
    newStudent->prev = NULL;
}

// Push Head
void pushHead(char _nama[], int _usia){

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

// Pop Head
void popHead(){

    // Kalo tidak ada data, print error message
    if(head == NULL){
        printf("Tidak ada data!\n");
        return;
    }

    // Kalo ada data
    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

// Push Tail
void pushTail(char _nama[], int _usia){

    // Bikin mhs
    Student *newStudent = createStudent(_nama, _usia);

    // Kalo tidak ada data
    if(tail == NULL){

        head = newStudent;
        tail = newStudent;
        return;
    }

    // Kalo ada data
    tail->next = newStudent;
    newStudent->prev = tail;
    tail = tail->next;
}

// Pop Tail
void popTail(){

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

// Push Mid 
void pushMidByName(char _nama[], int _usia){

    // Bikin mhs
    Student *newStudent = createStudent(_nama, _usia);

    // Kalo ada data atau tidak
    if(head == NULL){

        head = newStudent;
        tail = newStudent;
        return;
    }

    // Kalo nama ASCIInya < head punya nama
    if(strcmp(_nama, head->nama) <= 0){
        pushHead(_nama, _usia);
        return;
    }

    // Kalo nama ASCIInya > tail punya nama
    if(strcmp(_nama, tail->nama) >= 0){
        pushTail(_nama, _usia);
        return;
    }

    // Kalo nama posisinya di tengah
    // Taro kursor
    Student *cursor = head;

    // Pindahin kursor selama ASCII nama lebih besar
    while(strcmp(_nama, cursor->nama) > 0){
        cursor = cursor->next;
    }

    newStudent->next = cursor;
    newStudent->prev = cursor->prev;
    cursor->prev->next = newStudent;
    cursor->prev = newStudent;
}

// Pop Mid By Name
void popMidByName(char _nama[]){

    // Kalo nama sama dengan yang di head
    if(strcmp(_nama, head->nama) == 0){
        popHead();
        return;
    }

    // Kalo nama sama dengan yang di tail
    if(strcmp(_nama, tail->nama) == 0){
        popTail();
        return;
    }

    // Taro cursor di head
    Student *cursor = head->next;

    while(strcmp(_nama, cursor->nama) != 0 && cursor->next != NULL){
        cursor = cursor->next;
    }

    // Kalo tidak ketemu nama
    if(cursor == tail){
        printf("\nTidak ketemu node\n");
        return;
    }

    // Kalo ketemu data
    cursor->prev->next = cursor->next;
    cursor->next->prev = cursor->prev;
    free(cursor);
}

// Print
void printDLL(){

    // Taro kursor
    Student *cursor = head;

    // Print nodenya dan majuin kursor
    while(cursor != NULL){

        if(cursor == tail){
            printf("(%s, %d)", cursor->nama, cursor->usia);
            break;
        }

        printf("(%s, %d) --> ", cursor->nama, cursor->usia);

        cursor = cursor->next;
    }

}


int main(){

    pushMidByName("Abyan", 20);
    pushMidByName("Daniel", 18);
    pushMidByName("Nathan", 19);
    pushMidByName("Zaidan", 18);

    pushMidByName("Matthew", 19);

    printDLL();

    popMidByName("Matt");

    return 0;
}