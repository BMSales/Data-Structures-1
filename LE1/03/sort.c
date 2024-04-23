#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void Array_Create(int** array, int size){
	(*array) = (int*)malloc(size * sizeof(int));
}

void Array_Copy(int* array_1, int* array_2, int size){
	for(int i = 0; i < size; i++){
		array_2[i] = array_1[i];
	}
}

void Array_Fill_Zero(long long* array, int size){
	for(int i = 0; i < size; i++){
		array[i] = 0;
	}
}

void Array_Fill_Random(int* array, int size){
	for(int i = 0; i < size; i++){
		array[i] = rand() % 5000000;
	}
}

void Array_Print(int* array, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}

	printf("\n\n");
}

void Swap(int* a, int* b){
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
} 

void Bubblesort(int* array, int size, long long* operations){
	int end = size;
	int cont = 0;

	do{
		operations[1]++;
		cont = 0;
		for(int i = 0; i < end - 1; i++){
			operations[0]++;
			if(array[i] > array[i + 1]){
				operations[1] = operations[1] + 3;
				Swap(&array[i], &array[i + 1]);
				cont = 1;
			}
		}
		operations[0]++;
	}while(cont != 0);
}

void Selectionsort(int* array, int size, long long* operations){
	int smallest;

	for(int i = 0; i < size - 1; i++){
		operations[1]++;
		smallest = i;	
		for(int j = i + 1; j < size; j++){
			operations[0]++;
			if(array[j] < array[smallest]){
				operations[1]++;
				smallest = j;
			}
		}
		operations[0]++;
		if(i != smallest){
			operations[1] = operations[1] + 3;
			Swap(&array[i], &array[smallest]);
		}
	}
}

void Insertionsort(int* array, int size, long long* operations){
	int current, j;

	for(int i = 1; i < size; i++){
		operations[1]++;
		current = array[i];
		for(j = i; (j > 0) && (current < array[j - 1]); j--){
			operations[0]++;
			operations[1]++;
			array[j] = array[j - 1];
		}
		operations[1]++;
		array[j] = current;
	}
}
