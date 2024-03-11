/******************************************************************************

                    Review about Computer-Word in Sets

*******************************************************************************/
/* Some Challenges for you to Practice 
    1. Try comparing sets using char.
    2. Try converting Computer-Word to Computer-Word
    3. Try making the function body for isMember
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

/* Main Functions */
void insertSetData(SET* S, unsigned char data);
void deleteSetData(SET* S, unsigned char data);
SET setUnion(SET A, SET B);
SET setIntersection(SET A, SET B);
SET setDifference(SET A, SET B);

/* Utility Functions */
SET initSET(void);
void displaySet(SET S);
void displayBitPattern(SET S);
void isMember(SET S, unsigned char data);

int main(){
    /* Initialization */
    SET A = initSET();
    SET B = initSET();
    SET C = initSET();
    
    printf("\nInitialization of SET A and B:\n");
    printf("SET A: ");
    displayBitPattern(A); // A = { } => {0, 0, 0, 0, 0}
    printf("SET B: ");
    displayBitPattern(B); // B = { } => {0, 0, 0, 0, 0}
    
    /* Insert Data to SET A and B*/
    insertSetData(&A, 1);
    insertSetData(&A, 3);
    insertSetData(&A, 4);
    
    insertSetData(&B, 1);
    insertSetData(&B, 2);
    insertSetData(&B, 4);
    insertSetData(&B, 0);
    
    printf("\nInsertion of data in SET A and B:\n");
    printf("SET A: ");
    displayBitPattern(A); // A = {1, 3, 4} => 0001 1010 = 26
    printf("SET B: ");
    displayBitPattern(B); // B = {0, 1, 2, 4} => 0001 0111 = 23
    
    
    /* Delete Data to SET A and B*/
    deleteSetData(&A, 1);
    
    deleteSetData(&B, 4);
    deleteSetData(&B, 2);
    
    printf("\nDeletion of data in SET A and B:\n");
    printf("SET A: ");
    displayBitPattern(A); // A = {3, 4} => 0001 1000 = 24
    printf("SET B: ");
    displayBitPattern(B); // B = {0, 1} => 0000 0011 = 3
    
    /* SET UIDs */
    printf("\nUnion of SET A and B:\n");
    printf("SET C: ");
    C = setUnion(A, B); // C= {0, 1, 3, 4} => 0001 1011 = 27 
    displayBitPattern(C);
    printf("Elements of SET C: ");
    displaySet(C);
    
    printf("\nIntersection of SET A and B:\n");
    printf("SET C: ");
    C = setIntersection(A, B); // C= { } => 0000 0000 = 0 
    displayBitPattern(C);
    printf("Elements of SET C: \n");
    displaySet(C);
    
    printf("Difference of SET A to B:\n");
    printf("SET C: ");
    C = setDifference(A, B); // C= {3, 4} => 0001 1000 = 24
    displayBitPattern(C);
    printf("Elements of SET C: ");
    displaySet(C);
    
    printf("\nDifference of SET B to A:\n");
    printf("SET C: ");
    C = setDifference(B, A); // C= {0, 1} => 0000 0011 = 3
    displayBitPattern(C);
    printf("Elements of SET C: ");
    displaySet(C);
    
    return 1;
}

SET initSET(void){
    SET S = 0;
    return S;
}

void displaySet(SET S){
    int i;
    int SIZE = sizeof(SET)*8;
    for(i = 0; i < SIZE; i++){
        if(S & (1 << i)){
          printf("%d ", i);  
        }
    }
    printf("\n");
}

void displayBitPattern(SET S){
    int mask;
    
    for(mask = 1 << sizeof(SET)*8-1; mask > 0 ; mask >>= 1){
        printf("%d", (S & mask) ? 1 : 0);
    }
    printf("\n");
}

void insertSetData(SET* S, unsigned char data){
    *S |= 1 << data;
}

void deleteSetData(SET* S, unsigned char data){
    *S &= ~(1 << data);
}

SET setUnion(SET A, SET B){ return A | B;}

SET setIntersection(SET A, SET B){ return A & B;}

SET setDifference(SET A, SET B){ return A &~ B;}
