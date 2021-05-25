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

struct node* createLinkedList() {
	struct node* head = malloc(sizeof(struct node));

}

struct graph {
	int* nodes;
	int* branches;
}GRAPH;

struct graphNode {
	int info;
	int* branches;
}GRAPHNODE;


int** initNodes(int **nodes, int size) {
	nodes = realloc(nodes, sizeof(int*) * size);
	return nodes;
}

int main() {
	int graphSize;
	scanf("%d", &graphSize);
	int** nodes = NULL;

	struct graph *mainGraph = (struct graph*)malloc(sizeof(struct graph));
	initNodes(nodes, graphSize);
	mainGraph->nodes = nodes;
	mainGraph->branches = NULL;


	
	return 0;
}