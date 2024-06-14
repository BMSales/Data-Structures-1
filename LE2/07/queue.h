#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue{
	void* data;
	struct _queue* next;
}_queue;

typedef struct _queue_info{
	int size_1;
	int size_2;
	struct _queue* front_1;
	struct _queue* front_2;
	struct _queue* rear_1;
	struct _queue* rear_2;
}_queue_info;

void Insert_1(_queue_info* info, void* new_data);
void Insert_2(_queue_info* info, void* new_data);
void* Remove_1(_queue_info* info);
void* Remove_2(_queue_info* info);
#endif
