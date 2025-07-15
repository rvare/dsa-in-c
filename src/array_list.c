#include "../include/array_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Constructors and initializers
ArrayList* Arr_Constructor() {
	ArrayList *arr_list = (ArrayList*)malloc(sizeof(ArrayList));
	arr_list->array = (int*)malloc(sizeof(int)*10);
	arr_list->ptr = arr_list->array;
	arr_list->capacity = 10;
	arr_list->size = 0;
	return arr_list;
}

void Arr_Initializer(ArrayList *arr_list) {
	arr_list->array = (int*)malloc(sizeof(int)*10);
	arr_list->ptr = arr_list->array;
	arr_list->capacity = 10;
	arr_list->size = 0;
}

// Getters
int Arr_Get_Element(ArrayList *arr_list, int index) { // Negative indexing allowed
	assert(NULL != arr_list);
	if (index < 0) {
		return arr_list->array[arr_list->size + index];
	}

	if (index <= arr_list->size-1) {
		return arr_list->array[index];
	}
	return -1;
}

int Arr_Get_Size(ArrayList *arr_list) {
	assert(NULL != arr_list);
	return arr_list->size;
}

int Arr_Get_Capacity(ArrayList *arr_list) {
	assert(NULL != arr_list);
	return arr_list->capacity;
}


// Operations
// Insertion
void Arr_Append(ArrayList *arr_list, int value) {
	assert(NULL != arr_list);
	assert(NULL != arr_list->array);
	assert(NULL != arr_list->ptr);

	if (arr_list->size == arr_list->capacity) {
		return;
	}

	*arr_list->ptr = value;
	if (arr_list->size != arr_list->capacity) {
		++arr_list->ptr;
	}
}

void Arr_Prepend(ArrayList *arr_list, int value) {
}

void Arr_Insert_After(ArrayList *arr_list, int value, int index) {
	assert(NULL != arr_list);
	assert(NULL != arr_list->array);
	assert(NULL != arr_list->ptr);
}

void Arr_Set_Element(ArrayList *arr_list, int value, int index) {
	assert(NULL != arr_list);
	assert(NULL != arr_list->array);
	assert(NULL != arr_list->ptr);

	if (index <= arr_list->size) {
		arr_list->array[index] = value;
	}
}

void Arr_Clear_List(ArrayList *arr_list) {
	if (NULL == arr_list) return;
	if (NULL == arr_list->array) return;
	if (0 == arr_list->size) return;

	free(arr_list->array);
	Arr_Initializer(arr_list);
}

void Arr_Delete_List(ArrayList *arr_list) {
	if (NULL == arr_list) return;
	if (NULL == arr_list->array) return;
	if (0 == arr_list->size) return;

	free(arr_list->array);
	arr_list->array = NULL;
	arr_list->ptr = NULL;

	free(arr_list);
	arr_list = NULL;
}

int Arr_IsEmpty(ArrayList *arr_list) {
	return 0 == arr_list->size ? 1 : 0;
}


// Searching
int Arr_Get_IndexOf(ArrayList *arr_list, int value) {
	for (int i = 0; i < arr_list->size; i++) {
		if (arr_list->array[i] == value) {
			return i;
		}
	}

	return -1;
}

int Arr_Get_LastIndexOf(ArrayList *arr_list, int value) {
	assert(NULL != arr_list);
	assert(NULL != arr_list->array);
	assert(NULL != arr_list->ptr);

	for (int i = arr_list->size-1; i != -1; i--) {
		if (arr_list->array[i] == value) {
			return i;
		}
	}

	return -1;
}

// Removal and Deletion
void Arr_Remove_Head(ArrayList *arr_list) {
}

void Arr_Remove_Tail(ArrayList *arr_list) {
}

void Arr_Remove_Element(ArrayList *arr_list, int index) {
}

// Conversions
ArrayList* Arr_Reverse(ArrayList *arr_list) {
	ArrayList *new_arr_list = Arr_Constructor();
	for (int i = arr_list->size-1; i != -1; i--) {
		Arr_Append(new_arr_list, arr_list->array[i]);
	}

	return new_arr_list;
}

ArrayList* Arr_Slice(ArrayList *arr_list, int start, int end) {
	ArrayList *new_arr_list = (ArrayList*)malloc(sizeof(ArrayList));
	Arr_Initializer(new_arr_list);
	for (int i = start; i <= end; i++) {
		Arr_Append(new_arr_list, arr_list->array[i]);
	}

	return new_arr_list;
}

// Helpers
void _Resize_Array(ArrayList *arr_list) {
	int* arr= (int*)malloc(sizeof(int)*(arr_list->capacity*2));
	for (int i = 0; i < arr_list->size; i++) {
		arr[i] = arr_list->array[i];
	}

	free(arr_list->array);
	arr_list->array = arr;
	arr_list->ptr = arr_list->array + arr_list->size;
}

