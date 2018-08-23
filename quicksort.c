//
//  main.c
//  quicksort
//
//  Created by Sean Stuart C Urgel on 27/06/2017.
//  Copyright © 2017 Sean Stuart C Urgel. All rights reserved.
//

#include <stdio.h>


int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

int main(void) {
    int arr[100] = {15,22,13,27,12,10,20,25,35, 2, 3, 1, 5, 7, 8, 13, 50, 46 , 45, 43, 32, 44, 41};
    
    for(int x = 0; x < 23; x++){
        printf("%d ", arr[x]);
    }
    
    printf("\n");
    
    quicksort(arr, 0, 22);
    
    for(int x = 0; x < 23; x++){
        printf("%d ", arr[x]);
    }
    
    return 0;
}

int partition(int arr[], int low, int high)
{
    int i, j, temp;
    int pivotitem = arr[low];
    
    j = low;
    
    for(i = j + 1; i <= high; i++){
        if(arr[i] < pivotitem){
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int pivotpoint = j;
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return pivotpoint;
}

void quicksort(int arr[], int low, int high)
{
    int pivotpoint;
    if(low < high){
        pivotpoint = partition(arr, low, high);
        quicksort(arr, low, pivotpoint - 1);
        quicksort(arr, pivotpoint + 1, high);
    }
}


