#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"
#include "stack.h"

int main(){
	_stack_info stack;
	stack.size = 0;
	stack.head = NULL;
	void* data_pointer;

	char raw_string[] = "A base do teto desaba.";
	char* formatted_string = String_Clean(raw_string);

	int size_raw = String_Length(raw_string);
	int size_formatted = String_Length(formatted_string);

	char* inverted_string = (char*)malloc(size_formatted * sizeof(char));

	for(int i = 0; i < size_raw; i++){
		printf("%c ", raw_string[i]);
	}
	printf("\n");

	for(int i = 0; i < size_formatted; i++){
		data_pointer = &formatted_string[i];
		Push(&stack, data_pointer);
	}

	for(int i = 0; i < size_formatted; i++){
		inverted_string[i] = *(char*)Pop(&stack);
	}

	for(int i = 0; i < size_formatted; i++){
		if(inverted_string[i] != formatted_string[i]){
			printf("Not a palindrome\n");
			return 0;
		}
	}

	printf("Is a palindrome\n");
	return 0;
}
