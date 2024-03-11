#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define DELETED -1
#define EMPTY -2

typedef int DICTIONARY[SIZE];

/* Main Functions */
void initDictionary(DICTIONARY* D); // Set all values inside to EMPTY
int hash(int hashData);
void insertElem(DICTIONARY* D, int data);
void deleteElem(DICTIONARY* D, int data);

/* Utilitiy Functions */
void displayDictionary(DICTIONARY D);
int isMember(DICTIONARY D, int data);
int isFull(DICTIONARY D);
void pause(void);

void main(){
	DICTIONARY D;
	initDictionary(&D);
	
	/* Display Initialization Values */
	displayDictionary(D);
	pause();
	
	/* Insertion */
	printf("---- Usual Insertion ----\n");
	insertElem(&D, 59);
	insertElem(&D, 12);
	insertElem(&D, 10);
	insertElem(&D, 21);
	insertElem(&D, 76);
	
	displayDictionary(D);
	pause();
	
	/* Insertion with Collision (Synonym)*/
	printf("--- Insertion(Collision-Synonym) ---\n");
	insertElem(&D, 69);
	insertElem(&D, 100);
	insertElem(&D, 856);
	
	displayDictionary(D);
	pause();
	
	/* Insertion with Collision (Displacement)*/
	printf("--- Insertion(Collision-Displacement) ---\n");
	insertElem(&D, 93);
	insertElem(&D, 1284);
	insertElem(&D, 1223); // insertion unsuccessful

	displayDictionary(D);
	pause();
	
	/* Deletion */
	printf("---- Usual Deletion ----\n");
	deleteElem(&D, 59);
	deleteElem(&D, 69);
	deleteElem(&D, 100);
	deleteElem(&D, 856);
	deleteElem(&D, 12);
	deleteElem(&D, 10);
	deleteElem(&D, 21);
	deleteElem(&D, 76);
	deleteElem(&D, 93);
	deleteElem(&D, 1284);
	deleteElem(&D, 1284); // Element not found, terminate loop

	displayDictionary(D);
	pause();
	
	/* Insertion on Deleted Values */
	printf("---- Insertion on Deleted Values ----\n");
	insertElem(&D, 63);
	insertElem(&D, 56);
	
	displayDictionary(D);
	pause();
	
	printf("CONGRATULATIONS!\nYOU NOW KNOW HOW TO CODE DICTIONARY (CLOSE HASHING)!\nJUST UNDERSTAND ITS IMPLEMENTATION AND CODE IT REGULARLY");
}

void pause(void) {
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void initDictionary(DICTIONARY* D){ /* You can also use a parameter with no pointers since D is already a pointer to the first element of the first index */
	
	int i;
	for(i = 0; i < SIZE; i++){
		(*D)[i] = EMPTY;
	}
}

void displayDictionary(DICTIONARY D){
	
	printf("--- DICTIONARY VALUES ----\n\n");
	
	int i;
	for(i = 0; i < SIZE; i++){
		printf("    [%d]     => %5d\n", i, D[i]);
	}
}

/* The hash() function accepts as parameter an integer ndx and returns the digit in the ones place of x. */
int hash(int hashData) {
    return hashData % 10;
}

int isFull(DICTIONARY D){
	int i, counter = 0;
	for(i = 0; i < SIZE; i++){
		if(D[i] != EMPTY && D[i] != DELETED){
			counter++;
		}
	}
	
	return (counter == SIZE) ? 1 : 0;
}

int isMember(DICTIONARY D, int data){
	int i;
	for(i = hash(data); D[i] != DELETED && D[i] != EMPTY && D[i] != data; i = (i + 1) % SIZE){} 
	
	return (D[i] == data) ? 1 : 0;
}

void insertElem(DICTIONARY* D, int data){
	// Check if the DICTIONARY is full and if the data is unique
	if(isFull(*D) != 1 && isMember(*D, data) != 1){
		// get its index by hashing and store it in a variable ndx
		int ndx = hash(data);
		// if the value of the hashed data is EMPTY or DELETED, insert
		int i;
		for(i = ndx; (*D)[i] != EMPTY && (*D)[i] != DELETED; i = (i + 1) % SIZE){}
		(*D)[i] = data; 		
	} else {
		printf("Dictionary is already full. Data %d insertion unsuccessful\n\n", data);
	}
}

void deleteElem(DICTIONARY* D, int data){
	// get its index by hashing and store it in a variable ndx
	int ndx = hash(data);
	// if the value of the hashed ndx is equal to data, delete
	int i, counter = 0;
	for(i = ndx; counter != SIZE && (*D)[i] != EMPTY && (*D)[i] != data; i = (i + 1) % SIZE, counter++){}
	(*D)[i] = DELETED;
	
	if(counter == SIZE){
		printf("Dictionary is empty. No more values to delete.\n\n");
	}
}
