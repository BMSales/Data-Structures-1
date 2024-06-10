#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue{
	void* data;
	struct _queue* next;
}_queue;

typedef struct _queue_info{
	int size;
	struct _queue* front;
	struct _queue* rear;
}_queue_info;

void Push(_queue_info* info, void* new_data);
void* Pop(_queue_info* info);
void* Top_Value(_queue_info* info);
int Stack_Size(_queue_info* info);

#endif
