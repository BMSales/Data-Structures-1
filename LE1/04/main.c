#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "student.h"

void main(void){
	srand(clock());
	_student* head = NULL;
	
	for(int i = 0; i < 10; i++){
		Push(&head, i + 1, (rand() % 101)/10.0f);
	}

	List_Print(head);
	Compare_GPA(1, 4, head);
	Compare_GPA(10, 5, head);
}
