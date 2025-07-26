#include "../include/arr_stack.h"
#include <stdlib.h>
#include <assert.h>

// Constructor and initializer
ArrStack* ArrStack_Constructor() {
	ArrStack *arr_stack = (ArrStack*)malloc(sizeof(ArrStack));
	arr_stack->array = (int*)malloc(sizeof(int) * 10);
	arr_stack->ptr = arr_stack->array;
	arr_stack->resizable = RESIZE_TRUE;
	arr_stack->capacity = 10;
	arr_stack->count = 0;

	return arr_stack;
}

ArrStack* ArrStack_Constructor_Bool(int resizable) {
	ArrStack *arr_stack = (ArrStack*)malloc(sizeof(ArrStack));
	arr_stack->array = (int*)malloc(sizeof(int) * 10);
	arr_stack->ptr = arr_stack->array;
	arr_stack->resizable = resizable;
	arr_stack->capacity = 10;
	arr_stack->count = 0;
	
	return arr_stack;
}

void ArrStack_Initializer(ArrStack *arr_stack) {
	arr_stack->array = (int*)malloc(sizeof(int) * 10);
	arr_stack->ptr = arr_stack->array;
	arr_stack->resizable = RESIZE_TRUE;
	arr_stack->capacity = 10;
	arr_stack->count = 0;
}

void ArrStack_Initializer_Bool(ArrStack *arr_stack, int resizable) {
	arr_stack->array = (int*)malloc(sizeof(int) * 10);
	arr_stack->ptr = arr_stack->array;
	arr_stack->resizable = resizable;
	arr_stack->capacity = 10;
	arr_stack->count = 0;
}

// Stack operations
void ArrStack_Push(ArrStack *stack, int value) {
	assert(NULL != stack);
	assert(NULL != stack->array);
	assert(NULL != stack->ptr);

	if (stack->count == stack->capacity) return;

	*stack->ptr = value;
	++stack->ptr;
	++stack->count;
}

int ArrStack_Pop(ArrStack *stack) {
	assert(NULL != stack);
	assert(NULL != stack->array);
	assert(NULL != stack->ptr);

	if (0 == stack->count) return -1;

	--stack->count;
	--stack->ptr;
	int popped = *stack->ptr;

	return popped;
}

int ArrStack_Peek(ArrStack *stack) {
	assert(NULL != stack);
	assert(NULL != stack->ptr);

	return stack->ptr ? *stack->ptr : 0;
}


int ArrStack_Empty(ArrStack *stack) {
	assert(NULL != stack);
	assert(NULL != stack->ptr);
	assert(stack->count > -1);

	return stack->count > 0 ? 1 : 0;
}

int ArrStack_Search(ArrStack *stack, int value) { // Where is value in stack
	assert(NULL != stack);
	assert(NULL != stack->array);
	assert(NULL != stack->ptr);

	int count = 0;

	for (int i = stack->count - 1; i > 0; i--) {
		if (stack->array[i] == value) return count;
		++count;
	}
	
	return -1;
}

int ArrStack_Get_Size(ArrStack *stack) {
	return stack->count;
}

// Helper functions
void _ArrStack_Resize(ArrStack *stack) {
	assert(NULL != stack);
	assert(NULL != stack->array);
	assert(NULL != stack->ptr);

	if (0 == stack->resizable) return;
	if (stack->count != stack->capacity) return;

	int *array = (int*)malloc(sizeof(int) * stack->capacity * 2);
	// int *array = (int*)calloc(stack->capacity * 2, sizeof(int));
	for (int i = 0; i < stack->count; i++) {
		array[i] = stack->array[i];
	}

	free(stack->array);

	stack->array = array;
	stack->capacity = stack->capacity * 2;
	stack->ptr = stack->ptr + stack->count - 1;
}

