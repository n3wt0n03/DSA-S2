/* 02/2016 
This is collection of basic linked list codes written by Cris Lawrence Adrian G. Militante

The functions in this code assume that the linked list MAY have duplicate elements.
Make the necessary changes should there be any added limitations/restrictions based 
on the instructions*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node, *LL;

void initLL(LL*);
void insertSorted(LL*, int);
void insertFirst(LL*, int);
void insertLast(LL*, int);
int member(LL, int);
void deleteMem(LL*, int);
void deleteMany(LL*, int);
void display(LL);

int main(void)
{
	LL list;
	initLL(&list);	
	insertSorted(&list, 8);
	insertSorted(&list, 4);
	insertSorted(&list, 4);
	insertSorted(&list, 1);
	display(list);
	
	deleteMany(&list, 4);
	getch();
	system("CLS");
	display(list);
	
	
	return 0;
}

void initLL(LL* list)
{
	*list = NULL;
}

void insertSorted(LL* head, int data)
{
	/*Step 1: Declare temp and trav.*/
	LL temp, *trav;
		
	/*Step 2: Assign trav to head, and traverse the list until you find the right place for
		      insertion.*/
	for(trav = head; *trav != NULL && (*trav)->data <= data; trav = &(*trav)->next){}
	
	/*Step 3: Allocate memory for a node using temp. After which, check if the malloc succeeded.*/
	temp = (LL) malloc (sizeof(node));
	if(temp != NULL){
		
		/*Step 4: Assign the data of temp to be the data which is to be inserted, then insert the
				  new node.*/
		temp->data = data;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertLast(LL* head, int data)
{
	LL temp, *trav;
	
	for(trav = head; *trav != NULL; trav = &(*trav)->next){}
	temp = (LL) malloc (sizeof(node));
	if(temp != NULL){
		temp->data = data;
		temp->next = *trav;
		*trav = temp;
	}
}

void insertFirst(LL* head, int data)
{
	LL temp;
	
	temp = (LL) malloc (sizeof(node));
	if(temp != NULL){
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}	
}

int member(LL head, int data)
{
	LL trav;
	for(trav = head; trav != NULL && trav->data != data; trav = trav->next){}
	
	return trav != NULL ? 1 : 0;
}

void deleteMem(LL* head, int data)
{	
	/*Step 1: Declare temp and trav.*/
	LL temp, *trav;
	
	/*Step 2: Assign trav to head, and traverse the list until you find the node to delete
			  or you've reached the end of the list.*/
	for(trav = head; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
	
	/*Step 3: Check if you've reached the end of the list. If you haven't, then *trav is the node
			  to be deleted.*/
	if(*trav != NULL){
		/*Step 4: Delete the node*/
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}else{
		printf("\nItem does not belong in the list");
	}
}


void deleteMany(LL* head, int data)
{
	LL temp, *trav;
	for(trav = head; *trav != NULL;){
		if((*trav)->data == data){
			temp = *trav;
			*trav = temp->next;
			free(temp);
		}else{
			trav = &(*trav)->next;
		}
	}
	
	
}

void display(LL head)
{
	system("CLS");
	printf("The Linked List Contains the ff: values:\n");
	for(;head != NULL; head = head->next){
		printf("%d, ", head->data);
	}
}
