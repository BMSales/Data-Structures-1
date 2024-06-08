#ifndef STACK_H
#define STACK_H

typedef struct _stack{
	void* data;
	struct _stack* next;
}_stack;

typedef struct _stack_info{
	int size;
	struct _stack* head;
}_stack_info;

void Push(_stack_info* info, void* new_data);
void* Pop(_stack_info* info);
void* Top_Value(_stack_info* info);
int Stack_Size(_stack_info* info);

#endif
