/******************************************************************
 * Project Name:  List, Set and Dictionary                        *
 * Programmer  : Marc Nelson B. Ochavo                            *
 * Date Completed: March 25, 2023                                 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE     0XC    //size of Virtual Heap
#define OPEN_DSIZE  0XA    //size of Open Hash Table
#define CLOSE_DSIZE 0XC    //size of Close Hash Table
#define LIST_SIZE   0XF    //size of the array implementation of List
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; EMPTY or DELETED   
  	chocoDesc prodDesc;     //  product description 
 	float prodPrice;        //  product price 
  	int prodQty;            //  product count or quantity   
}product;                   //  product record  

typedef struct {
	product elem;            
	int next;                
}prodNode;                 // Product node, used in cursor-based implementation of Set  


/************************
 * Virtual Heap         *
 ************************/
typedef struct {
   prodNode VH_node[VH_SIZE];
   int avail;
}VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
   int elemIndex;        // index of the 1st element in the set  
   int count;            // holds the actual number of elements in the set  
   VHeap *VHptr;         // holds the pointer to the virtual heap  
}cursorSet;            

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
	int header[OPEN_DSIZE];  // array of sets   
	int count;               // total number of elements in the dictionary  
	VHeap *dicVHptr;         // holds the pointer to the virtual heap  
}openDic;


/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY   "empty"     // stored in product ID field  
#define DELETED  "del"      // stored in product ID field * 
 
typedef product closeDic[CLOSE_DSIZE];   //Definition of the closed hash dictionary
  
typedef struct {
	product prod[LIST_SIZE];
	int last;   //index of the last element; -1 if list is empty	
}List;



/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);                
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic * convertToCloseDict(openDic *D);	
void displayCloseDict(closeDic CD);


 
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
 int main( ) 
 {	
 /*---------------------------------------------------------------------------------
 * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set             *
 *                 2) Displays the contents  virtual heap and cursor Set          *
 *--------------------------------------------------------------------------------*/
 	printf("\n\n\nProblem #1:: "); 
 	printf("\n------------");
 	//Declare variables needed for Problem #1
 	 VHeap VH;
 	 cursorSet S;
	
 	//Function Calls for Problem #1
	 initVHeap(&VH);
	 S = initCursorSet(&VH);
	 displayVHeap(VH);
	 displaySet(S);

/*---------------------------------------------------------------------------------
 * 	Problem #2 ::  1) Populates the Cursor set which is sorted in ascending order *
 *                    according to ID                                             *
 *                 2) Displays the Cursor set                                     * 
 *--------------------------------------------------------------------------------*/	 
 	printf("\n\n\nProblem #2:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #2
	

 	//Function Calls for Problem #2
	populateSet(&S);
	displaySet(S);

/*---------------------------------------------------------------------------------
 * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary        *      
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the empty Cursor set.                              * 
 *--------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #3:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #3
	openDic D;  
	
	//Function Calls for Problem #3
	D = convertToOpenDict(&S);
	displayOpenDict(D);
	displaySet(S);

/*---------------------------------------------------------------------------------
 * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash Dictionary     *
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the Virtual Heap                                   * 
 *--------------------------------------------------------------------------------*/	
 	printf("\n\n\nProblem #4:: "); 
	printf("\n------------");	
	//Declare variables needed for Problem #4
    char delete01[] = "1703";
	char delete02[] = "1358";
	char delete03[] = "1601";
	
 
	//Function Calls for Problem #4	    
    deleteDict(&D, delete01);
	deleteDict(&D, delete02);
	deleteDict(&D, delete03);
	displayOpenDict(D);
	displayVHeap(VH);
    

/*------------------------------------------------------------------------------------
 * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash Dictionary *
 *                2) Displays the Closed Hash Dictionary                             * 
 *                3) Displays the virtual heap                                       *
 *---------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #5:: ");
    printf("\n------------");
    //Declare variables needed for Problem #5

    
    //Function Calls for Problem #5

	

	return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
 void initVHeap(VHeap *V)
 {
 	int i, lastNdx = VH_SIZE-1;
 	for(i = lastNdx; i >= 0; i--){
 		strcpy(V->VH_node[i+1].elem.prodID, " ");
 		V->VH_node[i].next = i-1;
	}
	V->avail = lastNdx; 
 }

cursorSet initCursorSet(VHeap *VH)
{
	cursorSet S;
	S.elemIndex = -1; // head of the Cursor-Based Set
	S.count = 0; // Number of Elements inside the Virtual Heap
	S.VHptr = VH; // Address of the Virtual Heap
	return S;
}

void displayVHeap(VHeap V)
{
	//Variable Declaration here

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", V.avail);       //Complete this statement
	printf("\nVHeap Address    ::  %d" , &V.VH_node);       //Complete this statemet
	
    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "Next Field");
	printf("\n%10s%10s%15s", "-----", "-------","----------");	
     
    //Write your code here 
	int i;
	for(i = 0; i < VH_SIZE; i++){
		printf("\n%8d%10s%12d", i, V.VH_node[i].elem.prodID, V.VH_node[i].next);
	}

	printf("\n\n"); system("Pause");
}

void displaySet(cursorSet A)
{
	printf("\n\nDetails of the Set :: ");
	printf("\n---------------------");
	printf("\nNo. of elements ::  %d", A.count);      //Complete this code
	printf("\n\n%-7s", "ID");
	printf("%-12s","Choco Name");
	printf("%-15s","Choco Weight");
	printf("%-10s","VHeap Index");
	printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------", "-----------");

	//Write your code here
	int trav;
	for(trav = A.elemIndex; trav != -1; trav = A.VHptr->VH_node[trav].next){
		printf("\n%-8s%-15s%-15d%-15d", A.VHptr->VH_node[trav].elem.prodID, A.VHptr->VH_node[trav].elem.prodDesc.name, A.VHptr->VH_node[trav].elem.prodDesc.weight, trav);
	}
	 

	printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH)
{
	int retVal = VH->avail;
	
	if(retVal != -1){
		VH->avail = VH->VH_node[retVal].next;
	}
	
	return retVal;
}


void insertSorted(cursorSet *A, product P)
{
	int *trav, temp;	
	
	// Check if count doesn't exceed the size of the heap
	if(A->count < VH_SIZE){
		for(trav = &A->elemIndex; *trav != -1 && strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) < 0; trav = &A->VHptr->VH_node[*trav].next){}
		//check if its unique
		if(strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) != 0){
			temp = mallocInVHeap(A->VHptr);
			if(temp != -1){
				A->VHptr->VH_node[temp].elem = P;
				A->VHptr->VH_node[temp].next = *trav;
				*trav = temp;
				A->count++;
			} 
		} else {
			printf("\nProduct with ID: [%s] already exists in the set", P.prodID);
		}
	} else {
		printf("\nNo available space. Product with ID: [%s] cannot be inserted", P.prodID);	
	}
}

void populateSet(cursorSet *A)
{
	const int COUNT = 15;
	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20},
						{"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35},
						{"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20},
						{"1201", {"Kitkat", 50}, 97.75, 40},
						{"1450", {"Ferrero", 100},150.50, 50},
						{"1701", {"Toblerone", 50}, 90.75, 80},
						{"1601", {"Meiji", 75}, 75.50, 60},
						{"1310", {"Nestle", 100}, 124.50, 70},
						{"1807", {"Valor", 120}, 149.50, 90},
						{"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60},
						{"1284", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35},
					
		              };
    //Inserts each element of the array to the cursor set
    //Write your code here!!
    
    int i;
    for(i = 0; i < COUNT; i++){
    	insertSorted(A, data[i]);
	}
}



/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char * prodID)               
{ 
	int i;
	int sum = 0;
	for(i = 0; prodID[i] != '\0'; i++){
		if(prodID[i] >= '0' && prodID[i] <= '9'){
			sum += (prodID[i] - '0');
		}
	}
	return sum % OPEN_DSIZE;
}


openDic initOpenDict(VHeap *VH)
{
	openDic D;
	int i;
	for(i = 0; i < OPEN_DSIZE; i++){
		D.header[i] = -1;
	}
	D.count = 0;
	D.dicVHptr = VH;
	return D;
}

openDic convertToOpenDict(cursorSet *A)
{
	openDic D = initOpenDict(A->VHptr);
	
	int i, *trav;
	for(i = 0; i < VH_SIZE; i++){
		int ndx = openHash(A->VHptr->VH_node[i].elem.prodID);
		for(trav = &D.header[ndx]; *trav != -1 && strcmp(A->VHptr->VH_node[*trav].elem.prodID, A->VHptr->VH_node[i].elem.prodID) < 0; trav = &D.dicVHptr->VH_node[*trav].next){}
		
		if(*trav != -1 || strcmp(A->VHptr->VH_node[*trav].elem.prodID, A->VHptr->VH_node[i].elem.prodID) != 0){
			A->VHptr->VH_node[i].next = *trav;	
			*trav = i;
			D.count++;
			A->count--;
		}
		A->elemIndex = -1;
	}
	return D;		 
}



void displayOpenDict(openDic D)
{
	//Variable declaration here 
	
	printf("\n\nDetails of the Open Hash Dictionary:: ");
	printf("\n-------------------------------------");
	
	printf("\nNo. of elements :: %d", D.count);
	printf("\n\n%-7s", "GROUPS");
	printf("%15s","ID Numbers");
	printf("\n%-7s%15s", "------","----------");
	
	//Write your code here
	int i;
	int trav;
	for(i = 0; i < OPEN_DSIZE; i++){
		printf("\nGroup[%d] :: ", i);
		for(trav = D.header[i]; trav != -1; trav = D.dicVHptr->VH_node[trav].next){
			printf("%-7s", D.dicVHptr->VH_node[trav].elem.prodID);
		}
	}
	

    printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx)
{
	if(ndx > 0 && ndx < VH_SIZE){
		strcpy(VH->VH_node[ndx].elem.prodID, " ");
		VH->VH_node[ndx].next = VH->avail;
		VH->avail = ndx;
	}	 
}

void deleteDict(openDic *D, char *IDen)
{
	int ndx = openHash(IDen);
	int *trav, temp;
	for(trav = &D->header[ndx]; *trav != -1 && strcmp(D->dicVHptr->VH_node[*trav].elem.prodID, IDen) != 0; trav = &D->dicVHptr->VH_node[*trav].next){}
	if(strcmp(D->dicVHptr->VH_node[*trav].elem.prodID, IDen) == 0){
		temp = *trav;
		*trav = D->dicVHptr->VH_node[temp].next;
		freeInVHeap(D->dicVHptr, temp);
		D->count--;
		printf("\nProduct with ID: [%s] is successfully deleted", IDen); 
	} else {
		printf("\nProduct with ID: [%s] is not in the dictionary", IDen);
	}
}


 /************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID)
{
     
}



void initCloseDict(closeDic CD)
{
	 

}
 
closeDic * convertToCloseDict(openDic *D)
{
    
}	

void displayCloseDict(closeDic CD)
{
 	//Variable declaration here
 	
 	
	printf("\n\nDetails of Closed Hash Dictionary :: ");
	printf("\n-------------------------------------");
	printf("\n\n%-6s", "Index");
	printf("%-10s", "ChocoID");
	printf("%-15s", "Choco Name");
	printf("\n%-6s%-10s%-15s", "-----", "-------", "----------"); 
	
	//Write your code here
	 
	
	printf("\n\n"); system("Pause");
 
}
 