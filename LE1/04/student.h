#ifndef STUDENT_H
#define STUDENT_H

typedef struct _student{
	int id;
	float gpa;
	struct _student* next;
}_student;

void Push(_student** head, int new_id, float new_gpa);
void List_Print(_student* head);
void Compare_GPA(int id_1, int id_2, _student* head);

#endif
