/* Some Reminders about Array Assignment when using typedefs on ChatGPT. Write it down on notes*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef int SET[SIZE];

/* Main Functions */
void insertElem(SET S, int ndx);
void deleteElem(SET S, int ndx);
SET* setUnion(SET A, SET B);
SET* setIntersection(SET A, SET B);
SET* setDifference(SET A, SET B);

/* Utility Functions */
void displaySET(SET S);
void isElem(SET S);
void pause(void);

void main() {
	SET A = {1, 1, 1, 0, 1}; // SET A contain elements 0, 1, 2, and 4
	SET B = {0, 1, 0, 0, 1}; // SET B contain elements 1 and 4
	SET* C; // SET C use for UID
	
	/* Print the original values of SET A and B */
	printf("SET A: ");
	displaySET(A);
	printf("SET B: ");
	displaySET(B);
	pause();
	
	/* Insert element in SET B*/
	insertElem(B, 2); //B[2] = 1 -> SET B = {0, 1, 1, 0 , 1}
	printf("After Inserting in SET B:\n\nSET B: ");
	displaySET(B);
	pause();
	
	/* Delete element in SET A*/
	deleteElem(A, 1); //B[1] = 0 -> SET A = {1, 0, 1, 0, 1}
	printf("After Deleting in SET A:\n\nSET A: ");
	displaySET(A);
	pause();
	
	/* UIDs */
	printf("SET UNION OF A AND B:\n\nSET C: ");
	C = setUnion(A, B); // A UNION B  = {1, 1, 1, 0, 1}
	displaySET(*C); // The passed argument must be a dereference pointer to get its value
	pause();
	
	printf("SET INTERSECTION OF A AND B:\n\nSET C: ");
	C = setIntersection(A, B); // A INTERSECTION B  = {0, 0, 1, 0, 1}
	displaySET(*C);
	pause();

	printf("SET DIFFERENCE OF A TO B:\n\nSET C: ");
	C = setDifference(A, B); // A DIFFERENCE B = {1, 0, 0, 0, 0}
	displaySET(*C);
	pause();
	
	printf("CONGRATULATIONS!\nYOU NOW KNOW HOW TO CODE BIT VECTOR!\nJUST UNDERSTAND ITS IMPLEMENTATION AND CODE IT REGULARLY");
}

/* Utility Functions */

void pause(void) {
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void displaySET(SET S){
	int i;
	
	for(i = 0; i < SIZE; i++){
		printf("%d ", S[i]);
	}
	printf("\n");
}

/* Main Functions */

void insertElem(SET S, int ndx){
	// Check first if ndx ranges from 0 - (SIZE - 1)
	if(ndx < SIZE){
		S[ndx] = 1;	
	}
}

void deleteElem(SET S, int ndx){
	// Check first if ndx ranges from 0 - (SIZE - 1)
	if(ndx < SIZE) {
		S[ndx] = 0;
	}
}

SET* setUnion(SET A, SET B){
	SET* C = (SET*) malloc (sizeof(SET)); // Allocate memory for the new SET after UNION

	// Check every index and compare it with OR in UNION
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
	SET* C = (SET*) malloc (sizeof(SIZE));
	
	int i;
	for(i = 0; i < SIZE; i++){
		(*C)[i] = A[i] &~ B[i];
	}
	
	return C;
}
