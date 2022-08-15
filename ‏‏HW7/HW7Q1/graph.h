#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH.H
#define VERTEX 7
#define EDGES 7
#define GROUP_M 3
#define N 7

int isMainGroup(int Graph[VERTEX][EDGES], int graph_N, int Group[], int group_M);
int contains(int NumCheck, int Group[], int lenGroup);
int isEdge(int Graph[N][N], int Group[],int group_M ,int p);
#endif