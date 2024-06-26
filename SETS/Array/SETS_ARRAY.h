#ifndef SETS_ARRAY
#define SETS_ARRAY
#define MAX 20

//Create a program to find the union and intersection
//2 functions that accepts 2 sets and find union & intersection
//functions to add or delete values in the set
//keep the integrity of the 2 initial sets when finding union & intersection
//display resulting unions & intersections
//array implementation

typedef int SET[MAX];

void initializeSet(SET set);
void addToSet(SET set, int element);
void deleteFromSet(SET set, int element);
void displaySet(SET set);
void findUnion(SET set1, SET set2, SET unionSet);
void findIntersection(SET set1, SET set2, SET intersectionSet);


#endif


