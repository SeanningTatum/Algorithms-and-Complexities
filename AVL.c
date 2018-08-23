/*
//  main.c
//  AVL
//
//  Created by Sean Stuart C Urgel on 25/07/2017.
//  Copyright © 2017 Sean Stuart C Urgel. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
/* * * * * * * * * * * * * * * * *
 *      STRUCTURE DEFINITIONS
 * * * * * * * * * * * * * * * * */

typedef struct node{
    int elem;
    int height;
    struct node *LC, *RC;
}*AVL;

typedef enum{TRUE,FALSE}boolean;

/* * * * * * * * * * * * * * * * *
 *      FUNCTION PROTOTYPES
 * * * * * * * * * * * * * * * * */
void insertAVL(AVL *A, int elem);
void preOrder(AVL A);

int max(int a, int b);
int getHeight(AVL A);
int getBalance(AVL A);

AVL createNode(int elem);

void rightRotate(AVL *A);
void leftRotate(AVL *A);
/* * * * * * * * * * * * * * * * *
 *           MAIN
 * * * * * * * * * * * * * * * * */
int main(void) {
    AVL A = NULL;
    insertAVL(&A, 10);
    insertAVL(&A, 20);
    insertAVL(&A, 30);
    insertAVL(&A, 40);
    insertAVL(&A, 50);
    insertAVL(&A, 25);
    insertAVL(&A, 80);
    insertAVL(&A, 90);
    insertAVL(&A, 100);
    
    printf("\nPre-Order Print\n");
    printf("- - - - - - - - - -\n");
    preOrder(A);
    
    return 0;
}

/* * * * * * * * * * * * * * * * *
 *      FUNCTION DEFINITIONS
 * * * * * * * * * * * * * * * * */

/* This function inserts the element into the AVL tree */
/* And balances the tree if necessary                 */
void insertAVL(AVL *A, int elem)
{
    /* 1) Perform the regular BST insertion */
    if(*A != NULL){
        if(elem < (*A)->elem ){
            insertAVL( &(*A)->LC, elem);
        }else{
            insertAVL( &(*A)->RC, elem);
        }
    }

    if(*A == NULL){
        *A = createNode(elem);
    }
    
    /* 2) Update the height of the ancestor node */
    (*A)->height = max(getHeight((*A)->LC), getHeight((*A)->RC)) + 1;
    
    /* 3) Get the balance factor to determine if the 
            current node has become unbalanced */
    int balance = getBalance(*A);
    printf("balance factor of %d : %d\n", (*A)->elem, balance);
    
    /* 4) If node has become unbalanced check for 4 cases */
    AVL left = (*A)->LC;
    AVL right = (*A)->RC;
    
    /* Left Left Case*/
    if(balance > 1 && elem < left->elem){
        printf("- - - - - - - \n");
        printf("Left Left Case!\n");
        printf("- - - - - - - \n");
        
        rightRotate(A);
    }
    
    /* Right Right Case */
    if(balance < -1 && elem > right->elem){
        printf("- - - - - - - \n");
        printf("Right Right Case!\n");
        printf("- - - - - - - \n");
        
        leftRotate(A);
    }
    
    /* Left Right Case */
    if(balance > 1 && elem > left->elem){
        printf("- - - - - - - \n");
        printf("Left Right case!\n");
        printf("- - - - - - - \n");
        
        leftRotate(&(*A)->LC);
        rightRotate(A);
    }
    
    /* Right Left Case */
    if(balance < -1 && elem < right->elem){
        printf("- - - - - - - \n");
        printf("Right Left Case!\n");
        printf("- - - - - - - \n");
        
        rightRotate(&(*A)->RC);
        leftRotate(A);
    }

}
/* end insert AVL */

/* Prints the tree in pre order */
void preOrder(AVL A)
{
    if(A != NULL){
        printf("%d ", A->elem);
        preOrder(A->LC);
        preOrder(A->RC);
    }
}
/* end preOrder */

/* * * * * * * * * * * * * * * * * * * *
 *             ROTATIONS
 * * * * * * * * * * * * * * * * * * * */
void leftRotate(AVL *A)
{
    AVL y = (*A)->RC;
    AVL x = y->LC;
    
    /* perform  rotation */
    y->LC = *A;
    (*A)->RC = x;
    
    /* update heights */
    (*A)->height = max(getHeight( (*A)->LC ), getHeight( (*A)->RC)  ) + 1;
    y->height = max(getHeight(y->LC), getHeight(y->RC) ) + 1;
    
    /* change the root node */
    *A = y;
}

void rightRotate(AVL *A)
{
    AVL x = (*A)->LC;
    AVL y = x->RC;
    
    /* perform  rotation */
     x->RC = *A;
    (*A)->LC = y;
    
    /* update heights */
    (*A)->height = max(getHeight( (*A)->LC ), getHeight( (*A)->RC)  ) + 1;
    x->height = max(getHeight(x->LC), getHeight(x->RC) ) + 1;
    
    /* change the root node */
    *A = x;
}
/* * * * * * * * * * * * * * * * * * * *
*        UTILITY FUNCTIONS
* * * * * * * * * * * * * * * * * * * */

/* Function for creating and initialzing a new node */
AVL createNode(int elem)
{
    AVL temp = (AVL)malloc(sizeof(struct node));
    temp->elem = elem;
    temp->height = 1;
    temp->LC = temp->RC = NULL;
    
    printf("I was created: %d \n", temp->elem);
    
    return temp;
}
/* end createNode */


/* Function to get the max between to integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
/* end max */


/* Function to return the height of a given node */
int getHeight(AVL A)
{
    return (A == NULL)? 0 : A->height;
}
/* end getHeight */


/* Function to get the balance factor of node */
int getBalance(AVL A)
{
    return (A == NULL)? 0 : getHeight(A->LC) - getHeight(A->RC);
}










