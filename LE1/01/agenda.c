#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void Include(AGENDA **users, int* users_num_ptr){
	(*users_num_ptr) = (*users_num_ptr) + 1;
	(*users) = (AGENDA*)realloc(*users, (*users_num_ptr) * sizeof(AGENDA));
}

void Display(AGENDA *users, int* users_num_ptr){
	for(int i = 0; i < (*users_num_ptr); i++){
		printf("name: %c\nemail: %c\nphone number: %d\n\n", users[i].name[0], users[i].email[0], users[i].phone_num);
	}
	printf("\n\n");
}
