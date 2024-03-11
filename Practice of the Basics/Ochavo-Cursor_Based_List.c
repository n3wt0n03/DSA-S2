#include <stdio.h>
#define MAX 5

typedef struct {
	int data;
	int next; // Link
}NodeType; // Node

typedef struct {
	NodeType elems[MAX];
	int avail; // No. of Nodes Available
}VirtualHeap; // Virtual Heap

typedef int CBList; // Head of the List

/** Function Prototypes **/
/* Utility Functions */
void initVH(VirtualHeap* VH);
CBList initCBList(void);
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap* VH, int ndx);
void display(VirtualHeap VH, CBList head);
int isMember(VirtualHeap VH, CBList head, int data);

/* Insertion */
void insertFirst(VirtualHeap* VH, CBList* head, int data);
void insertLast(VirtualHeap* VH, CBList* head, int data);
void insertSorted(VirtualHeap* VH, CBList* head, int data);

/* Utility Functions */
void deleteFirst(VirtualHeap* VH, CBList* head);
void deleteLast(VirtualHeap* VH, CBList* head);
void deleteAll(VirtualHeap* VH, CBList* head);
void deleteElem(VirtualHeap* VH, CBList* head, int data);

/* Pause Function */
void pause(void);

void main(){
    VirtualHeap VHeap1, VHeap2, VHeap3;
    CBList L1 = initCBList();
    CBList L2 = initCBList();
    CBList L3 = initCBList();
    
    initVH(&VHeap1);
    initVH(&VHeap2);
    initVH(&VHeap3);
    
    /* Insert Values Here */
    printf("Insertion at the start:\n\n");
    insertFirst(&VHeap1, &L1, 5);
    insertFirst(&VHeap1, &L1, 15);
    insertFirst(&VHeap1, &L1, 25);
    insertFirst(&VHeap1, &L1, 35);
    insertFirst(&VHeap1, &L1, 45);
    insertFirst(&VHeap1, &L1, 55); //Stop insertion
    display(VHeap1, L1);
    pause();
    
    printf("Insertion at the last:\n\n");
    insertLast(&VHeap2, &L2, 5);
    insertLast(&VHeap2, &L2, 15);
    insertLast(&VHeap2, &L2, 25);
    insertLast(&VHeap2, &L2, 35);
    insertLast(&VHeap2, &L2, 45);
    insertLast(&VHeap2, &L2, 55); //stops here
	display(VHeap2, L2);
    pause();
    
    printf("Insertion Sorted:\n\n");
    insertSorted(&VHeap3, &L3, 5);
    insertSorted(&VHeap3, &L3, 15);
    insertSorted(&VHeap3, &L3, 65);
    insertSorted(&VHeap3, &L3, 3);
    insertSorted(&VHeap3, &L3, 25);
    insertSorted(&VHeap3, &L3, 95); //stops here
    display(VHeap3, L3);
    pause();
    
    /* Deleting Values Here */ 
    printf("Delete First:\n\n");
    deleteFirst(&VHeap1, &L1);
    deleteFirst(&VHeap1, &L1);
    display(VHeap1, L1);
    pause();
    
	printf("Delete Last:\n\n");
    deleteLast(&VHeap2, &L2);
    deleteLast(&VHeap2, &L2);
    display(VHeap2, L2);
    pause();
}

void pause(void)
{
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void initVH(VirtualHeap* VH) {
    
    /* Version 2 */
    int i;
     for(i = MAX-1; i >= 0; i--){
         VH->elems[i].next = i-1; 
     }
     VH->avail = MAX-1;
    
    /* Version 1 */
//    for(i = 0; i < MAX-1; i++){
//        VH->elems[i].next = i+1;
//    }
//    VH->elems[i].next = -1;
//    VH->avail = 0;    
}

CBList initCBList(void) {
    CBList head = -1;
    return head;
}

int allocSpace(VirtualHeap* VH) {
    int retVal;
	// Get the avail and store it in a variable to make it as an index
    retVal = VH->avail;
    
    if(retVal != -1) {
    	// Update the avail as the next available node of the new index(retVal).
        VH->avail = VH->elems[retVal].next;
    }
    return retVal;
}

void deallocSpace(VirtualHeap* VH, int ndx){
	// Check if the passed index is a valid index (not -1 and not more than MAX)
	if(ndx >= 0 && ndx < MAX - 1){
		// Change the link of the node to be deleted to the current avail
		VH->elems[ndx].next = VH->avail;
		// Set the passed index as the new avail
		VH->avail = ndx;
	}
}

void display(VirtualHeap VH, CBList head) {
	CBList trav;
	for(trav = head; trav != -1; trav = VH.elems[trav].next) {
		printf("Element[%d] -> %d\n", trav, VH.elems[trav].data);
	}
}

/* Insertion Starts Here */
void insertFirst(VirtualHeap* VH, CBList* head, int data){
    CBList temp;
    temp = allocSpace(VH);
    
    if(temp != -1){
        VH->elems[temp].data = data;
        VH->elems[temp].next = *head;
        *head = temp;
    }
}

void insertLast(VirtualHeap* VH, CBList* head, int data){
    CBList *trav, temp;
    temp = allocSpace(VH);
    
    if(temp != -1) {
        for(trav = head; *trav != -1; trav = &VH->elems[*trav].next){}
        VH->elems[temp].data = data;
        VH->elems[temp].next = *trav;
        *trav = temp;
    }
}

void insertSorted(VirtualHeap* VH, CBList* head, int data){
    CBList *trav, temp;
    temp = allocSpace(VH);
    
    if(temp != -1) {
      for(trav = head; *trav != -1 && data > VH->elems[*trav].data; trav = &VH->elems[*trav].next){}
      VH->elems[temp].data = data;
      VH->elems[temp].next = *trav;
      *trav = temp;
    }
}

/* Deletion Starts Here */
void deleteFirst(VirtualHeap* VH, CBList* head){
	// Check if the List is not empty
	if(*head != -1) {
		CBList *trav, temp;
		// Point trav to the head of the List
		trav = head; 
		
		// Let temp point to the first node
		temp = *trav; // equivalent to temp = *head; dereference it to get the value of head
		// Change the link of head and set it to the next node
		*trav = VH->elems[temp].next;
		// Delete through deallocSpace()
		deallocSpace(VH, temp);
	} else {
		printf("List is empty\n");
	}	
}

void deleteLast(VirtualHeap* VH, CBList* head){
	// Check if the List is not empty
	if(*head != -1) {
		CBList *trav, temp; 
		// loop through the whole list and get the last node
		for(trav = head; VH->elems[*trav].next != -1; trav = &VH->elems[*trav].next){}
		
		// Let temp point to the first node
		temp = *trav; // equivalent to temp = *head; dereference it to get the value of head
		// Change the link of head and set it to the next node
		*trav = VH->elems[temp].next;
		// Delete through deallocSpace()
		deallocSpace(VH, temp);
	} else {
		printf("List is empty\n");
	}	
}
