#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Insert(_queue_info* info, void* new_data, int data_type){
	_queue* new_node;
	new_node = (_queue*)malloc(sizeof(_queue));
	new_node->next = NULL;
	new_node->data = new_data;
	new_node->data_type = data_type;

	if(info->size == 0){
		info->front = new_node;
		info->rear = new_node;
	}
	else if(info->size == 1){
		(info->front)->next = new_node;
		info->rear = new_node;
	}
	else{
		(info->rear)->next = new_node;
		info->rear = new_node;
	}

	info->size += 1;
}

_queue Remove(_queue_info* info){
	_queue* new_front = (info->front)->next;
	_queue old_front = (*info->front);

	free(info->front);
	info->size -= 1;
	info->front = new_front;

	return old_front;
}

void* Front_Value(_queue_info* info){
	if(info->size == 0){
		return NULL;
	}

	return (info->front)->data;
}

int Queue_Size(_queue_info* info){
	return info->size;
}

void Prefix_Reinsert(_queue_info* info, _queue* nodes, int num_of_nodes){
	for(int i = 0; i < num_of_nodes; i++){
		Insert(info, nodes[i].data, nodes[i].data_type);
	}
}

void Prefix_Operation(_queue_info* info, _queue* nodes){
	char operator = *(char*)nodes[0].data;
	int operand_1 = *(int*)nodes[1].data;
	int operand_2 = *(int*)nodes[2].data;
	void* result = (int*)malloc(sizeof(int));

	printf("operator: %c\n", operator);
	printf("operand_1: %d\n", operand_1);
	printf("operand_2: %d\n", operand_2);

	switch(operator){
		case '+':
			*(int*)result = operand_1 + operand_2;
			Insert(info, result, 1);
			break;
		case '-':
			*(int*)result = operand_1 - operand_2;
			Insert(info, result, 1);
			break;
		case '*':
			*(int*)result = operand_1 * operand_2;
			Insert(info, result, 1);
			break;
	}
}

void Prefix_Check(_queue_info* info){
	_queue nodes[3];
	void* data_pointer;

	nodes[0] = Remove(info);

	if(nodes[0].data_type == 1){
		Prefix_Reinsert(info, nodes, 1);
		return;
	}

	for(int i = 1; i < 3; i++){
		if(info->front->data_type == 2){
			Prefix_Reinsert(info, nodes, i);
			return;
		}
		nodes[i] = Remove(info);
	}

	
	Prefix_Operation(info, nodes);
}

int Prefix_Run(_queue_info* info){
	while(info->size >= 3){
		Prefix_Check(info);
	}
	return *(int*)(info->front)->data;
}
