#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"

void Insert(_list_info* info, int coefficient, int exponent){
	_list* new_node;
	_list* loop_node = info->head;
	new_node = (_list*)malloc(sizeof(_list));
	
	new_node->coefficient = coefficient;
	new_node->exponent = exponent;
	info->size += 1;

	if(info->size == 1){
		new_node->next = info->head;
		info->head = new_node;
		return;
	}

	if(new_node->exponent > (info->head)->exponent){
		new_node->next = info->head;
		info->head = new_node;
		return;
	}

	if(new_node->exponent == (info->head)->exponent){
		(info->head)->coefficient += new_node->coefficient;
		free(new_node);
		info->size -= 1;
		return;
	}

	while(loop_node != NULL){
		if(loop_node->next == NULL){
			new_node->next = NULL;
			loop_node->next = new_node;
			return;
		}
		if(new_node->exponent > loop_node->next->exponent){
			new_node->next = loop_node->next;
			loop_node->next = new_node;
			return;
		}
		if(new_node->exponent == loop_node->next->exponent){
			loop_node->next->coefficient += new_node->coefficient; 
			free(new_node);
			info->size -= 1;
			return;
		}
		loop_node = loop_node->next;
	}
}

_list Remove(_list_info* info){
	_list removed = (*info->head);
	_list* new_head = info->head->next;

	free(info->head);
	info->head = new_head;
	info->size -= 1;

	return removed;
}

void Parser(_list_info* info, char* polynomial, int size){
	int coefficient = 1;
	int exponent = 1;
	int operator_sign = 1;
	int mode = 1;

	for(int i = 0; i <= size; i++){
		if(polynomial[i] == '^'){
			continue;
		}

		if(polynomial[i] == '-'){
			operator_sign = -1;
		}
		else if(polynomial[i] == '+'){
			operator_sign = 1;
		}

		if(mode == 1){
			if(isdigit(polynomial[i])){
				coefficient = polynomial[i] - '0';
				coefficient *= operator_sign;
				mode = 2;
				continue;
			}
			else if(polynomial[i] == 'x'){
				coefficient *= operator_sign;
				mode = 3;
				continue;
			}
			else{
				continue;
			}
		}

		if(mode == 2){
			if(polynomial[i] == 'x'){
				mode = 3;
				continue;
			}
			else{
				exponent = 0;
				Insert(info, coefficient, exponent);
				mode = 1;
				continue;
			}
		}

		if(mode == 3){
			if(isdigit(polynomial[i])){
				exponent = polynomial[i] - '0';
				Insert(info, coefficient, exponent);
				mode = 1;
				continue;
			}
			else{
				exponent = 1;
				Insert(info, coefficient, exponent);
				mode = 1;
				continue;
			}
		}
	}
}
