#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
	char name[40];
	char email[40];
	int phone_num;
}AGENDA;

void Run(AGENDA* users, int* users_num_ptr);

/*void Include(AGENDA** users, int* users_num_ptr);
void Exclude(AGENDA** users, int* users_num_ptr);
void Display(AGENDA* users, int* users_num_ptr); 
int Search(AGENDA* users, int* users_num_ptr);
void Change(AGENDA* users, int* users_num_ptr);*/

#endif
