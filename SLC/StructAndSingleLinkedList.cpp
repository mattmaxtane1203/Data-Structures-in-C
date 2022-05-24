// Struct & Single Linked List //

// Struct
    // Kumpulan yang di bungkus
    // Dibuat diluar int main
    // Casing - camel casing or all capital

// Single Linked-List
    // Struct yang dapat menunjuk ke struct yang lain
// Other Types of Structs
    // Push
        // Push Head
        // Push Tail
        // Push Mid
    // Search


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct SUBJECT{
//     char subjectName[64];
//     int difficulty;
// };

struct STUDENT{
    char name[64];
    int age;
    double ipk;
    STUDENT* next;
    // SUBJECT currentlyTraining;
};

// Global Variables
STUDENT* head = NULL;
STUDENT* tail = NULL;

// Declare constructor
STUDENT* createStudent(char _name[], int _age, double _ipk){
    // Allocating memory to pointer
    STUDENT* newStudent = (STUDENT*)malloc(sizeof(STUDENT));

    // newStudent->name;
    strcpy(newStudent->name, _name);
    newStudent->age = _age;
    newStudent->ipk = _ipk;

    newStudent->next = NULL;

    return newStudent;
}

// Push Head
void pushHead(STUDENT* newStudent){
    // 1. Kalau head == NULL
    if(head == NULL){
        head = newStudent;
        tail = newStudent;
    }
    // 2. kalau head != NULL
    else{
        newStudent->next = head;
        head = newStudent;

    }
}

// Push Tail
void pushTail(STUDENT* newStudent){
    if(head == NULL){
        tail->next = newStudent;
        tail = newStudent;
    }
    else{
        tail->next = newStudent;
        tail = newStudent;
    }
}

// Pop Head
void popHead(){
    if(head == NULL){ // 1. If head / tails == NULL
        printf("No data\n");
    } else if(head == tail){ // 2. If head == tail 
        free(head); // Opposite of malloc
        head = NULL;
        tail = NULL;
    } else{ // 3. Else more than 1 data
        STUDENT* toBeDeleted = head;
        head = head->next;
        free(toBeDeleted);
    }
}

// Pop Tail
void popTail(){
    if(head == NULL || head == tail){
        popHead();
    } else{ // 3. Else (more than 1 data)
        STUDENT* toBeDeleted = head;

        while(toBeDeleted->next != tail){
            toBeDeleted = toBeDeleted->next;
        }

        tail = toBeDeleted;
        free(tail->next);
        tail->next = NULL;
    }
}

// Push Mid
void pushMid(STUDENT* newStudent){
    // 1. if there is no data
    // 2. if there is data
    if(head == NULL){ // no data
        head = newStudent;
        tail = newStudent;
    } else{ // if there is data
        if(newStudent->age <= head->age){
            pushHead(newStudent);
        } else if(newStudent->age >= tail->age){
            pushTail(newStudent);
        } else{
            STUDENT* cursor = head;
            
            while(newStudent->age > cursor->next->age){
                cursor = cursor->next;
            }
            
            newStudent.next = cursor->next;
            cursor->next = newStudent;
        }
    }
}

// Pop Mid
void popMidByName(char _name[]){
    if(head == NULL){ // If there is no data
        printf("No Data\n");
    } else{ // If there is data
        if(strcmp(_name, head->name) == 0){
            popHead();
        } else if(strcmp(_name, tail->name) == 0){
            popTail;
        } else{
            STUDENT* cursor = head;

            while(cursor->next != NULL && strcmp(_name, cursor->next->name) != 0){
                cursor = cursor->next;
            }

            // 1. data tidak ketemu
            if(cursor->next == NULL){
                printf("Data not found!\n");
            
            } else{
                STUDENT* toBeDeleted = cursor->next;
                cursor->next = toBeDeleted->next;
                free(toBeDeleted);
            }
        }
    }
}

void printSLL(){
    STUDENT* cursor = head;

    while(cursor != NULL){
        printf("Name: %s\n", cursor->name);
        printf("Age : %d\n", cursor->name);
        printf("IPK : %.2lf\n", cursor->ipk);
        printf("\n");

        cursor = cursor->next;
    }
}

#include <stdio.h>

int main(){
    // // Initialize struct
    // STUDENT abraham, benny;

    // // Manipulate struct
    // strcpy(abraham.name, "Abraham");
    // abraham.age = 18;
    // abraham.ipk = 3.7;

    // strcpy(benny.name, "Benny");
    // benny.age = 21;
    // benny.ipk = 4.0;

    // abraham.next = &benny;

    // // Printing using struct
    // printf("Name: %s\n", abraham.name);
    // printf("Age : %d\n", abraham.age);
    // printf("IPK : %.2lf\n", abraham.ipk);

    // printf("Name: %s\n", (*(abraham.next)).name);
    // printf("Age : %d\n", (*(abraham.next)).age);
    // printf("IPK : %.2lf\n", (*(abraham.next)).ipk);

    // STUDENT* abraham = createStudent("Abraham", 18, 3.7);
    // printf("%s", abraham->name);

    pushTail(createStudent("Abraham", 18, 3.7));
    pushTail(createStudent("Benny", 18, 4.0));
    pushTail(createStudent("Charlie", 20, 3.7));


    // popHead();
    // popHead();

    // popTail();
    // popTail();

    printSLL();
    return 0;
}