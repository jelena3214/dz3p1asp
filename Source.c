#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int info;
	struct node* next;
}NODE;

struct node* createNode(int info) {
	struct node* newnode = malloc(sizeof(struct node));
	newnode->info = info;
	newnode->next = NULL;
	return newnode;
}

struct linkedList {
	struct node* head;
}LINKEDLIST;

struct graph {
	int numofNodes;
	struct linkedList* adjList;
}GRAPH;

struct graph* createGraph(int size) {
	struct graph* mainGraph = (struct graph*)malloc(sizeof(struct graph));
	mainGraph->numofNodes = size;
	mainGraph->adjList = (struct linkedList*)malloc(size * sizeof(struct linkedList)); //lista ulancanih listi

	for (int i = 0; i < size; i++) {
		mainGraph->adjList[i].head = NULL; //sve liste na pocetku su prazne
	}
	return mainGraph;
}

void printGraph(struct graph* graph, int *arrBool)
{
	for (int i = 0; i < graph->numofNodes; i++) {
		if (arrBool[i] == 1)continue;
		struct node* p = graph->adjList[i].head;
		printf("cvor br = %d\n", i);
		while (p != NULL) {
			printf("-> %d", p->info);
			p = p->next;
		}
		putchar('\n');
	}
}

void addBranch(struct graph* mainGraph, int from, int to) {
	struct node* newnode = createNode(to);
	newnode->next = mainGraph->adjList[from].head;
	mainGraph->adjList[from].head = newnode;
}
//sortiranje lista?

void freeGraphNode(struct node* remove) {
	free(remove);
}

void removeNode(struct graph* maing, struct node** remove, int f) {
	struct node* p = maing->adjList[f].head;
	struct node* n = (*remove)->next;
	if (maing->adjList[f].head == NULL)return NULL;
	if (((*remove)->next) == NULL && (*remove) == maing->adjList[f].head) {
		maing->adjList[f].head = NULL;
		freeGraphNode((*remove));
		(*remove) = NULL;
		return maing->adjList[f].head;
	}
	while (p->next != (*remove)) {
		p = p->next;
	}

	p->next = n;
	if (maing->adjList[f].head == (*remove)) {
		maing->adjList[f].head = n;
	}
	freeGraphNode((*remove));
	(*remove) = n;
	return maing->adjList[f].head;
}

void addGraphNode(struct graph* maingraph, int *arr) {
	int n = maingraph->numofNodes;
	maingraph->adjList = realloc(maingraph->adjList, sizeof(struct linkedList) * (n + 1));
	maingraph->numofNodes = n + 1;
	maingraph->adjList[n].head = NULL;
	arr = realloc(arr, sizeof(int) * (n + 1));
	arr[n] = 0;
}

struct graph* removeGraphNode(struct graph* mainGraph,int *arrBool, int remove, int info) {
	struct node* curr = mainGraph->adjList[remove].head;
	while (curr->info != info) {
		if (curr->next == NULL)return mainGraph;
		curr = curr->next;
	}
	removeNode(mainGraph, &curr, remove);
	arrBool[remove] = 1;
	return mainGraph;
}

int main() {
	int graphSize;
	scanf("%d", &graphSize);
	int* inGraph = calloc(graphSize, sizeof(int));
	struct graph* tryit = createGraph(graphSize);
	//printGraph(tryit);
	addBranch(tryit, 1, 2);
	addBranch(tryit, 2, 3);
	addBranch(tryit, 3, 5);
	addBranch(tryit, 4, 2);
	addBranch(tryit, 4, 3);
	addBranch(tryit, 4, 5);
	addBranch(tryit, 5, 2);
	removeGraphNode(tryit, inGraph, 3, 5);
	addGraphNode(tryit, inGraph);
	addBranch(tryit, 6, 5);
	
	addGraphNode(tryit, inGraph);
	removeGraphNode(tryit, inGraph, 6, 5);
	printGraph(tryit, inGraph);
	return 0;
}