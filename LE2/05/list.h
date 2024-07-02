#ifndef LIST_H
#define LIST_h

typedef struct _list{
	void* data;
	struct _list* next;
}_list;

typedef struct _list_info{
	int size;
	struct _list* head;
}_list_info;

void Insert(_list_info* info, void* new_data);
void* Remove(_list_info* info);

#endif
