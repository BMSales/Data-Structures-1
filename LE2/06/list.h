#ifndef LIST_H
#define LIST_H

typedef struct _list{
	int coefficient;
	int exponent;
	struct _list* next;
}_list;

typedef struct _list_info{
	int size;
	struct _list* head;
}_list_info;

void Insert(_list_info* info, int coefficient, int exponent);
_list Remove(_list_info* info);
void Parser(_list_info* info, char* polynomial, int size);

#endif
