#include "graph.h"
#include <stdio.h>

int main(){
    int graph[VERTEX][EDGES]= {{0,1,0,0,0,0,1},{1,0,1,1,0,1,0},{0,1,0,1,0,0,1},{0,1,1,0,1,0,0},{0,0,0,1,0,1,1},{0,1,0,0,1,0,1},{1,0,1,0,1,1,0}};
    int mainGroup[] = {0,3,5};
    int result;

    result = isMainGroup(graph, N, mainGroup, GROUP_M);
    if(result == 1){
        printf("\nIt is a main group!\n");
    }
    else {
        printf("\nIt isn't a main group!\n");
    }
    return 0;
}

/*Check if it is a main group*/
int isMainGroup(int Graph[VERTEX][EDGES], int graph_N, int Group[], int group_M){
    int i = 0;
    for(i = 0; i < graph_N ; i++){
        if(contains(i,Group,group_M)==0 && isEdge(Graph,Group,group_M,i) == 0){
            return 0;
        }
    }
    return 1;
}

/*Check the edges*/
int isEdge(int Graph[N][N], int Group[],int group_M ,int p) {
    int g, i = 0;
    for (i = 0; i < group_M; i++) {
        g = Group[i];
        if(Graph[p][g] == 1) {
            if(Graph[g][p] == 1){
            return 1;
            }
        }
    }
    return 0;
}

/*Check if it is in the main group*/
int contains(int num, int Group[], int len){
    int i = 0;
    for(i = 0; i < len; i++) {
        if (Group[i] == num) {
            return 1;
        }
    }
    return 0;
}