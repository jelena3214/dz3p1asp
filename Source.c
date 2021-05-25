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

void printGraph(struct graph* graph)
{
	for (int i = 0; i < graph->numofNodes; i++) {
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

int main() {
	int graphSize;
	scanf("%d", &graphSize);
	
	struct graph* tryit = createGraph(graphSize);
	addBranch(tryit, 1, 2);
	addBranch(tryit, 2, 3);
	addBranch(tryit, 3, 5);
	addBranch(tryit, 4, 2);
	addBranch(tryit, 4, 3);
	addBranch(tryit, 4, 5);
	addBranch(tryit, 5, 6);

	printGraph(tryit);
	 

	
	return 0;
}