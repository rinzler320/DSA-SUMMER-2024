#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// Global variables
extern int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
extern int numVertices;
extern char vertexLabels[MAX_VERTICES];

// Function prototypes
void addVertex(void);
void removeVertex(int vertex);
void addEdge(int from, int to);
void removeEdge(int from, int to);
void displayInitialAdjacencyMatrix(void);
void displayAdjacencyMatrix(void);

#endif /* GRAPH_H */

