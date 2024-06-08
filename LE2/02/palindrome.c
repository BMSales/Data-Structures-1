#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "palindrome.h"

int String_Length(char* string){
	int i = 0;
	while(1){
		if(string[i] == '\n' || string[i] == '\0'){
			return i;
		}
		i++;
	}
	return i + 1;
}

char* String_Clean(char* dirty_string){
	int size = String_Length(dirty_string);
	int j = 0;
	char* clean_string = (char*)malloc(size * sizeof(char));
	char* return_string;
		for(int i = 0; i < size; i++){
		if(!ispunct(dirty_string[i]) && dirty_string[i] != ' '){
			if(dirty_string[i] >= 65 && dirty_string[i] <= 90){
				clean_string[j] = dirty_string[i] + 32;
				j++;
			}
			else if(dirty_string[i] != '\0'){
				clean_string[j] = dirty_string[i];
				j++;
			}
		}
	}

	return_string = (char*)malloc(j * sizeof(char));

	for(int i = 0; i < j; i++){
		return_string[i] = clean_string[i];
	}
	
	free(clean_string);
	return return_string;
}

int Is_Palindrome(char* string, int size){
	int j = size - 1;
	for(int i = 0; i <= j; i++){
		if(string[i] != string[j]){
			return 0;
		}
		else{
			j--;
		}
	}
	return 1;
}
