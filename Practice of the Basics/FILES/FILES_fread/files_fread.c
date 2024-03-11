#include <stdio.h>
#include <string.h>

/* Things to remember 
	1. The 3rd parameter of the fwrite is used to know how many elements do you want to put in the file
	2. If you want to start at Nth, not in the first index of a structure or an array, just used pointer arithmetic operations or use addresses (i.e &nameArr[1] = arrName + 1)
	3. remember to use the format specifier "r" when using fread
*/
// int fread(void* dest, int size, int numElems, FILE* stream);

typedef struct{
	char fName[32];
	char mi;
	char lName[32];	
}nameType;

int main(void){
	nameType name;
	nameType nameArr[4];
	
	FILE* fptr;
	fptr = fopen("test.txt", "r");
	if(fptr != NULL){
//		fwrite(nameArr, sizeof(nameType), 4, fptr);
//		fread(&name, sizeof(nameType), 1, fptr); // when storing only one element
		fread(nameArr, sizeof(nameType), 4, fptr); // when storing only bulk elements (struct or array)
		printf("SUCCESS");
//		printf("\n%s", name.fName); // when printing only one element
		printf("\n\n%-7s", "First Names");
		printf("%25s", "Middle Initials");
		printf("%23s","Last Names");
		printf("\n%-7s%26s%25s", "----------","---------------", "--------------");
		int i;
		for(i = 0; i < 4; i++){
			printf("\n%-12s%17c%28s", nameArr[i].fName, nameArr[i].mi, nameArr[i].lName);
		}
	} else {
		printf("ERROR");
	}
}
