#include <stdio.h>
#include <stdlib.h>
#include "SETS_ARRAY.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET set1, set2, unionSet, intersectionSet;
    int choice, element;
    int addMoreElements;

    initializeSet(set1);
    initializeSet(set2);

    // Adding initial elements to set1
    addToSet(set1, 1);
    addToSet(set1, 2);
    addToSet(set1, 3);
    addToSet(set1, 4);

    // Adding initial elements to set2
    addToSet(set2, 3);
    addToSet(set2, 4);
    addToSet(set2, 5);
    addToSet(set2, 6);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add element to set\n");
        printf("2. Delete element from set\n");
        printf("3. Display sets\n");
        printf("4. Compute union\n");
        printf("5. Compute intersection\n");
        printf("6. Exit\n");
        printf("7. Add multiple elements to sets\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addToSet(set1, element);
                addToSet(set2, element);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                deleteFromSet(set1, element);
                deleteFromSet(set2, element);
                break;
            case 3:
                printf("Set 1: ");
                displaySet(set1);
                printf("\n");
                printf("Set 2: ");
                displaySet(set2);
                printf("\n");
                break;
            case 4:
                findUnion(set1, set2, unionSet);
                printf("Union of Set 1 and Set 2: ");
                displaySet(unionSet);
                printf("\n");
                break;
            case 5:
                findIntersection(set1, set2, intersectionSet);
                printf("Intersection of Set 1 and Set 2: ");
                displaySet(intersectionSet);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            case 7:
                do {
                    printf("Enter element to add (negative to stop): ");
                    scanf("%d", &element);
                    if (element >= 0) {
                        addToSet(set1, element);
                        addToSet(set2, element);
                    }
                } while (element >= 0);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 6);

    return 0;
}
