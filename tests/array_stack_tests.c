#include "../include/arr_stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void test_pointer(void *ptr);
void print_list(ArrStack *ptr);

int main() {
	// Create helper variables
	int pop_value = 0;
	int peek_value = 0;
	int truthy = 0;
	ArrStack *arr_stack_ptr = NULL;
	ArrStack arr_stack_var;

	printf("Array stack tests\n\n");


	printf("Array stack constructor and initializer tests\n");

	printf("Constructor\n");
	arr_stack_ptr = ArrStack_Constructor();
	test_pointer(arr_stack_ptr);
	free(arr_stack_ptr);

	printf("Constructor boolean\n");
	arr_stack_ptr = ArrStack_Constructor_Bool(1);
	test_pointer(arr_stack_ptr);

	printf("Initializer\n");
	ArrStack_Initializer(&arr_stack_var);

	ArrStack_Initializer_Bool(&arr_stack_var, 1);
	

	printf("\nStack operations\n");

	printf("Push\n");
	for (int i = 0; i < 5; i++) {
		printf("\tPushing %d\n", i);
		ArrStack_Push(arr_stack_ptr, i);
	}
	print_list(arr_stack_ptr);

	printf("Push past current allocation size\n");
	for (int i = 0; i < 11; i++) {
		printf("\tPushing %d\n", i);
		ArrStack_Push(arr_stack_ptr, i);
	}

	printf("Pop\n");
	ArrStack_Pop(arr_stack_ptr);

	printf("Peek\n");
	peek_value = ArrStack_Peek(arr_stack_ptr);
	printf("Value peeked: %d\n", peek_value);
	
	printf("Empty\n");
	truthy = ArrStack_Empty(arr_stack_ptr);
	if (truthy != 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	printf("Search\n");
	printf("Where is 0?\n");
	ArrStack_Search(arr_stack_ptr, 0);

	printf("Get Size\n");
	ArrStack_Get_Size(arr_stack_ptr);
	
	_ArrStack_Resize(arr_stack_ptr);

	return EXIT_SUCCESS;
}

void test_pointer(void *ptr) {
	printf("Pointer null?\n");
	printf(NULL != ptr ? "Yes\n" : "No\n");
}

void print_list(ArrStack *ptr) {
	for (int i = 0; i < ptr->count; i++) {
		printf("%d ", ptr->array[i]);
	}
	printf("\n");
}
