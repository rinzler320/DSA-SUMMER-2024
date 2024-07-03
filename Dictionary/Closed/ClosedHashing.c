#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TABLE_SIZE 10
#define MAX_LOAD_FACTOR 0.65

typedef struct {
    char animal[50];
    char species[50];
    int isOccupied;
} ClosedEntry;

ClosedEntry* closedTable;
int tableSize = INITIAL_TABLE_SIZE;
int numEntries = 0;

unsigned int hashFunction(char* str, int size) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % size;
}

unsigned int linearProbing(unsigned int index, unsigned int i) {
    return (index + i) % tableSize;
}

unsigned int quadraticProbing(unsigned int index, unsigned int i) {
    return (index + i * i) % tableSize;
}

unsigned int doubleHashing(unsigned int index, unsigned int i) {
    unsigned int hash2 = 7 - (index % 7);
    return (index + i * hash2) % tableSize;
}

void insertClosed(char* animal, char* species, unsigned int (*probingFunc)(unsigned int, unsigned int));

void resizeTableClosed(unsigned int (*probingFunc)(unsigned int, unsigned int)) {
    int newSize = tableSize * 2;
    ClosedEntry* newTable = (ClosedEntry*)malloc(newSize * sizeof(ClosedEntry));
    int i;
    for (i = 0; i < newSize; i++) {
        newTable[i].isOccupied = 0;
    }

    ClosedEntry* oldTable = closedTable;
    int oldSize = tableSize;

    closedTable = newTable;
    tableSize = newSize;
    numEntries = 0;

    for (i = 0; i < oldSize; i++) {
        if (oldTable[i].isOccupied) {
            insertClosed(oldTable[i].animal, oldTable[i].species, probingFunc);
        }
    }
    free(oldTable);
}

void insertClosed(char* animal, char* species, unsigned int (*probingFunc)(unsigned int, unsigned int)) {
    if ((float)numEntries / tableSize >= MAX_LOAD_FACTOR) {
        resizeTableClosed(probingFunc);
    }
    unsigned int index = hashFunction(animal, tableSize);
    unsigned int i = 0;
    while (closedTable[probingFunc(index, i)].isOccupied) {
        i++;
    }
    unsigned int newIndex = probingFunc(index, i);
    strcpy(closedTable[newIndex].animal, animal);
    strcpy(closedTable[newIndex].species, species);
    closedTable[newIndex].isOccupied = 1;
    numEntries++;
}

void printTableClosed() {
	int i;
    for (i = 0; i < tableSize; i++) {
        if (closedTable[i].isOccupied) {
            printf("Index %d: (%s, %s)\n", i, closedTable[i].animal, closedTable[i].species);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

int main() {
    char animal[50], species[50];
    int choice, probingChoice;
    closedTable = (ClosedEntry*)malloc(tableSize * sizeof(ClosedEntry));
    int i;
    for (i = 0; i < tableSize; i++) {
        closedTable[i].isOccupied = 0;
    }
    while (1) {
        printf("1. Insert animal\n2. Print table\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter animal name: ");
            scanf("%s", animal);
            printf("Enter species: ");
            scanf("%s", species);
            printf("Choose probing method: 1. Linear 2. Quadratic 3. Double hashing\nChoice: ");
            scanf("%d", &probingChoice);
            if (probingChoice == 1) {
                insertClosed(animal, species, linearProbing);
            } else if (probingChoice == 2) {
                insertClosed(animal, species, quadraticProbing);
            } else if (probingChoice == 3) {
                insertClosed(animal, species, doubleHashing);
            } else {
                printf("Invalid choice!\n");
            }
        } else if (choice == 2) {
            printTableClosed();
        } else if (choice == 3) {
            break;
        }
    }
    free(closedTable);
    return 0;
}

