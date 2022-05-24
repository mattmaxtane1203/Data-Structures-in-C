#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tableSize 1007
int amountOfBooks = 0;

// Book data structure
struct Book{

    char title[51];
    char author[26];
    char ISBN[14];
    int pageNumber;
    char bookID[101];

    Book *next;

} *head[tableSize] = {NULL}, *tail[tableSize] = {NULL};

// Book ID first sets
char bookIDOnes[6] = "B0000";
char bookIDTens[5] = "B000";
char bookIDHundreds[4] = "B00";
char bookIDThousands[3] = "B0";
char bookIDTenThousands[2] = "B";

// Function List
void mainMenu();

// Hash Table Functions
Book *createBook(char _title[], char _author[], char _ISBN[], int _pageNumber, char _bookID[]){

    // Allocate memory
    Book *newBook = (Book*)malloc(sizeof(Book));

    // Store all information
    strcpy(newBook->title, _title);
    strcpy(newBook->author, _author);
    strcpy(newBook->ISBN, _ISBN);
    strcpy(newBook->bookID, _bookID);
    newBook->pageNumber = _pageNumber;

    // Set pointers
    newBook->next = NULL;

    return newBook;
}

int hash(char _bookID[]){

    int hashNumber = 0;
    for(int charIndex = 0; charIndex < strlen(_bookID); charIndex++){
        hashNumber = hashNumber + _bookID[charIndex];
    }

    return hashNumber % tableSize;
}

void insert(Book *book){

    int index = hash(book->bookID);

    if(head[index] == NULL){
        head[index] = tail[index] = book;
    }

    tail[index]->next = book;
    tail[index] = book;
}

void printHashTable(){

    for(int index = 0; index < tableSize; index++){

        // Place cursor on head
        Book *cursor = head[index];

        // Move cursor
        while(cursor != NULL){
            
            printf("%s %s %s %s %d\n", cursor->bookID, cursor->title, cursor->author, cursor->ISBN, cursor->pageNumber);
            cursor = cursor->next;
        }
    }
}

// Utility functions
void cls(){
    system("cls");
}

void promptEnterKey(){
    printf("Press Enter to continue ...");
    getchar();
}

bool checkBookTitleIsUnique(char bookTitle[]){

    // Search every index
    for(int index = 0; index < tableSize; index++){

        // Check book title at head first
        if(strcmp(head[index]->title, bookTitle) == 0){
            return false;
        }

        // Else, place cursor in head
        Book *cursor = head[index];

        // Move cursor forward while book title is not the same and cursor is not NULL
        while(cursor != NULL && strcmp(bookTitle, cursor->title) != 0){
            cursor = cursor->next;
        }

        // Check if it stopped at NULL or the same book title
        if(cursor != NULL){
            return false;
        }
    }

    return true;
}

bool checkAuthorHasTitle(char authorName[]){

    // Initialize string
    char validation[5];

    for(int charIndex = 0; charIndex < 3; charIndex++){
        validation[charIndex] = authorName[charIndex];
    }

    // Test print title
    printf("%s\n", validation);

    // Check for "Mr."
    if(strcmp(validation, "Mr.") == 0){
        return true;
    }

    // If not Mr, check for Mrs.
    strncat(validation, &authorName[3], 1);
    if(strcmp(validation, "Mrs.") == 0){
        return true;
    }

    return false;
}

bool checkISBNisNumeric(char ISBN[]){

    for(int charIndex = 0; charIndex < strlen(ISBN); charIndex++){

        if(ISBN[charIndex] < 48 || ISBN[charIndex] > 57){
            return false;
        }
    }

    return true;
}

// Menu Functions

void viewBook(){

    // Clear screen
    cls();

    printHashTable();

    promptEnterKey();
    mainMenu();
}

void insertBook(){

    // Clear screen
    cls();

    // Input book title
    char tempBookTitle[51] = "";
    bool bookTitleIsUnique = false;
    do{
        
        printf("Input book title[5-50][unique]: ");
        scanf(" %[^\n]", &tempBookTitle);

        // Validate book title uniqueness by creating search function
        bookTitleIsUnique = checkBookTitleIsUnique(tempBookTitle);

    } while(bookTitleIsUnique == false || (strlen(tempBookTitle) < 5 || strlen(tempBookTitle) > 50));

    // Input author name
    char tempAuthor[26] = "";
    bool authorHasTitle = false;
    do{
        
        printf("Input author name[3-25][Mr. | Mrs. ]: ");
        scanf(" %[^\n]", &tempAuthor);

        // Validate if author has title
        authorHasTitle = checkAuthorHasTitle(tempAuthor);
        
    } while(authorHasTitle == false || (strlen(tempAuthor) < 3 || strlen(tempAuthor) > 25));

    // Input ISBN
    char tempISBN[14];
    bool ISBNisNumeric = false;
    do{
        
        printf("Input ISBN[10-13][numeric]: ");
        scanf(" %[^\n]", &tempISBN);

        // Check if ISBN is all numeric
        ISBNisNumeric = checkISBNisNumeric(tempISBN);

    } while(ISBNisNumeric == false || (strlen(tempISBN) < 10 || strlen(tempISBN) > 13));

    // Input page number
    int tempPageNumber = 0;
    do{

        printf("Input page number[>= 16]: ");
        scanf("%d", &tempPageNumber);
        getchar();

    } while(tempPageNumber < 16);

    // Generate book ID
    char tempBookID[101];
    char bookNum[6];
    char dash[2] = "-";
    
    // Increment amount of books
    amountOfBooks++;

    // Decide zeros behind the book number
    if(amountOfBooks < 10){
        strcpy(tempBookID, bookIDOnes);
    } else if(amountOfBooks >= 10 && amountOfBooks < 100){
        strcpy(tempBookID, bookIDHundreds);
    } else if(amountOfBooks >= 100 && amountOfBooks < 1000){
        strcpy(tempBookID, bookIDThousands);
    } else{
        strcpy(tempBookID, bookIDTenThousands);
    }

    // printf("%s\n", tempBookID);

    // Append book number and append
    sprintf(bookNum, "%d", amountOfBooks);
    strcat(tempBookID, bookNum);
    strcat(tempBookID, dash);

    // printf("%s\n", tempBookID);
    
    // Append ISBN and dash
    strcat(tempBookID, tempISBN);
    strcat(tempBookID, dash);

    // printf("%s\n", tempBookID);

    // Find the first letter after the title of the author
    for(int charIndex = 0; charIndex < strlen(tempAuthor); charIndex++){

        // If letter comes after a space, append the letter
        if(charIndex >= 1 && tempAuthor[charIndex - 1] == ' '){
            strncat(tempBookID, &tempAuthor[charIndex], 1);
            break;
        }
    }

    // Append first letter of book title
    strncat(tempBookID, &tempBookTitle[0], 1);

    // printf("%s\n", tempBookID);

    // Insert to hash table
    Book *newBook = createBook(tempBookTitle, tempAuthor, tempISBN, tempPageNumber, tempBookID);
    insert(newBook);

    // Print success message
    printf("\nInsert success !");
    getchar();
    mainMenu();
}

void removeBook(){

    // Clear screen
    cls();

}

void mainMenu(){

    // Clear screen
    cls();

    // Print main menu
    printf("Bluejack Library\n=================\n1. View Book\n2. Insert Book\n3. Remove Book\n4. Exit\n");

    // Input choice
    int choice = 0;
    do{

        printf(">> ");
        scanf("%d", &choice);
    } while(choice < 1);

    // Switch choice
    switch(choice){

        case 1:
            viewBook();
            break;
        case 2:
            insertBook();
            break;
        case 3:
            removeBook();
            break;
        case 4:
            exit(0);
            break;
    }
}

// Driver code
int main(){

    // Call main menu page
    mainMenu();
    
    return 0;
}