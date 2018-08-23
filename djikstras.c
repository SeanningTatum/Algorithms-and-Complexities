//
//  main.c
//  Graphs
//
//  Created by Sean Stuart C Urgel on 14/03/2017.
//  Copyright © 2017 Sean Stuart C Urgel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 9
#define MAX 9999

typedef enum{TRUE, FALSE}boolean;

int* djikstra(int graph[V][V], int src);
void printGraph(int dist[]);

int main(void)
{
    int *dist;
    int graph[V][V] = {
        {MAX, 4, MAX, MAX, MAX, MAX, MAX, 8, MAX},
        {4, MAX, 8, MAX, MAX, MAX, MAX, 11, MAX},
        {MAX, 8, MAX, 7, MAX, 4, MAX, MAX, 2},
        {MAX, MAX, 7, MAX, 9, 14, MAX, MAX, MAX},
        {MAX, MAX, MAX, 9, MAX, 1, MAX, MAX, MAX},
        {MAX, MAX, 4, 14, 1, MAX, 2, MAX, MAX},
        {MAX, MAX, MAX, MAX, MAX, 2, MAX, 1, 6},
        {8, 11, MAX, MAX, MAX, MAX, 1, MAX, 7},
        {MAX, MAX, 2, MAX, MAX, MAX, 6, 7, MAX}
    };
    
    
    dist = djikstra(graph, 0);x
    printGraph(dist);
    
    return 0;
}

int* djikstra(int graph[V][V], int src)
{
    int* retval;
    boolean sptSet[V];
    
    retval = (int*)malloc(sizeof(int)*(V-1));
    memcpy(retval, graph[src], sizeof(int)*(V-1));
    
    for(int x = 0; x < V; x++){
        sptSet[x] = FALSE;
    }
    
    retval[src] = 0;
    
    int min, min_index;
    
    for(int x = 0; x < V-1; x++){
        min = MAX;
        
        for(int y = 0;y < V; y++){
            if(sptSet[y] != TRUE && retval[y] <= min){
                min = retval[y];
                min_index = y;
            }
        }
        
        sptSet[min_index] = TRUE;
        
        for(int z = 0; z < V; z++){
            if(graph[min_index][z] + retval[min_index] < retval[z]){
                retval[z] = graph[min_index][z] + retval[min_index];
            }
        }
    }
    
    return retval;
}


void printGraph(int dist[])
{
    printf("index\t\tDistance from source\n");
    for(int x = 0; x < V; x++){
        printf("%d\t\t%d\n", x, dist[x]);
    }
}



