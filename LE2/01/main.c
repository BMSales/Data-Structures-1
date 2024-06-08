#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	_stack_info info;
	info.size = 0;
	info.head = NULL;
	int numbers[5] = {1, 2, 3, 4, 5};
	void* pointer = NULL;

	for(int i = 0; i < 5; i++){
		printf("%d ", numbers[i]);
		pointer = &numbers[i];
		Push(&info, pointer);
	}
	printf("\n");

	while(info.head != NULL){
		printf("%d ", *(int*)Pop(&info));
	}
	printf("\n");
}
