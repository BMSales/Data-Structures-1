#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	 _queue_info queue;
	queue.size = 0;
	queue.front = NULL;
	queue.rear = NULL;
	int numbers[5] = {1, 2, 3, 4, 5};
	void* data_pointer = NULL;

	for(int i = 0; i < 5; i++){
		data_pointer = &numbers[i];
		Insert(&queue, data_pointer);
		printf("Front: %d\n", *(int*)(queue.front)->data);
		printf("Rear: %d\n", *(int*)(queue.rear)->data);
		
	}

	for(int i = 0; i < 5; i++){
		printf("%d ", *(int*)Remove(&queue));
	}
	printf("\n");
}
