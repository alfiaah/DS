#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

typedef struct node AdjNode;

AdjNode* createNode(int);

struct Graph {
  int numVertices;
  AdjNode** adjLists;
};

typedef struct Graph Graph;

AdjNode* createNode(int v) 
{
  AdjNode* newNode = malloc(sizeof(AdjNode));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

Graph* createAGraph(int vertices) {
  Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(AdjNode*));
  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;
  return graph;
}

void addEdge(Graph* graph, int s, int d) {
  AdjNode* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createAGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);
  printf("\n Adjancency List\n-------------------\n");
  printGraph(graph);

  return 0;
}

