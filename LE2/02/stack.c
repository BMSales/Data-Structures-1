#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Push(_stack_info* info, void* new_data){
	_stack* new_node;
	new_node = (_stack*)malloc(sizeof(_stack));

	info->size += 1;
	new_node->data = new_data;
	new_node->next = info->head;
	info->head = new_node;
}

void* Pop(_stack_info* info){
	if(info->head == NULL){
		return NULL;
	}

	void* data = (info->head)->data;
	_stack* popped_element = info->head;

	info->head = popped_element->next;
	info->size -= 1;

	free(popped_element);
	return data;
}

void* Top_Value(_stack_info* info){
	if(info->head == NULL){
		return NULL;
	}

	return (info->head)->data;
}

int Stack_Size(_stack_info* info){
	return info->size;
}
