/******************************************************************************

                    Review about Open-Hash Dictionary

*******************************************************************************/
/* Some Challenges for you to Practice 
    1. Try hashing using char.
    2. Try converting Open-Hash Dictionary to Close-Hash Dictionary
    3. Try making the elements of Open-Hash using Cursor-Based Dictionary
    4. Try making a hash algorithm using both chars and int
    5. Try using insertSorted
    6. Try to display a count
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
}nodeType, *LL;

typedef LL OpenDict[MAX];

/* Main Functions */
OpenDict* initOpenDict(void);
int hashData(int data); // hash in the ones place
void insertElem(OpenDict* D, int data);
void deleteElem(OpenDict* D, int data);

/* Utility Functions */
void displayOpenDict(OpenDict D);
int isMem(OpenDict D, int data);

int main(){
    OpenDict* D = initOpenDict();
    displayOpenDict(*D);
    
    /* insertUnique in Openhash */
    insertElem(D, 546);
    insertElem(D, 632);
    insertElem(D, 10923);
    insertElem(D, 49385);
    insertElem(D, 30453);
    insertElem(D, 95069);
    insertElem(D, 67585);
    insertElem(D, 102953);
    displayOpenDict(*D);
    
    /* delete in Open Hash */
    deleteElem(D, 10923);
    deleteElem(D, 67585);
    deleteElem(D, 546);  
    displayOpenDict(*D);
        
    return 1;
}

void displayOpenDict(OpenDict D){
    
    int i; // For accessing the index
    LL trav; // For acceessing the list
    
    printf("\n\nDetails of the Open Hash Dictionary:: ");
	printf("\n-------------------------------------");
	
// 	printf("\nNo. of elements :: %d", D.count);
	printf("\n\n%-7s", "GROUPS");
	printf("%15s","ID Numbers");
	printf("\n%-7s%15s", "------","----------");
	
    for(i = 0; i < MAX; i++){
        printf("\nGroup[%d] :: ", i);
        for(trav = D[i]; trav != NULL; trav = trav->next){
            printf("%-7d", trav->data);    
        }
    }
}

int hashData(int data){
    return data % 10;
}

OpenDict* initOpenDict(void){
    OpenDict* D = (OpenDict*)malloc(sizeof(OpenDict));
    int i;
    for(i = 0; i < MAX; i++){
        (*D)[i] = NULL;
    }
    return D;
}

int isMem(OpenDict D, int data){
    int hashVal = hashData(data);
    LL trav;
    for(trav = D[hashVal]; trav != NULL && trav->data != data; trav = trav->next){}
    return (trav != NULL) ? 1 : 0;
}

void insertElem(OpenDict *D, int data){
    if(isMem(*D, data) != 1){
        int hashVal = hashData(data);  
        LL *trav;
        for(trav = &(*D)[hashVal]; *trav != NULL; trav = &(*trav)->next){}
        
        LL temp = (LL) malloc (sizeof(nodeType));
        if(temp != NULL){
            temp->data = data;
            temp->next = *trav;
            *trav = temp;
        }
    }
}


void deleteElem(OpenDict *D, int data){
    int hashVal = hashData(data);
    LL *trav, temp;
    for(trav = &(*D)[hashVal]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    
    temp = *trav;
    *trav = temp->next;
    free(temp);
}




