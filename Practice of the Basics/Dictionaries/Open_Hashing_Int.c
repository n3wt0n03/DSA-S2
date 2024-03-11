// Always remember, NULL are only used for pointers, not on arrays

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node{
	int data;
	struct node* next;
}nodeType, *LL;

/* DICTIONARY D is an array of pointers */
typedef LL DICTIONARY[SIZE];

/* Main Functions */
void initDictionary(DICTIONARY* D);
int hash(int hashData);
void insertElem(DICTIONARY* D, int data);
void deleteElem(DICTIONARY* D, int data);

/* Utility Functions */
void displayDictionary(DICTIONARY D);
int isMember(DICTIONARY D, int data);
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
	insertElem(&D, 956);
	insertElem(&D, 302);
	insertElem(&D, 76);
	insertElem(&D, 9286);
	
	displayDictionary(D);
	pause();
	
	/* Deletion */
	printf("---- Usual Deletion ----\n");
	deleteElem(&D, 76);
	deleteElem(&D, 12);
	deleteElem(&D, 9286);
	
	displayDictionary(D);
	pause();
}

void pause(void) {
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void displayDictionary(DICTIONARY D){
	
	printf("--- DICTIONARY VALUES ----\n\n");
	
	LL trav;
	int i;
	for(i = 0; i < SIZE; i++){
		printf(" [%d] => ", i);
		for(trav = D[i]; trav != NULL; trav = trav->next){
			printf(" %d  => ", trav->data);
		}
		printf("\n");
	}
}

void initDictionary(DICTIONARY* D){
    int i;
    for(i = 0; i < SIZE; i++){
        (*D)[i] = NULL;
    }
}

int hash(int hashData){
	return hashData % 10;
}

int isMember(DICTIONARY D, int data){
	int ndx = hash(data);
	LL trav;
	for(trav = D[ndx]; trav != NULL && trav->data != data; trav = trav->next){}
	
	return (trav != NULL) ? 1 : 0; 
}

void insertElem(DICTIONARY* D, int data){
	// Check if the element is unique
	if(isMember(*D, data) != 1){
		// Hash its index using data
		int ndx =  hash(data);
		// insert and link to its corresponding index
		LL *trav;
		for(trav = &(*D)[ndx]; *trav != NULL; trav = &(*trav)->next){}
		
		LL temp = (LL) malloc (sizeof(nodeType));
		if(temp != NULL){
			temp->data = data;
			temp->next = *trav;
			*trav = temp;
		}
	}
}

void deleteElem(DICTIONARY* D, int data){
	// hash its index using data
	int ndx = hash(data);
	// traverse the list and delete
	LL *trav;
	for(trav = &(*D)[ndx]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
	
	LL temp = *trav;
	*trav = temp->next;
	free(temp);
	
}
