#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void Include(AGENDA **users, int* users_num_ptr){
	char p_number[11];
	(*users) = (AGENDA*)realloc(*users, ((*users_num_ptr) + 1) * sizeof(AGENDA));

	printf("Name of the user: ");
  	fgets((*users)[(*users_num_ptr)].name, 40, stdin);
	printf("e-Mail of the user: ");
	fgets((*users)[(*users_num_ptr)].email, 40, stdin);
	printf("Phone number the user: ");
	fgets(p_number, 11, stdin);
	(*users)[(*users_num_ptr)].phone_num = strtol(p_number, NULL, 0);
	printf("\n\n");

	(*users_num_ptr) = (*users_num_ptr) + 1;
}

void Display(AGENDA *users, int* users_num_ptr){
	for(int i = 0; i < (*users_num_ptr); i++){
		puts(users[i].name);
		puts(users[i].email);
		printf("%d\n\n", users[i].phone_num);
	}
	printf("\n\n");
}
