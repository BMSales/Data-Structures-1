#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void main(void){
	srand(clock());
	int* array_raw = NULL;
	int* array_sort = NULL;
	long long operations[2] = {0, 0};
	clock_t start, end;
	float seconds;
	int size = 50000;

	Array_Create(&array_raw, size);
	Array_Create(&array_sort, size);

	Array_Fill_Random(array_raw, size);
	Array_Copy(array_raw, array_sort, size);

	printf("bubble sort\n");
	start = clock();
	Bubblesort(array_sort, size, operations);
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("time in milliseconds: %f\n", 1000 * seconds);
	printf("number of comparisons: %lld\n", operations[0]);
	printf("number of attributions: %lld\n\n", operations[1]);

	Array_Copy(array_raw, array_sort, size);
	Array_Fill_Zero(operations, 2);

	printf("selection sort\n");
	start = clock();
	Selectionsort(array_sort, size, operations);
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("time in milliseconds: %f\n", 1000 * seconds);
	printf("number of comparisons: %lld\n", operations[0]);
	printf("number of attributions: %lld\n\n", operations[1]);

	Array_Copy(array_raw, array_sort, size);
	Array_Fill_Zero(operations, 2);

	printf("insertion sort\n");
	start = clock();
	Insertionsort(array_sort, size, operations);
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("time in milliseconds: %f\n", 1000 * seconds);
	printf("number of comparisons: %lld\n", operations[0]);
	printf("number of attributions: %lld\n\n", operations[1]);
}
