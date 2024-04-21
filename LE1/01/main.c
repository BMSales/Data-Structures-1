#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void main(void){
	AGENDA *users;
	int users_num = 1;
	int* users_num_ptr = &users_num;

	users = (AGENDA*)malloc(sizeof(AGENDA));

	users[0].name[0] = 'N';
	users[0].email[0] = 'n';
	users[0].phone_num = 1;
	Display(users, users_num_ptr);
	
	Include(&users, users_num_ptr);

	users[1].name[0] = 'L';
	users[1].email[0] = 'l';
	users[1].phone_num = 2;
	Display(users, users_num_ptr);
}
