#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void Push(_student** head, int new_id, float new_gpa){
	_student* new_node;
	new_node = (_student*)malloc(sizeof(_student));

	new_node->id = new_id;
	new_node->gpa = new_gpa;
	new_node->next = (*head);
	(*head) = new_node;
}

void List_Print(_student* head){
	_student* current = head;
	while(current != NULL){
		printf("Student ID: %d\n", current->id);
		printf("Student GPA: %.1f\n\n", current->gpa);
		current = current->next;
	}
	printf("\n");
}

_student* Search_ID(int id, _student* head){
	_student* current = head;
	while(current != NULL){
		if(current->id == id){
			return current;
		}
		current = current->next;
	}
	printf("Student ID %d not found\n", id);
	return NULL;
}

void* Compare_Larger(void* element_1, void* element_2, int (*Is_Larger_Pointer)(void*, void*)){
	if((*Is_Larger_Pointer)(element_1, element_2)){
		return element_1;
	}
	else{
		return element_2;
	}
}

int Is_Larger(void* element_1, void* element_2){
	if(*(float*)element_1 > *(float*)element_2){
		return 1;
	}
	else{
		return 0;
	}
}

void Compare_GPA(int id_1, int id_2, _student* head){
	_student* student_1;
	_student* student_2;
	student_1 = Search_ID(id_1, head);
	student_2 = Search_ID(id_2, head);

	if(student_1 != NULL && student_2 != NULL){
		if(Is_Larger(&student_1->gpa, &student_2->gpa)){
			printf("Student %d, GPA of %.1f > Student %d, GPA of %.1f\n", student_1->id, student_1->gpa, student_2->id, student_2->gpa);
		}
		else{
			printf("Student %d, GPA of %.1f !> Student %d, GPA of %.1f\n", student_1->id, student_1->gpa, student_2->id, student_2->gpa);
		}
	}
}
