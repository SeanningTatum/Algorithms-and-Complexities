//
//  main.c
//  Prims MST
//
//  Created by Sean Stuart C Urgel on 17/MAX3/2017.
//  Copyright © 2017 Sean Stuart C Urgel. All rights reserved.
//

#define V 5
#define MAX 9999

#include <stdio.h>

typedef enum{TRUE,FALSE}boolean;

void primsMST(int graph[V][V], int src);
void printMST(int parent[], int n, int graph[V][V]);

int main(void){
    int graph[V][V] = {{
         MAX, 2, MAX, 6, MAX},
        {2, MAX, 3, 8, 5},
        {MAX, 3, MAX, MAX, 7},
        {6, 8, MAX, MAX, 9},
        {MAX, 5, 7, 9, MAX},
    };
    
    primsMST(graph, 0);
    

    
    return 0;
}

void primsMST(int graph[V][V], int src)
{
    boolean sptSet[V];
    int parent[V];
    int key[V];
    int min, min_index;
    
    for(int i = 0; i < V; i++){
        key[i] = FALSE;
        parent[i] = MAX;
    }
    
    key[src] = 0;
    parent[src] = -1;
    
    for(int count = 0; count < V-1; count++){
        min = MAX;
        
        for(int x = 0; x < V; x++){
            if(sptSet[x] == FALSE && key[x] < min){
                min = key[x];
                min_index = x;
            }
        }
        
        sptSet[min_index] = TRUE;
        
        for(int y = 0; y < V; y++){
            if(sptSet[y] == FALSE && graph[min_index][y] < key[y]){
                parent[y] = min_index;
                key[y] = graph[min_index][y];
            }
        }
        
    }
    printMST(parent,V,graph);
}

void printMST(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d    %d \n", parent[i], i, graph[i][]);
    }
}
















