#include <stdio.h>
#include <string.h>

int main(void){
	FILE* fptr; // Declare a FILE pointer var
	fptr = fopen("test.txt", "r"); // fopen => to open the file with format specifiers
	if(fptr != NULL){
		puts("SUCCESS");
	} else {
		puts("ERROR");
	}
}
