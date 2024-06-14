#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	_queue_info queue;
	queue.size_1 = 0;
	queue.size_2 = 0;
	queue.front_1 = NULL;
	queue.front_2 = NULL;
	queue.rear_1 = NULL;
	queue.rear_2 = NULL;
	void* data_pointer;

	int census_1[] = {21199865, 16373645, 9157540, 7608070, 7039362, 6188463, 5819100, 5456428, 5221801, 4669571, 4112198, 3876380, 3554760, 3251876, 2968806, 2945831, 2813833, 2603607, 2581506, 2450292};
	int census_2[] = {19549649, 14531529, 8239820, 6727050, 6253311, 5892937, 5455403, 5187171, 4037282, 3731131, 2959950, 3192582, 2970328, 2238480, 2538834, 2859644, 2498016, 2492525, 1980140, 2270808};

	for(int i = 0; i < 20; i++){
		data_pointer = &census_1[i];
		Insert_1(&queue, data_pointer);
		data_pointer = &census_2[i];
		Insert_2(&queue, data_pointer);
	}

	printf("2000 census:\n");
	for(int i = 0; i < 20; i++){
		printf("%d\n", *(int*)Remove_1(&queue));
	}
	printf("\n");

	printf("1990 census:\n");
	for(int i = 0; i < 20; i++){
		printf("%d\n", *(int*)Remove_2(&queue));
	}
}
