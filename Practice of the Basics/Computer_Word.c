// bit representation of a SET
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET; // char = 1 byte -> 1 byte = 8 bits

/* Main Functions */
void insertElem(SET* S, unsigned char ndx);
void deleteElem(SET* S, unsigned char ndx);
SET setUnion(SET A, SET B);
SET setIntersection(SET A, SET B);
SET setDifference(SET A, SET B);

/* Utility Functions */
void displaySET(SET S); // elements of the set
void displayBitPattern(SET S); // 1s and 0s of the set
int isMember(SET S, unsigned char ndx);
void pause(void);

void main(){
	SET A = 0; // 0000 0000
	SET B = 0; // 0000 0000
	SET C; // for UIDs
	
	/* Initialization of Computer Word */
	printf("Initialization of SETS in Computer Word\n");
	printf("\nBit Pattern of A: ");
	displayBitPattern(A);
	printf("\nBit Pattern of B: ");
	displayBitPattern(B);
	
	printf("\n\nElements of SET A: ");
	displaySET(A);
	printf("\nElements of SET B: ");
	displaySET(B);
	pause();
	
	/* Insertion for SET A and B */
	printf("Insertion of SETS in Computer Word\n");
	insertElem(&A, 0);
	insertElem(&A, 1);
	insertElem(&A, 5);
	insertElem(&A, 7);
	
	insertElem(&B, 2);
	insertElem(&B, 5);
	
	printf("\nBit Pattern of A: ");
	displayBitPattern(A); // 1010 0011 = 163
	printf("\nBit Pattern of B: ");
	displayBitPattern(B); // 0010 0100 = 36
	
	printf("\n\nElements of SET A: ");
	displaySET(A); // SET A = {0, 1, 5, 7}
	printf("\nElements of SET B: ");
	displaySET(B); // SET B = {2, 5}
	pause();
	
	/* Deletion for SET A and B*/
	printf("Deletion of SETS in Computer Word\n");
	deleteElem(&A, 1);
	deleteElem(&A, 7);
	
	deleteElem(&B, 2);
	
	printf("\nBit Pattern of A: ");
	displayBitPattern(A); // 0010 0001 = 33
	printf("\nBit Pattern of B: ");
	displayBitPattern(B); // 0010 0000 = 32
	
	printf("\n\nElements of SET A: ");
	displaySET(A); // SET A = {0, 5}
	printf("\nElements of SET B: ");
	displaySET(B); // SET B = {5}
	pause();
	
	/* Start of UIDs */
	/* Union SET C of SET A and B */
	printf("Union of SET A and B\n");
	C= setUnion(A, B);
	printf("\nBit Pattern of C: ");
	displayBitPattern(C); // 0010 0001 = 33
	printf("\n\nElements of SET C: ");
	displaySET(C); // SET A = {0, 5}
	pause();
	
	/* Intersection SET C of SET A and B */
	printf("Intersection of SET A and B\n");
	C= setIntersection(A, B);
	printf("\nBit Pattern of C: ");
	displayBitPattern(C); // 0010 0000 = 32
	printf("\n\nElements of SET C: ");
	displaySET(C); // SET A = {5}
	pause();
	
	/* Difference SET C of SET A to B */
	printf("Difference of SET A and B\n");
	C= setDifference(A, B);
	printf("\nBit Pattern of C: ");
	displayBitPattern(C); // 000 0001 = 1
	printf("\n\nElements of SET C: ");
	displaySET(C); // SET A = {0}
	pause();
	
	/* Difference SET C of SET B to A */
	printf("Difference of SET B and A\n");
	C= setDifference(B, A);
	printf("\nBit Pattern of C: ");
	displayBitPattern(C); // 000 0000 = 0
	printf("\n\nElements of SET C: ");
	displaySET(C); // SET A = 
	pause();
	
	printf("CONGRATULATIONS!\nYOU NOW KNOW HOW TO CODE COMPUTER WORD!\nJUST UNDERSTAND ITS IMPLEMENTATION AND CODE IT REGULARLY");
}

void pause(void) {
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void insertElem(SET* S, unsigned char ndx){
	*S |= 1 << ndx;
}

void deleteElem(SET* S, unsigned char ndx){
	*S &= ~(1 << ndx);
}

void displayBitPattern(SET S){
	int mask;
	
	for(mask = 1 << sizeof(SET)*8-1; mask > 0; mask >>= 1){
		printf("%d", (S & mask) ? 1 : 0);
	}
}

SET setUnion(SET A, SET B){
	return A | B;
}

SET setIntersection(SET A, SET B){
	return A & B;
}

SET setDifference(SET A, SET B){
	return A &~ B;
}

void displaySET(SET S){
	int i;
	int SIZE = sizeof(SET) * 8; // mask = 1 * 8 - 1 = 7 which has a value of 128
		
	for(i = 0; i < SIZE; i++){ // treat 0 as index, not a normal value
		if(S & (1 << i)){
			printf("%d ", i);
		}
	}
}


