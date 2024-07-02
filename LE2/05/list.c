#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void Insert(_list_info* info, void* new_data){
	_list* new_node;
	_list* loop_node = info->head;
	new_node = (_list*)malloc(sizeof(_list));
	
	new_node->data = new_data;
	info->size += 1;

	if(info->size == 1){
		new_node->next = info->head;
		info->head = new_node;
		return;
	}

	if(*(int*)new_node->data <= *(int*)(info->head)->data){
		new_node->next = info->head;
		info->head = new_node;
		return;
	}

	while(loop_node != NULL){
		if(loop_node->next == NULL){
			new_node->next = NULL;
			loop_node->next = new_node;
			return;
		}
		if(*(int*)new_node->data <= *(int*)loop_node->next->data){
			new_node->next = loop_node->next;
			loop_node->next = new_node;
			return;
		}
		loop_node = loop_node->next;
	}
}

void* Remove(_list_info* info){
	_list* removed = info->head;
	void* data = removed->data;

	info->head = info->head->next;
	free(removed);

	return data;
}
