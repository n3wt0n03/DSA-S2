#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
 
typedef enum {VACANT, OCCUPIED, DAMAGED} state;
 
typedef struct{
    char idNumber[9];
    char fName[32];
    char lName[32];
}studentRecord;
 
typedef struct{
    studentRecord currentUser;
    char lastUser[9]; //ID Number of the last student who used the PC.
    int pcNumber;
    state pcState;
}pcRecord;
 
typedef struct{
    pcRecord PC[30];
    int count;    //refers to the total number of desktops
    int occupied; //refers to the number of occupied desktops
}pcList;

/*Codes have already been provided for these functions*/
char* displayState(state S);
void displayPCRecords(pcRecord PCList[]);
void displayPCList(pcList desktops);

/*Problem 1*/
void initPCList(pcList* desktops, int numPCs);
void populatePCList(pcList* desktops);

/*Problem 2*/
void usePC(pcList* desktops, int pcNumber, studentRecord SR);

/*Problem 3*/
void vacatePC(pcList* desktops, int pcNumber);

/*Problem 4*/
pcList genPCListOccupied(pcList desktops);

/*Problem 5*/
void reportDamagedPC(pcList* desktops, studentRecord SR);
pcRecord* removeDamagedPCs(pcList* desktops);

int main(void) {
    pcList LB445;
    int numPCLB = 5;
    
    /*Problem 1*/
    //call initPCList() passing LB445 as the parameter. Initialize the list to have only 5 computers.
    //call populatePCList() passing LB445 as the parameter.
    //call displayPCList() passing LB445 as the parameter.
    
    initPCList(&LB445, numPCLB);
	populatePCList(&LB445);
	displayPCList(LB445);
	getch();
	system("CLS");

   
    /*Problem 2*/
    //Initialize a studentRecord stud1 with the values 14101941, Cris, Militante.
    //Call usePC() passing LB445, pcNumber 8, and stud1 as the parameters. This is to check if your code works for a pcNumber that doesn't exist.
    //Call usePC() passing LB445, pcNumber 3, and stud1 as the parameters.
    //call displayPCList() passing LB445 as the parameter.
    
    studentRecord stud1 = {"14101941", "Cris", "Militante"};
    usePC(&LB445, 8, stud1); // Check if it exists
    usePC(&LB445, 3, stud1);
    displayPCList(LB445);
    getch();
	system("CLS");
    
    

   
    /*Problem 3*/
    //Call vacatePC() passing LB445 and pcNumber 3 as the parameter.
    //Call displayPCList() passing LB445 as the parameter.
    //Initialize a studentRecord stud2 with the values 14101943, Gabby, Pineda.
    //Call usePC() passing LB445, pcNumber 3, and stud2 as the parameters.
    //Call displayPCList() passing LB445 as the parameter.
    //Initialize a studentRecord stud3 with the values 14101945, Patty, Woo.
    //Call usePC() passing LB445, pcNumber 3, and stud3 as the parameters.
    //Call displayPCList() passing LB445 as the parameter.
    
    void vacatePC(pcList* desktops, int pcNumber);
    vacatePC(&LB445, 3);
    displayPCList(LB445);
    printf("\n\n Click 'Enter' to proceed to next Problem 3 Use Case\n\n");
    getch();
	system("CLS");
    
    studentRecord stud2 = {"14101943", "Gabby", "Pineda"};
  	usePC(&LB445, 3, stud2);
  	displayPCList(LB445);
  	printf("\n\n Click 'Enter' to proceed to last Problem 3 Use Case \n\n");
    getch();
	system("CLS");
	
	studentRecord stud3 = {"14101945", "Patty", "Woo"};
  	usePC(&LB445, 3, stud3);
  	displayPCList(LB445);
    getch();
	system("CLS");

   
    /*Problem 4*/
    //Initialize a new pcList occLB445 using genPCListOccupied().
    //Call displayPCList() passing LB445 as the parameter.
   	pcList occLB445 = genPCListOccupied(LB445);
   	displayPCList(occLB445);
   	getch();
	system("CLS");
    

   
    /*Problem 5*/
    //Call reportDamagedPC() passing LB445, and stud3 as the parameters.
    //Call reportDamagedPC() passing LB445, and stud3 as the parameters.
    //Call displayPCList() passing LB445 as the parameter.
    //Initialize a new array of pcRecords using removeDamagedPCs().
    //Call displayPCList() passing LB445 as the parameter.
    //Call displayPCRecords() passing damagedPCs as the parameter.
	
	reportDamagedPC(&LB445, stud3);
    displayPCList(LB445);
    printf("\n\n Click 'Enter' to proceed to next Problem 5 Use Case\n\n");
    getch();
	system("CLS");
	
	//why *newRec? It's because the function header is a pointer -> clarify to sir if theory is correct
	pcRecord *newRec = removeDamagedPCs(&LB445);
	displayPCList(LB445);
	printf("\n\n Click 'Enter' to proceed to last Problem 5 Use Case\n\n");
    getch();
	system("CLS");
	
	displayPCRecords(newRec);
	
	
    

   
    return 0;
}


/*Code for function displayState() has already been provided*/
char* displayState(state S)
{
    char* stateDescription = NULL;
    char buffer[64];
    switch(S){
        case 0:
            strcpy(buffer, "VACANT");
            break;
        case 1:
            strcpy(buffer, "OCCUPIED");
            break;
        case 2:
            strcpy(buffer, "DAMAGED");
            break;
        default:
            strcpy(buffer, "Error Occured");
    }
   
    stateDescription = (char*) malloc (sizeof(strlen(buffer) + 1));
    if(stateDescription != NULL){
        strcpy(stateDescription, buffer);
    }
    return stateDescription;
}

/* Write the code for the function initPCList(). This function will receive a pcList,
   and the inital number of PCs. The function will initialize the arrayList of desktops to have its
   proper count and occupied values based on the parameters.
 */
void initPCList(pcList* desktops, int numPCs)
{
	desktops->count = numPCs;
	desktops->occupied = 0;
}
 
/* Write the code for the function populatePCList(). This function will receive a pcList. The function
   will populate the pcList with default values for each PC. The default studentRecord will contain strings
   containing "XXX" for both names, and "XXXXXXXX" for the idNumber. Initialize the other structure elements
   with values that make sense. CLUE: Look at the structure of the pcRecord and think of the values that should
   be populated to those fields when a PC is initially empty.
 */
void populatePCList(pcList* desktops)
{
	if(desktops->count <= 5) {
		int i;
		for(i = 0; i < 5; i++) {
			desktops->PC[i].pcNumber = i; // index 0 = PC Number 1
			desktops->PC[i].pcState = 0;
			strcpy(desktops->PC[i].currentUser.fName, "XXXXXXXX");
			strcpy(desktops->PC[i].currentUser.lName, "XXXXXXXX");
			strcpy(desktops->PC[i].currentUser.idNumber, "XXXXXXXX");
			strcpy(desktops->PC[i].lastUser, "XXXXXXXX");
		}
	}
}

/* Code for the function displayPCList() is partially given.*/
void displayPCList(pcList desktops)
{
	int i;
    for(i = 0; i < desktops.count; i++){
        printf("PC[%d]\nState: %s\nCurrent User: %s, \nLast User: %s\n\n", 
		i, displayState(desktops.PC[i].pcState), 
		desktops.PC[i].currentUser.idNumber, 
		desktops.PC[i].lastUser);
    }
    printf("Occupancy Rate: %d/%d\n\n", desktops.occupied, desktops.count);
}
 
/* Write the code for the function usePC(). The function will receive a pcList, a pcNumber, and a studentRecord.
   The function will simulate the process of a student who wants to use the given pcNumber. The function will check
   for the following:
    1) If the pcNumber is a valid pcNumber (meaning, if there are only 5 PCs, only pcNumber 0-4 are valid.
    2) If there are still PCs that are unnoccupied.
    3) If the pcNumber that the student has selected is VACANT.
        If it is, then assign that PC to the student by setting the student's records in the pcList.
        If it isn't, then look for the nearest available PC that can be used (forward search).
        
 */
void usePC(pcList* desktops, int pcNumber, studentRecord SR)
{
    if (pcNumber < desktops->count ) {
		if(desktops->occupied < 5){
			if(desktops->PC[pcNumber].pcState != OCCUPIED && desktops->PC[pcNumber].pcState != DAMAGED){		
				desktops->PC[pcNumber].pcNumber = pcNumber;	
				desktops->PC[pcNumber].currentUser = SR;
				desktops->PC[pcNumber].pcState = 1;
				desktops->occupied++;	
			} else {
				int i;
				for(i = pcNumber; i < desktops->count && desktops->PC[i].pcState != VACANT; i++){}		
				desktops->PC[i].pcNumber = pcNumber;
				desktops->PC[i].currentUser = SR;
				desktops->PC[i].pcState = 1;
				desktops->occupied++;
			}
		} else {
			printf("There is no available PCs. Please come back in another time.\n");
		}
	} else {
		printf("Please input a valid PC number from 0 - 5\n");
	}
}
 

/* Write the code for the function vacatePC(). The function will receive a pcList and a pcNumber as parameters.
   The function will remove the student student from the passed pcNumber from the pcList, and revert the values
   to their defaults EXCEPT for the lastUser member. Update values where it makes sense.
 */
void vacatePC(pcList* desktops, int pcNumber)
{
	int i;
    for(i = 0; i < desktops->count; i++){
		if(desktops->PC[i].pcNumber == pcNumber){
			strcpy(desktops->PC[i].lastUser, desktops->PC[i].currentUser.idNumber);
			desktops->PC[i].pcNumber = i; // index 0 = PC Number 1
			desktops->PC[i].pcState = 0;
			strcpy(desktops->PC[i].currentUser.fName, "XXXXXXXX");
			strcpy(desktops->PC[i].currentUser.lName, "XXXXXXXX");
			strcpy(desktops->PC[i].currentUser.idNumber, "XXXXXXXX");
//			desktops->occupied--; results to -1, why?
		}
    }
    desktops->occupied--;
}
 
/* Write the code for the function reportDamagedPC(). This function will receive a pcList and a studentRecord.
   The function will go through the pcList and check if the pass studentRecord is currently using a PC. If they are,
   then update the state of the PC they are using as damaged, and assign them the next available PC from PC 0.
   CLUE: You are allowed to use functions that have already been coded.
 */
void reportDamagedPC(pcList* desktops, studentRecord SR)
{	
	int i;
	for(i = 0; i < desktops->count; i++){
		if(strcmp(desktops->PC[i].currentUser.idNumber, SR.idNumber) == 0 && desktops->PC[i].pcState == OCCUPIED){
			desktops->PC[i].pcState = 2;
			desktops->occupied--;
			usePC(desktops, 0, SR);
		}
	}
}

/* Write the code for the function genPCListOccupied(). The function will receive a pcList. The function will go
   through the passed pcList and return a new pcList containing only the OCCUPIED PCs. Do not remove the occupied
   PCs from the original list.
 */
pcList genPCListOccupied(pcList desktops)
{
	pcList retOccPC;
	retOccPC.count = 0;
	retOccPC.occupied = 0;
	
	int i;
	for(i = 0; i < desktops.count; i++) {
		if(desktops.PC[i].pcState == OCCUPIED) {
			retOccPC.PC[retOccPC.count] = desktops.PC[i];
			retOccPC.count++;
			retOccPC.occupied++;
		}
	}
	return retOccPC;
}

/* Write the code for the function removeDamagedPCs(). The function will receive a pcList. The function will go
   through the given pcList and return an array of pcRecords that contain all the DAMAGED PCs from the pcList.
   After the last used index of the array of the pcRecords, Let it contain a sentinel value containing "00000000", END, END, END,
   -1, VACANT. This function also deletes the damaged PCs from the original list.
 */
pcRecord* removeDamagedPCs(pcList* desktops)
{
	pcRecord sentinel = {{"00000000", "END", "END"}, "END", -1, VACANT};
	pcRecord tempArr[desktops->count];
	int i;
	int j;
	int damageCount = 0;
	for(i = 0; i < desktops->count;){
		if(desktops->PC[i].pcState == DAMAGED) {
			tempArr[damageCount] = desktops->PC[i];
			damageCount++;
			for(j = i; j < desktops->count - 1; j++){ //shift elements to the left to delete
				desktops->PC[j] = desktops->PC[j+1];
			}
			desktops->count--;
		} else {
			i++;	
		}
	}
	
	//Create an array to be returned using malloc
	pcRecord *retArr = (pcRecord*) malloc (sizeof(pcRecord)*(damageCount + 1));
	if(retArr!= NULL){
		//transfer the contents from tempArr to retArr
		for(i = 0; i < damageCount; i++){
			retArr[i] = tempArr[i];
		}  
		retArr[i] = sentinel;
	} else {
		printf("Memory allocation not successful.");
	}

	return retArr;
}
 
/* Code for the function displayPCRecords() is partially given.*/
void displayPCRecords(pcRecord PCList[])
{
    int i;
    for(i = 0; i < PCList[i].pcNumber; i++){
  		printf("PC[%d]\nState: %s\nCurrent User: %s, \nLast User: %s\n\n", PCList[i].pcNumber, displayState(PCList[i].pcState), PCList[i].currentUser.idNumber, PCList[i].lastUser);
    }
}
 
