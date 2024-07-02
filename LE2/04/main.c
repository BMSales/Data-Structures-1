#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

int main(){
	_queue_info queue;
	_queue test;
	queue.size = 0;
	queue.front = NULL;
	queue.rear = NULL;

	char string[] = "-+*9+28*+4863";
	void* data_pointer;

	for(int i = 0; string[i] != '\0'; i++){
		if(isdigit(string[i])){
			data_pointer = (int*)malloc(sizeof(int));
			*(int*)data_pointer = string[i] - '0';
			Insert(&queue, data_pointer, 1);
		}
		else{
			data_pointer = (char*)malloc(sizeof(char));
			*(char*)data_pointer = string[i];
			Insert(&queue, data_pointer, 2);
		}
	}

	printf("result: %d\n", Prefix_Run(&queue));
}
