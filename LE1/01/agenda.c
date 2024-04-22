#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void Allocate(AGENDA** users, int* users_num_ptr){
	(*users) = (AGENDA*)realloc(*users, (*users_num_ptr) * sizeof(AGENDA));
}

void Include(AGENDA** users, int* users_num_ptr){
	char p_number[11];
	(*users_num_ptr) = (*users_num_ptr) + 1;
	Allocate(users, users_num_ptr);	

	printf("Name of the user: ");
	fgets((*users)[(*users_num_ptr) - 1].name, 40, stdin);

	printf("e-Mail of the user: ");
	fgets((*users)[(*users_num_ptr) - 1].email, 40, stdin);

	printf("Phone number the user: ");
	fgets(p_number, 11, stdin);
	(*users)[(*users_num_ptr) - 1].phone_num = strtol(p_number, NULL, 0);

	printf("\n\n");
}

void Exclude(AGENDA** users, int* users_num_ptr){
	char name[40];

	printf("Search for user: ");
	fgets(name, 40, stdin);

	for(int i = 0; i < (*users_num_ptr); i++){
		if(strcmp((*users)[i].name, name) == 0){
			(*users)[i] = (*users)[(*users_num_ptr) - 1];

			(*users_num_ptr) = (*users_num_ptr) - 1;
			Allocate(users, users_num_ptr);

			printf("User removed\n");
			return;
		}
	}
	printf("User not found\n\n");
}

void Display(AGENDA* users, int* users_num_ptr){
	for(int i = 0; i < (*users_num_ptr); i++){
		printf("User %d\n", i + 1);

		printf("Name: ");
		puts(users[i].name);

		printf("e-Mail: ");
		puts(users[i].email);

		printf("Phone number: %d\n\n\n", users[i].phone_num);
	}
	printf("\n\n");
}
