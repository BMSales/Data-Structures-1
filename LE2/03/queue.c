#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Insert(_queue_info* info, void* new_data){
	_queue* new_node;
	new_node = (_queue*)malloc(sizeof(_queue));

	if(info->size == 0){
		info->size += 1;
		new_node->next = NULL;
		new_node->data = new_data;
		info->front = new_node;
		info->rear = new_node;
	}
	else{
		info->size += 1;
		new_node->next = info->rear;
		new_node->data = new_data;
		info->rear = new_node;
	}
}

void Remove(_queue_info* info){
	if(info->size == 0){
		return;
	}
	_queue* new_front;
	new_front = (info->front)->next;
	free(info->front);
	info->front = new_front;
}

void* Top_Value(_queue_info* info){
	if(info->head == NULL){
		return NULL;
	}

	return (info->head)->data;
}

int Stack_Size(_queue_info* info){
	return info->size;
}
