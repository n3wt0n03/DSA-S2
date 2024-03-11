/******************************************************************************

                    Review about Bit-Vector in Sets

*******************************************************************************/
/* Some Challenges for you to Practice 
    1. Try comparing sets using char.
    2. Try converting Bit-Vector to Computer-Word
    3. Try making the function body for isMember
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef int SET[SIZE];

/* Main Functions */
void insertSetData(SET S, int data);
void deleteSetData(SET S, int data);
SET* setUnion(SET A, SET B);
SET* setIntersection(SET A, SET B);
SET* setDifference(SET A, SET B);

/* Utility Functions */
SET* initSET(void);
void displaySet(SET S);
void isMember(SET S, int data);

int main(){
    /* Initialization */
    SET* A = initSET();
    SET* B = initSET();
    SET* C = initSET();
    
    printf("\nInitialization of SET A and B:\n");
    printf("SET A: ");
    displaySet(*A); // A = { } => {0, 0, 0, 0, 0}
    printf("SET B: ");
    displaySet(*B); // B = { } => {0, 0, 0, 0, 0}
    
    /* Insert Data to SET A and B*/
    insertSetData(*A, 1);
    insertSetData(*A, 3);
    insertSetData(*A, 4);
    
    insertSetData(*B, 1);
    insertSetData(*B, 2);
    insertSetData(*B, 4);
    insertSetData(*B, 0);
    
    printf("\nInsertion of data in SET A and B:\n");
    printf("SET A: ");
    displaySet(*A); // A = {1, 3, 4} => {0, 1, 0, 1, 1}
    printf("SET B: ");
    displaySet(*B); // B = {0, 1, 2, 4} => {1, 1, 1, 0, 1}
    
    
    /* Delete Data to SET A and B*/
    deleteSetData(*A, 1);
    
    deleteSetData(*B, 4);
    deleteSetData(*B, 2);
    
    printf("\nDeletion of data in SET A and B:\n");
    printf("SET A: ");
    displaySet(*A); // A = {3, 4} => {0, 0, 0, 1, 1}
    printf("SET B: ");
    displaySet(*B); // B = {0, 1} => {1, 1, 0, 0, 0}
    
    /* SET UIDs */
    printf("\nUnion of SET A and B:\n");
    printf("SET C: ");
    C = setUnion(*A, *B); // C= {0, 1, 3, 4} => {1, 1, 0, 1, 1}
    displaySet(*C);
    
    printf("\nIntersection of SET A and B:\n");
    printf("SET C: ");
    C = setIntersection(*A, *B); // C= {0, 1, 3, 4} => {0, 0, 0, 0, 0}
    displaySet(*C);
    
    printf("\nDifference of SET A to B:\n");
    printf("SET C: ");
    C = setDifference(*A, *B); // C= {0, 1, 3, 4} => {0, 0, 0, 1, 1}
    displaySet(*C);
    
    printf("\nDifference of SET B to A:\n");
    printf("SET C: ");
    C = setDifference(*B, *A); // C= {0, 1, 3, 4} => {1, 1, 0, 0, 0}
    displaySet(*C);
    
    return 1;
}

SET* initSET(void){
    SET* S = (SET*) malloc (sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*S)[i] = 0;
    }
    return S;
}

void displaySet(SET S){
    int i;
    for(i = 0; i < SIZE; i++){
        printf("%d ", S[i]);
    }
    printf("\n");
}

void insertSetData(SET S, int data){
    if(data < SIZE){
        S[data] = 1;
    }
}

void deleteSetData(SET S, int data){
    if(data < SIZE){
        S[data] = 0;
    }
}

SET* setUnion(SET A, SET B){
    SET* C = (SET*) malloc (sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] || B[i];
    }
    
    return C;
}

SET* setIntersection(SET A, SET B){
    SET* C = (SET*) malloc (sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] && B[i];
    }
    
    return C;
}

SET* setDifference(SET A, SET B){
    SET* C = (SET*) malloc (sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] &~ B[i];
    }
    
    return C;
}
