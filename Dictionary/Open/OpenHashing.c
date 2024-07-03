#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TABLE_SIZE 10

typedef struct Entry{
    char animal[50];
    char species[50];
    struct Entry* next;
}Entry;

Entry** hashTable;
int tableSize = INITIAL_TABLE_SIZE;
int numEntries = 0;

unsigned int hashFunction(char* str, int size) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % size;
}

void insertOpen(char* animal, char* species);

void resizeTableOpen(){
    int newSize = tableSize * 2;
    Entry** newTable = (Entry**)malloc(newSize * sizeof(Entry*));
    int i;
    for (i = 0; i < newSize; i++) {
        newTable[i] = NULL;
    }

    for (i = 0; i < tableSize; i++) {
        Entry* current = hashTable[i];
        while (current) {
            insertOpen(current->animal, current->species);
            Entry* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);
    hashTable = newTable;
    tableSize = newSize;
}

void insertOpen(char* animal, char* species){
    if ((float)numEntries / tableSize >= 1.0) {
        resizeTableOpen();
    }
    unsigned int index = hashFunction(animal, tableSize);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    strcpy(newEntry->animal, animal);
    strcpy(newEntry->species, species);
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
    numEntries++;
}

void printTableOpen(){
	int i;
    for (i = 0; i < tableSize; i++) {
        printf("Index %d: ", i);
        Entry* current = hashTable[i];
        while (current) {
            printf("(%s, %s) -> ", current->animal, current->species);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main(){
    char animal[50], species[50];
    int choice;
    hashTable = (Entry**)malloc(tableSize * sizeof(Entry*));
    int i;
    for (i = 0; i < tableSize; i++) {
        hashTable[i] = NULL;
    }
    while (1) {
        printf("1. Insert animal\n2. Print table\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter animal name: ");
            scanf("%s", animal);
            printf("Enter species: ");
            scanf("%s", species);
            insertOpen(animal, species);
        } else if (choice == 2) {
            printTableOpen();
        } else if (choice == 3) {
            break;
        }
    }
    free(hashTable);
    return 0;
}

