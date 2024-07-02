#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	_list_info list;
	list.head = NULL;
	list.size = 0;
	int* user_nums;
	int array_size;
	void* data_pointer;

	printf("How many?\n");
	scanf("%d", &array_size);

	user_nums = (int*)malloc(array_size * sizeof(int));

	for(int i = 0; i < array_size; i++){
		printf("Insert: ");
		scanf("%d", &user_nums[i]);
	}

	for(int i = 0; i < array_size; i++){
		data_pointer = &user_nums[i];
		Insert(&list, data_pointer);
	}

	for(int i = 0; i < array_size; i++){
		printf("%d ", *(int*)Remove(&list));
	}
	printf("\n");
}
