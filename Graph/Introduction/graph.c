#include "graph.h"

// Global variables
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {[0 ... MAX_VERTICES-1][0 ... MAX_VERTICES-1] = 0};
int numVertices = 0;
char vertexLabels[MAX_VERTICES] = {'A', 'B', 'C', 'D', 'E'};

// Function to add a new vertex
void addVertex(void) {
    if (numVertices < MAX_VERTICES) {
        numVertices++;
    } else {
        printf("Maximum number of vertices reached (%d)\n", MAX_VERTICES);
    }
}

// Function to remove a vertex
void removeVertex(int vertex) {
    if (vertex < 0 || vertex >= numVertices) {
        printf("Invalid vertex\n");
        return;
    }
	int i;
    // Remove edges incident to the vertex
    for (i = 0; i < numVertices; i++) {
        if (i != vertex) {
            adjacencyMatrix[i][vertex] = 0;
            adjacencyMatrix[vertex][i] = 0;
        }
    }

    // Shift vertices after the removed vertex
    for (i = vertex; i < numVertices - 1; i++) {
        // Shift rows
        int j;
        for (j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = adjacencyMatrix[i + 1][j];
        }
        // Shift columns
        for (j = 0; j < numVertices; j++) {
            adjacencyMatrix[j][i] = adjacencyMatrix[j][i + 1];
        }
        vertexLabels[i] = vertexLabels[i + 1];
    }

    numVertices--;
}

// Function to add a new edge between two vertices
void addEdge(int from, int to) {
    // Check valid vertices and avoid self-loop
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices && from != to) {
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1; // Since it's an undirected graph
    } else {
        printf("Invalid vertices or trying to add self-loop\n");
    }
}

// Function to remove an edge between two vertices
void removeEdge(int from, int to) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjacencyMatrix[from][to] = 0;
        adjacencyMatrix[to][from] = 0; // Since it's an undirected graph
    } else {
        printf("Invalid vertices\n");
    }
}

// Function to display the initial adjacency matrix (all values as 0)
void displayInitialAdjacencyMatrix(void) {
    // Variables for loops
    int i, j;

    // Print column labels (vertex labels)
    printf("  ");
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("%c ", vertexLabels[i]);
    }
    printf("\n");

    // Print rows with vertex labels and matrix values
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("%c ", vertexLabels[i]);
        for (j = 0; j < MAX_VERTICES; j++) {
            if (i == j) {
                printf("  "); // Print space for diagonal elements
            } else {
                printf("%d ", adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to display the adjacency matrix
void displayAdjacencyMatrix(void) {
    // Variables for loops
    int i, j;

    // Print column labels (vertex labels)
    printf("  ");
    for (i = 0; i < numVertices; i++) {
        printf("%c ", vertexLabels[i]);
    }
    printf("\n");

    // Print rows with vertex labels and matrix values
    for (i = 0; i < numVertices; i++) {
        printf("%c ", vertexLabels[i]);
        for (j = 0; j < numVertices; j++) {
            if (i == j) {
                printf("  "); // Print space for diagonal elements
            } else {
                printf("%d ", adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

