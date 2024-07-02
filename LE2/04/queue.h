#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue{
	void* data;
	int data_type;
	struct _queue* next;
}_queue;

typedef struct _queue_info{
	int size;
	struct _queue* front;
	struct _queue* rear;
}_queue_info;

void Insert(_queue_info* info, void* new_data, int data_type);
_queue Remove(_queue_info* info);
void* Front_Value(_queue_info* info);
int Queue_Size(_queue_info* info);
int Prefix_Run(_queue_info* info);

#endif
