/******************************************************************************

                    Review about Close-Hash Dictionary

*******************************************************************************/
/* Some Challenges for you to Practice 
    1. Try hashing using char.
    2. Try converting Close-Hash Dictionary to Open-Hash Dictionary
    3. Try making the elements of Close-Hash using Cursor-Based Dictionary
    4. Try making a hash algorithm using both chars and int
    5. Try using insertSorted
    6. Try to display a count
    7. Try making DeleteAll
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define DELETED -2
#define EMPTY -1

typedef int CloseDict[MAX];

/* Main Functions */
CloseDict* initCloseDict(void);
int hashData(int data); // hash in the ones place
void insertElem(CloseDict* D, int data);
void deleteElem(CloseDict* D, int data);

/* Utility Functions */
void displayCloseDict(CloseDict D);
int isFull(CloseDict D);
int isMem(CloseDict D, int data);

int main(){
    CloseDict* D = initCloseDict();
    displayCloseDict(*D);
    
    /* insertUnique in Close Hash */
    insertElem(D, 546);
    insertElem(D, 632);
    insertElem(D, 10923);
    insertElem(D, 49385);
    insertElem(D, 30453);
    insertElem(D, 95069);
    insertElem(D, 67585);
    insertElem(D, 102953);
    insertElem(D, 3451);
    insertElem(D, 98761);
    insertElem(D, 76853); // Error, dict is full
    insertElem(D, 8534); // Error, dict is full
    displayCloseDict(*D);
    
    /* delete in Close Hash */
    deleteElem(D, 10923);
    deleteElem(D, 67585);
    deleteElem(D, 546);  
    displayCloseDict(*D);
    
    /* delete ALL in Close Hash */
    deleteElem(D, 546); // not found
    deleteElem(D, 632);
    deleteElem(D, 10923); // not found
    deleteElem(D, 49385);
    deleteElem(D, 30453);
    deleteElem(D, 95069);
    deleteElem(D, 67585); // not found
    deleteElem(D, 102953);
    deleteElem(D, 3451);
    deleteElem(D, 98761);
    displayCloseDict(*D);
        
    return 1;
}

void displayCloseDict(CloseDict D){
    
    int i; // For accessing the index
    
    printf("\n\nDetails of the Close Hash Dictionary:: ");
	printf("\n-------------------------------------");
	
// 	printf("\nNo. of elements :: %d", D.count);
	printf("\n\n%-7s", "INDEX");
	printf("%12s","Data");
	printf("\n%-7s%15s", "------","----------");
	
    for(i = 0; i < MAX; i++){
        printf("\nIndex[%d] :: %6d", i, D[i]);
    }
}

int hashData(int data){
    return data % 10;
}

CloseDict* initCloseDict(void){
    CloseDict* D = (CloseDict*)malloc(sizeof(CloseDict));
    int i;
    for(i = 0; i < MAX; i++){
        (*D)[i] = EMPTY;
    }
    return D;
}

int isMem(CloseDict D, int data){
    int hashVal = hashData(data);
    int i, counter = 0;
    for(i = hashVal; counter != MAX && D[i] != EMPTY && D[i] != DELETED && D[i] != data; i = (i + 1) % MAX, counter++){}
    return (D[i] == data) ? 1 : 0;
}

int isFull(CloseDict D){
    int i, counter = 0;
    for(i = 0; i < MAX; i++){
        if(D[i] != EMPTY && D[i] != DELETED){
            counter++;
        }
    }
    
    return (counter == MAX) ? 1 : 0;
}

void insertElem(CloseDict *D, int data){
    if(isMem(*D, data) != 1 && isFull(*D) != 1){
        int hashVal = hashData(data);  
        int i;
        for(i = hashVal; (*D)[i] != EMPTY && (*D)[i] != DELETED; i = (i + 1) % MAX){}
        (*D)[i] = data;
    } else {
        printf("\nDictionary is full. Can't insert data: %d", data);
    }
}


void deleteElem(CloseDict *D, int data){
    int hashVal = hashData(data);
    int i, counter = 0;
    
    for(i = hashVal; counter != MAX && (*D)[i] != EMPTY && (*D)[i] != data; i = (i + 1) % MAX, counter++){}
    if(counter != MAX){
        (*D)[i] = DELETED;    
    } else {
        printf("\nDictionary is empty. No more values to delete.");
    }
}




