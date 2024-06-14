#include <stdlib.h>
#include "queue.h"

void Insert_1(_queue_info* info, void* new_data){
	_queue* new_node;
	new_node = (_queue*)malloc(sizeof(_queue));
	new_node->next = NULL;
	new_node->data = new_data;

	if(info->size_1 == 0){
		info->front_1 = new_node;
		info->rear_1 = new_node;
	}
	else if(info->size_1 == 1){
		(info->front_1)->next = new_node;
		info->rear_1 = new_node;
	}
	else{
		(info->rear_1)->next = new_node;
		info->rear_1 = new_node;
	}

	info->size_1 += 1;
}

void Insert_2(_queue_info* info, void* new_data){
	_queue* new_node;
	new_node = (_queue*)malloc(sizeof(_queue));
	new_node->next = NULL;
	new_node->data = new_data;

	if(info->size_2 == 0){
		info->front_2 = new_node;
		info->rear_2 = new_node;
	}
	else if(info->size_2 == 1){
		(info->front_2)->next = new_node;
		info->rear_2 = new_node;
	}
	else{
		(info->rear_2)->next = new_node;
		info->rear_2 = new_node;
	}

	info->size_2 += 1;
}

void* Remove_1(_queue_info* info){
	if(info->size_1 == 0){
		return NULL;
	}
	_queue* new_front = (info->front_1)->next;
	void* data = (info->front_1)->data;

	free(info->front_1);
	info->size_1 -= 1;
	info->front_1 = new_front;

	return data;
}

void* Remove_2(_queue_info* info){
	if(info->size_2 == 0){
		return NULL;
	}
	_queue* new_front = (info->front_2)->next;
	void* data = (info->front_2)->data;

	free(info->front_2);
	info->size_2 -= 1;
	info->front_2 = new_front;

	return data;
}
