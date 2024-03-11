/******************************************************************************

                    Review about Cursor-Based Implementation

*******************************************************************************/

#include <stdio.h>
#define SIZE 5

typedef struct{
    int data;
    int next;
}nodeType;

typedef struct node{
    nodeType elem[SIZE];
    int avail;
}VirtualHeap;

typedef int CBList;

/* Main Functions */
int allocSpace(VirtualHeap* VH);
void insertFirst(VirtualHeap* VH, CBList* head, int data);
void insertLast(VirtualHeap* VH, CBList* head, int data);
void insertSorted(VirtualHeap* VH, CBList* head, int data);

void deallocSpace(VirtualHeap* VH, int ndx);
void deleteFirst(VirtualHeap* VH, CBList* head);
void deleteLast(VirtualHeap* VH, CBList* head);

/* Utility Functions */
void initVHeap(VirtualHeap* VH);
CBList initCBList(void);
void displayVirtualHeap(VirtualHeap VH);
void displayCBList(VirtualHeap VH, CBList head);
int isMember(VirtualHeap VH, CBList head, int data);

// Also try insertUnique if Cursor-Based is a Set...
// Also try if the elements inside the Virtual Heap are characters
// Also try incorporating count and have it print if it exceeds the size and if no space available
// Also try deleteSearch

int main()
{
    VirtualHeap VH;
    CBList C = initCBList();
    
    initVHeap(&VH);
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);
    
    /* Insertion */
    /* Insert First */
    insertFirst(&VH, &C, 89);
    insertFirst(&VH, &C, 67);
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);
    
    /* Insert Last */
    insertLast(&VH, &C, 54);
    insertLast(&VH, &C, 21);
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);
    
    /* Insert Sorted */
    insertSorted(&VH, &C, 60);
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);
    
    
    /* Deletion */
    /* Delete First */
    deleteFirst(&VH, &C); // 89
    deleteFirst(&VH, &C); //67
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);
    
    /* Delete Last */
    deleteLast(&VH, &C); // 54
    deleteLast(&VH, &C); // 21
    
    displayVirtualHeap(VH);
    displayCBList(VH, C);

    return 0;
}

void initVHeap(VirtualHeap* VH){
    int i, lastNdx = SIZE-1;
    for(i = lastNdx; i >= 0; i--){
        VH->elem[i].next = i - 1;
    }
    VH->avail = lastNdx;
}

CBList initCBList(void){
    CBList C = -1;
    return C;
}

void displayVirtualHeap(VirtualHeap VH){
    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", VH.avail);       //Complete this statement
	printf("\nVHeap Address    ::  %p" , &VH);       //Complete this statemet
	
    printf("\n\n%10s", "Index");
    printf("%10s", " ");
    printf("%15s", "Next Field");
	printf("\n%10s%10s%15s", "-----", " ","----------");
	
	int i;
	for(i = 0; i < SIZE; i++){
	    printf("\n%8d%10s%12d", i, "=>", VH.elem[i].next); 
	}
}

void displayCBList(VirtualHeap VH, CBList head){
	printf("\n\nDetails of the Set :: ");
	printf("\n---------------------");
// 	printf("\nNo. of elements ::  %d", A.count);      //Complete this code
	printf("\n\n%7s", "Index");
	printf("%13s","Data");
	printf("%18s","VHeap Index");
	printf("\n%-12s%-15s%-10s", "----------", "------------", "-----------");

	CBList trav;
	for(trav = head; trav != -1; trav = VH.elem[trav].next){
	   printf("\n%5d%14d%14d", trav, VH.elem[trav].data, VH.elem[trav].next);
	}
}

int allocSpace(VirtualHeap* VH){
    int retVal = VH->avail;
    
    if(retVal != -1) {
        VH->avail = VH->elem[retVal].next;
    }
    return retVal;
}

void insertFirst(VirtualHeap* VH, CBList* head, int data){
    CBList ndx = allocSpace(VH); // you can also use int directly since CBList is just an int, but it is better to use CBList for readability
    
    if(ndx != -1){
        VH->elem[ndx].data = data;
        VH->elem[ndx].next = *head;
        *head = ndx;
    }
}

void insertLast(VirtualHeap* VH, CBList* head, int data){
    CBList *trav, ndx = allocSpace(VH);
    
    if(ndx != -1){
        for(trav = head; *trav != -1; trav = &VH->elem[*trav].next){}
        VH->elem[ndx].data = data;
        VH->elem[ndx].next = *trav;
        *trav = ndx;
    }
}

void insertSorted(VirtualHeap* VH, CBList* head, int data){
    CBList *trav, ndx = allocSpace(VH);
    
    if(ndx != -1) {
        for(trav = head; *trav != -1 && data < VH->elem[*trav].data; trav = &VH->elem[*trav].next){}
        VH->elem[ndx].data = data;
        VH->elem[ndx].next = *trav;
        *trav = ndx;
    }
}

void deallocSpace(VirtualHeap* VH, int ndx){
    if(ndx > 0 && ndx < SIZE){
        VH->elem[ndx].next = VH->avail;
        VH->avail = ndx;
    }
}

void deleteFirst(VirtualHeap* VH, CBList* head){
    if(*head != -1) {
        CBList *trav, temp;
        
        trav = head;
        temp = *trav;
        *trav = VH->elem[temp].next;
        deallocSpace(VH, temp);
    }
}

void deleteLast(VirtualHeap* VH, CBList* head){
    if(*head != - 1){
        CBList *trav, temp;

        for(trav = head; VH->elem[*trav].next != -1; trav = &VH->elem[*trav].next){}
        temp = *trav;
        *trav = VH->elem[temp].next;
        deallocSpace(VH, temp);
    }    
}

