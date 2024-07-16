#include <stdio.h>
#include "graph.h"

int main(void) {
    // Display initial adjacency matrix with all values as 0
    printf("Initial Adjacency Matrix:\n");
    displayInitialAdjacencyMatrix();

    // Add vertices A, B, C, D, E
    addVertex(); // A
    addVertex(); // B
    addVertex(); // C
    addVertex(); // D
    addVertex(); // E

    // Add edges to the graph
    addEdge(0, 1); // A <-> B
    addEdge(0, 2); // A <-> C
    addEdge(0, 3); // A <-> D
    addEdge(1, 2); // B <-> C
    addEdge(1, 3); // B <-> D
    addEdge(1, 4); // B <-> E
    addEdge(2, 3); // C <-> D
    addEdge(3, 4); // D <-> E

    // Display the adjacency matrix
    printf("\nAdjacency Matrix after adding edges:\n");
    displayAdjacencyMatrix();

    // Remove vertex B and edge A<->D
    removeVertex(1); // Remove vertex B
    removeEdge(0, 3); // Remove edge A<->D

    // Display the updated adjacency matrix
    printf("\nAdjacency Matrix after removing vertex B and edge A<->D:\n");
    displayAdjacencyMatrix();

    return 0;
}

