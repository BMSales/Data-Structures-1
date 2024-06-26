#include <stdlib.h>
#include "queue.h"

void Insert(_queue_info* info, void* new_data){
	_queue* new_node;
	new_node = (_queue*)malloc(sizeof(_queue));
	new_node->next = NULL;
	new_node->data = new_data;

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

void* Remove(_queue_info* info){
	if(info->size == 0){
		return NULL;
	}
	_queue* new_front = (info->front)->next;
	void* data = (info->front)->data;

	free(info->front);
	info->size -= 1;
	info->front = new_front;

	return data;
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
