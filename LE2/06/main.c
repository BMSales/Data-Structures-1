#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	char polynomial_1[] = "5x^4+6x^3+7";
	char polynomial_2[] = "2x^3-7x^2+3x";
	_list aux_node;
	_list_info list_1, list_2;

	list_1.size = 0;
	list_1.head = NULL;
	list_2.size = 0;
	list_2.head = NULL;

	Parser(&list_1, polynomial_1, 11);
	Parser(&list_2, polynomial_2, 12);

	while(list_1.size != 0){
		aux_node = Remove(&list_1);
		Insert(&list_2, aux_node.coefficient, aux_node.exponent);
	}
	while(list_2.size != 0){
		aux_node = Remove(&list_2);
		printf("coe: %d\n", aux_node.coefficient);
		printf("exp: %d\n\n", aux_node.exponent);
	}
}
