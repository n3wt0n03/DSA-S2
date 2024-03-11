#include <stdio.h>
#include <string.h>

// int fwrite(void* ptr, int size, int numElems, FILE* stream);

int main(void){
//	char letter = 'N';
//	char arrChar[] = "LET'S PASS DSA!!"; 
//	
//	FILE* fptr;
//	fptr = fopen("test.txt", "w");
//	if(fptr != NULL){
////		fwrite(&letter, sizeof(char), 1, fptr);
//		fwrite(arrChar, sizeof(char), sizeof(arrChar), fptr);
//		printf("SUCCESS");
//	} else {
//		printf("ERROR");
//	}
//	fclose(fptr);
	
	int x = 65; // stores letter 'A' from ASCII
	int arrInt[5] = {65, 66, 67, 68, 69};
	
	FILE* fptr2;
	fptr2 = fopen("testInt.txt", "w");
	if(fptr2 != NULL){
//		fwrite(&x, sizeof(int), sizeof(x), fptr2);
		fwrite(arrInt, sizeof(int), sizeof(arrInt), fptr2);
		printf("\nSUCCESS");
	} else {
		printf("\nERROR");
	}
}
