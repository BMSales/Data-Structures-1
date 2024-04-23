#ifndef SORT_H
#define SORT_H

void Array_Create(int** array, int size);
void Array_Copy(int* array_1, int* array_2, int size);
void Array_Fill_Zero(long long* array, int size);
void Array_Fill_Random(int* array, int size);
void Array_Print(int* array, int size);
void Bubblesort(int* array, int size, long long* operations);
void Selectionsort(int* array, int size, long long* operations);
void Insertionsort(int* array, int size, long long* operations);

#endif
