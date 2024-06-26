#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studCount;
}classRecord;

void insertFront(classRecord *CR, studentInfo student);
void insertRear(classRecord *CR, studentInfo student);
bool insertAtIndex(classRecord *CR, studentInfo student, int index);
void insertSortedByAge(classRecord *CR, studentInfo student);
bool deleteFront(classRecord *CR);
bool deleteAtIndex(classRecord *CR,  int index);
bool deleteRear(classRecord *CR);
void printClassRecord(classRecord *CR);
studentInfo getStudentInfo();

int main() {
    classRecord CR;
    CR.studCount=0;
    
    int choice;
    studentInfo student;
    int index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert Sorted by Age\n");
        printf("4. Insert at Index\n");
        printf("5. Delete from Front\n");
        printf("6. Delete from Rear\n");
        printf("7. Delete from Index\n");
        printf("8. Print Class Record\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                student = getStudentInfo();
                insertFront(&CR, student);
                break;
            case 2:
                student = getStudentInfo();
                insertRear(&CR, student);
                break;
            case 3:
                student = getStudentInfo();
                insertSortedByAge(&CR, student);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                student = getStudentInfo();
                if (!insertAtIndex(&CR, student, index)) {
                    printf("Insertion at index %d failed.\n", index);
                }
                break;
            case 5:
                if (!deleteFront(&CR)) {
                    printf("Deletion from front failed.\n");
                }
                break;
            case 6:
                if (!deleteRear(&CR)) {
                    printf("Deletion from rear failed.\n");
                }
                break;
            case 7:
                printf("Enter index: ");
                scanf("%d", &index);
                if (!deleteAtIndex(&CR, index)) {
                    printf("Deletion from index %d failed.\n", index);
                }
                break;
            case 8:
                printClassRecord(&CR);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void insertFront(classRecord *CR, studentInfo student){
	if (CR->studCount>=20){
		printf("Class record is full!\n");
		return;
	}
	int i;
	for (i = CR->studCount; i>0;i--){
		CR->studList[i]=CR->studList[i-1];
	}
	
	CR->studList[0]=student;
	CR->studCount++;
}

void insertRear(classRecord *CR, studentInfo student){
	if (CR->studCount>=20){
		printf("Class record is full!\n");
		return;
	}
	
	CR->studList[CR->studCount]=student;
	CR->studCount++;
}

bool insertAtIndex(classRecord *CR, studentInfo student, int index){
	if (CR->studCount>=20){
		printf("Class record is full!\n");
		return false;
	}
	if(index<0 || index>CR->studCount){
		printf("Invalid Index!\n");
		return false;
	}
	int i;
	for(i=CR->studCount; i>index;i--){
		CR->studList[i]=CR->studList[i-1];
	}
	
	CR->studList[index]=student;
	CR->studCount++;
	return true;
}

void insertSortedByAge(classRecord *CR, studentInfo student){
	if (CR->studCount>=20){
		printf("Class record is full!\n");
		return;
	}
	
	int i;
	for(i=CR->studCount; i>0 && CR->studList[i-1].age>student.age; i--){
		CR->studList[i]=CR->studList[i-1];	
	}
	
	CR->studList[i]=student;
	CR->studCount++;
}

bool deleteFront(classRecord *CR){
	if(CR->studCount<=0){
		printf("Class record is empty\n");
		return false;
	}
	
	int i;
	for(i=0;i<CR->studCount-1;i++){
		CR->studList[i]=CR->studList[i+1];
	}
	
	CR->studCount--;
	return true;
}

bool deleteAtIndex(classRecord *CR,  int index){
	if(CR->studCount<=0){
		printf("Class record is empty!\n");
		return false;
	}
	
	if(index<0 || index>CR->studCount){
		printf("Invalid Index!\n");
		return false;
	}
	int i;
	for(i=index; i>CR->studCount-1;i++){
		CR->studList[i]=CR->studList[i+1];
	}
	
	CR->studCount--;
	return true;
}

bool deleteRear(classRecord *CR){
	if(CR->studCount<=0){
		printf("Class record is empty!\n");
		return false;
	}
	
	CR->studCount--;
	return true;
}

void printClassRecord(classRecord *CR){
	int i;
	for(i=0;i<CR->studCount;i++){
		printf("Student %d: %s %s \nAge: %d\nID: %d\n", i+1, CR->studList[i].name.fName, 
		CR->studList[i].name.lName, CR->studList[i].age, CR->studList[i].idNum);
	}
}

studentInfo getStudentInfo(){
    studentInfo student;
    printf("Enter first name: ");
    scanf("%s", student.name.fName);
    printf("Enter last name: ");
    scanf("%s", student.name.lName);
    printf("Enter birth month: ");
    scanf("%d", &student.birthdate.month);
    printf("Enter birth year: ");
    scanf("%d", &student.birthdate.year);
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter ID number: ");
    scanf("%d", &student.idNum);
    return student;
}

