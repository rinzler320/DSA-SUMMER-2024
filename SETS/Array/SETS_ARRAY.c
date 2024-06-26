#include <stdio.h>
#include <stdlib.h>
#include "SETS_ARRAY.h"

void initializeSet(SET set) {
    int i;
    for (i = 0; i < MAX; i++) {
        set[i] = 0;
    }
}

// Function to add an element to the set
void addToSet(SET set, int element) {
    if (element >= 0 && element < MAX) {
        set[element] = 1;
    }
}

// Function to delete an element from the set
void deleteFromSet(SET set, int element) {
    if (element >= 0 && element < MAX) {
        set[element] = 0;
    }
}

// Function to display elements of the set
void displaySet(SET set) {
    int i;
    printf("{ ");
    for (i = 0; i < MAX; i++) {
        if (set[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}");
}

// Function to find the union of two sets
void findUnion(SET set1, SET set2, SET unionSet) {
    int i;
    initializeSet(unionSet);

    for (i = 0; i < MAX; i++) {
        if (set1[i] == 1 || set2[i] == 1) {
            unionSet[i] = 1;
        }
    }
}

// Function to find the intersection of two sets
void findIntersection(SET set1, SET set2, SET intersectionSet) {
    int i;
    initializeSet(intersectionSet);

    for (i = 0; i < MAX; i++) {
        if (set1[i] == 1 && set2[i] == 1) {
            intersectionSet[i] = 1;
        }
    }
}

