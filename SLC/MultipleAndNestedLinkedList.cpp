#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[255];
	int age;
	Student *next, *prev;
};

struct Classroom{
	char name[255];
	Student *head = NULL, *tail = NULL;
	Classroom *north, *east, *south, *west;
	
	Student *createStudent(char name[], int age){
	
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
	
	void pushHead(char name[], int age){
	
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
	        head->prev = newStudent;
	        head = newStudent;
	    }
	}

	void pushMid(char name[],int age){
	//kalau head==tail
	//< head -> pushHead
	//>= tail -> pushTail
	
	
		if(head==NULL||strcmp(name,head->name)<0){
			pushHead(name,age);
		}	else if(strcmp(name,tail->name) >=0 ){
			pushTail(name,age);
		}
		else{
			Student *point = head;
			while(strcmp(name,point->next->name)>=0){
				point = point->next;
			}
			Student *newStudent = createStudent(name,age);
			newStudent->next=point->next;
			point->next->prev=newStudent;
			
			point->next=newStudent;
			newStudent->prev= point;
		}
		
	}

	void pushTail(char name[], int age){

		// Create new student
		Student *newStudent = createStudent(name, age);

		// 1. If no data
		if(head == NULL){
			head = newStudent;
			tail = newStudent;
		} else if(head == tail){
			// 2. If there is only one data
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
	
	void describe(){

		// "This" is the Classroom being referenced
		printf("Class Name: %s\n", this->name);
		printf("North : %s\n", (this->north != NULL) ? this->north->name : "-");
		printf("East : %s\n", (this->east != NULL) ? this->east->name : "-");
		printf("West : %s\n", (this->west != NULL) ? this->west->name : "-");
		printf("South : %s\n", (this->south != NULL) ? this->south->name : "-");
		Student *cursor = this->head;
		
		puts("\tStudents:");
		while(cursor != NULL){
			printf("\t%s (%d)\n", cursor->name, cursor->age);
			cursor = cursor->next;
		}
	}
};

Classroom *createClassroom(char name[]){
	
	// Allocate memory
	Classroom *classroom = (Classroom*)malloc(sizeof(Classroom));
	
	// Store variables
	strcpy(classroom->name, name);
	
	// Set pointers
	classroom->head = classroom->tail = NULL;
	
	// Set direction pointers
	classroom->north = classroom->east = classroom->west = classroom->south = NULL;
	
	return classroom;
}

void placeClassroom(Classroom *newClass, Classroom *mark, char way[]){

	if(strcasecmp(way, "north") == 0){

		// If towards the direction of the reference point is empty
		if(mark->north == NULL){
			mark->north = newClass;
			newClass->south = mark;
		} else{
			printf("Class already exists there.\n");
		}
	} else if(strcasecmp(way, "east") == 0){
		if(mark->east == NULL){
			mark->east = newClass;
			newClass->west = mark;
		} else{
			printf("Class already exists there.\n");
		}
	} else if(strcasecmp(way, "south") == 0){
		if(mark->south == NULL){
			mark->south = newClass;
			newClass->north = mark;
		} else{
			printf("Class already exists there.\n");
		}
	} else if(strcasecmp(way, "west") == 0){
		if(mark->west == NULL){
			mark->west = newClass;
			newClass->east = mark;
		} else{
			printf("Class already exists there.\n");
		}
	}
}

void unlinkClass(Classroom *classroom){

	if(classroom->north != NULL){
		classroom->north->south = NULL;
		classroom->north = NULL;
	} 
	
	if(classroom->east != NULL){
		classroom->east->west = NULL;
		classroom->east = NULL;
	}

	if(classroom->south != NULL){
		classroom->south->north = NULL;
		classroom->south = NULL;
	}

	if(classroom->west != NULL){
		classroom->west->east = NULL;
		classroom->west = NULL;
	}

	free(classroom);
	classroom = NULL;
}

int main(){
	
	Classroom *c1 = createClassroom("601");
	c1->pushHead("Budiman", 19);
	c1->pushHead("Nyoman", 20);
	// c1->describe();
	// printf("\n");

	Classroom *c2 = createClassroom("602");
	c2->pushHead("Jason", 19);
	c2->pushHead("Anthony", 20);
	// c2->describe();
	// printf("\n");

	Classroom *c3 = createClassroom("603");
	c3->pushHead("Nicholas", 19);
	c3->pushHead("Calvin", 20);
	// c3->describe();
	// printf("\n");

	Classroom *c4 = createClassroom("604");
	c4->pushHead("Jerry", 19);
	c4->pushHead("Matthew", 20);
	// c4->describe();
	// printf("\n");

	Classroom *c5 = createClassroom("605");
	c5->pushHead("Justine", 19);
	c5->pushHead("Yuda", 20);
	// c5->describe();
	// printf("\n");

	Classroom *c6 = createClassroom("606");
	c6->pushHead("Bono", 19);
	c6->pushHead("Bibi", 20);
	// c6->describe();
	// printf("\n");

	Classroom *c7 = createClassroom("607");
	c7->pushHead("Gabriel", 19);
	c7->pushHead("Peter", 20);
	// c7->describe();
	// printf("\n");

	Classroom *c8 = createClassroom("608");
	c8->pushHead("Gratia", 19);
	c8->pushHead("Mason", 20);
	// c8->describe();
	// printf("\n");

	// North
	placeClassroom(c2, c1, "north");
	placeClassroom(c3, c2, "north");
	placeClassroom(c5, c4, "north");
	placeClassroom(c8, c7, "north");

	// East
	placeClassroom(c6, c3, "east");
	placeClassroom(c5, c2, "east");
	placeClassroom(c4, c1, "east");
	placeClassroom(c8, c5, "east");
	placeClassroom(c7, c4, "east");

	// West
	placeClassroom(c3, c6, "west");
	placeClassroom(c2, c5, "west");
	placeClassroom(c1, c4, "west");
	placeClassroom(c5, c8, "west");
	placeClassroom(c4, c7, "west");

	// South
	placeClassroom(c2, c3, "south");
	placeClassroom(c1, c2, "south");
	placeClassroom(c5, c6, "south");
	placeClassroom(c4, c5, "south");
	placeClassroom(c7, c8, "south");

	// unlinkClass(c5);

	Classroom *curr = c1;
	Classroom *target;
	int choose = 0;
	do{

		system("cls");
		curr->describe();

		puts("1. North");
		puts("2. East");
		puts("3. South");
		puts("4. West");
		puts("5. Exit");
		printf(">> ");
		scanf("%d", &choose);
		getchar();

		if(choose == 1){
			target = curr->north;
		} else if(choose == 2){
			target = curr->east;
		} else if(choose ==3){
			target = curr->south;
		} else if(choose == 4){
			target = curr->west;
		}

		if(choose >= 1 && choose <= 4){
			if(target == NULL){
				printf("No Classroom There!");
				getchar();
			} else{
				curr = target;
			}
		}
	} while(choose != 5);

	// c1->describe();
	// c2->describe();
	// c3->describe();
	// c4->describe();
	// c5->describe();
	// c6->describe();
	// c7->describe();
	// c8->describe();

}
