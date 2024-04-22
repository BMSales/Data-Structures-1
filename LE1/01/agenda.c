#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void Flusher(){
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) {}
}

void Allocate(AGENDA** users, int* users_num_ptr){
	(*users) = (AGENDA*)realloc(*users, (*users_num_ptr) * sizeof(AGENDA));
}

void Swap(AGENDA* user_1, AGENDA* user_2){
	AGENDA swapper;
	swapper = *user_1;
	*user_1 = *user_2;
	*user_2 = swapper;
}

void Quicksort(AGENDA *users, int start, int end){
	if(end - start < 1){
		return;
	}

	int pivot = end;
	int swap_marker = start - 1;

	for(int i = start; i <= end; i++){
		if(users[i].name[0] > users[pivot].name[0]){
			continue;
		}
		else{
			swap_marker++;
			if(i > swap_marker){
				Swap(&users[i], &users[swap_marker]);
			}
		}
	}

	Quicksort(users, start, swap_marker - 1);
	Quicksort(users, swap_marker + 1, end);
}

void Sort(AGENDA* users, int* users_num_ptr){
	Quicksort(users, 0, (*users_num_ptr) - 1);
}

int Search(AGENDA* users, int* users_num_ptr){
	char name[40];

	printf("Name of the user: ");
	fgets(name, 40, stdin);

	for(int i = 0; i < (*users_num_ptr); i++){
		if(strcmp(users[i].name, name) == 0){
			printf("\n--User %d--\n", i + 1);

			printf("Name: ");
			puts(users[i].name);

			printf("email: ");
			puts(users[i].email);

			printf("Phone number: %d\n\n", users[i].phone_num);
			return i;
		}
	}
	printf("\nUser not found\n\n");
	return -1;
}

void Include(AGENDA** users, int* users_num_ptr){
	char p_number[11];
	(*users_num_ptr) = (*users_num_ptr) + 1;
	Allocate(users, users_num_ptr);	

	printf("Name of the user: ");
	fgets((*users)[(*users_num_ptr) - 1].name, 40, stdin);

	printf("email of the user: ");
	fgets((*users)[(*users_num_ptr) - 1].email, 40, stdin);

	printf("Phone number the user: ");
	fgets(p_number, 11, stdin);
	(*users)[(*users_num_ptr) - 1].phone_num = strtol(p_number, NULL, 0);

	Sort((*users), users_num_ptr);
	printf("\nUser added\n\n");
}

void Exclude(AGENDA** users, int* users_num_ptr){
	int index = Search((*users), users_num_ptr);
	char decide[2] ;

	if(index != -1){
		printf("Remove user? [Y/n]\n");
		fgets(decide, 2, stdin);

		if(decide[0] == 'Y'){
			(*users)[index] = (*users)[(*users_num_ptr) - 1];
			(*users_num_ptr) = (*users_num_ptr) - 1;
			Allocate(users, users_num_ptr);

			Sort((*users), users_num_ptr);
			printf("\nUser removed\n\n");
		}
	}
}

void Edit(AGENDA* users, int* users_num_ptr){
	int index = Search(users, users_num_ptr);
	char decide[2] ;
	char p_number[11];

	if(index != -1){
		printf("Edit user? [Y/n]\n");
		fgets(decide, 2, stdin);
		Flusher();

		if(decide[0] == 'Y'){
			printf("New name: ");
			fgets(users[index].name, 40, stdin);
			
			printf("New email: ");
			fgets(users[index].email, 40, stdin);

			printf("New phone number: ");
			fgets(p_number, 11, stdin);
			users[index].phone_num = strtol(p_number, NULL, 0);

			Sort(users, users_num_ptr);
			printf("\nUser edited\n\n");
		}
	}
}

void Display(AGENDA* users, int* users_num_ptr){
	for(int i = 0; i < (*users_num_ptr); i++){
		printf("\n--User %d--\n", i + 1);

		printf("Name: ");
		puts(users[i].name);

		printf("email: ");
		puts(users[i].email);

		printf("Phone number: %d\n", users[i].phone_num);
	}
	printf("\n");
}

void Run(AGENDA* users, int* users_num_ptr){
	char choice[2];

	while(1){
		printf("\nCurrent number of users: %d\n", (*users_num_ptr));
		printf("1 - Include\n");
		printf("2 - Exclude\n");
		printf("3 - Display\n");
		printf("4 - Search\n");
		printf("5 - Edit\n");
		printf("9 - Exit\n\n");
		printf("Select operation: ");
		fgets(choice, 2, stdin);

		if(choice[0] == '1'){
			Flusher();
			Include(&users, users_num_ptr);
		}
		else if(choice[0] == '2'){
			Flusher();
			Exclude(&users, users_num_ptr);
		}
		else if(choice[0] == '3'){
			Flusher();
			Display(users, users_num_ptr);
		}
		else if(choice[0] == '4'){
			Flusher();
			Search(users, users_num_ptr);
		}
		else if(choice[0] == '5'){
			Flusher();
			Edit(users, users_num_ptr);
		}
		else if(choice[0] == '9'){
			Flusher();
			return; 
		}
		else{
			Flusher();
			printf("Invalid option\n\n");
		}
		printf("{press enter}\n");
		Flusher();
	}
}
