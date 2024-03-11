#include <stdio.h>
#include <string.h>

/* Things to remember 
	1. The 3rd parameter of the fwrite is used to know how many elements do you want to put in the file
	2. If you want to start at Nth, not in the first index of a structure or an array, just used pointer arithmetic operations or use addresses (i.e &nameArr[1] = arrName + 1)
*/

typedef struct{
	char fName[32];
	char mi;
	char lName[32];	
}nameType;

int main(void){
	nameType name = {"Marc Nelson", 'B', "Ochavo"};
	nameType nameArr[4] = {{"Marc Nelson", 'B', "Ochavo"},
						   {"Maricar", 'B', "Ochavo"},
						   {"Nelson", 'M', "Ochavo"},
						   {"Nicole", 'B', "Ochavo"},
						  };
	
	FILE* fptr;
	fptr = fopen("test.txt", "w");
	if(fptr != NULL){
//		fwrite(nameArr, sizeof(nameType), 4, fptr);
		fwrite(&nameArr[1], sizeof(nameType), 3, fptr);
		printf("SUCCESS");
	} else {
		printf("ERROR");
	}
}
