#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void main(void){
	AGENDA *users;
	int users_num = 0;
	int* users_num_ptr = &users_num;

	users = (AGENDA*)malloc(sizeof(AGENDA));

	Include(&users, users_num_ptr);
	Display(users, users_num_ptr);
	Include(&users, users_num_ptr);
	Display(users, users_num_ptr);

	Exclude(&users, users_num_ptr);
	Display(users, users_num_ptr);
}
