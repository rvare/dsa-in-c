#include "../include/stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_stack(Stack* stack);

int main() {
	printf("Stack tests\n");

	printf("Stack constructions\n");
	Stack* stack = Stack_Construct();
	if (NULL == stack->top && 0 == stack->size) {
		printf("Constructed properly\n\n");
	}
	else {
		printf("Not constructed properly\n\n");
	}

	printf("Stack variable initializer\n");
	Stack var_stack;
	Stack_Initializer(&var_stack);
	if (NULL == stack->top && 0 == stack->size) {
		printf("Initialized properly\n\n");
	}
	else {
		printf("Not initialized properly\n\n");
	}

	printf("Push tests\n");
	for (int i=0; i<5; i++) {
		Push(stack, i);
	}
	print_stack(stack);
	printf("\n");

	printf("Peeking values\n");
	printf("Peeking via returning a node\n");
	StackNode* node = Peek(stack);
	printf("Does top equal 4?\n");
	if (4 == node->value) {
		printf("Yes\n\n");
	}
	else {
		printf("No\n\n");
	}

	printf("Peeking by value\n");
	int value = Peek_Value(stack);
	printf("Does top equal 4?\n");
	if (4 == value) {
		printf("Yes\n\n");
	}
	else {
		printf("No\n\n");
	}

	node = NULL;
	printf("Popping values\n");
	for (int i=4; i != -1 && NULL != stack->top; i--) {
		node = Pop(stack);
		printf("%d ", node->value);
		free(node);
		node = NULL;
	}

	printf("Is it emtpy?\n");
	if (Emtpy(stack)) {
		printf("Yes\n\n");
	}
	else {
		printf("No\n\n");
	}

	printf("Search for values\n");
	printf("Repopulate stack\n");
	for (int i=0; i<5; i++) {
		Push(stack, i);
	}
	printf("Is value 4 at 0?\n");
	int index = Search(stack, 4);
	-1 != index ? printf("Yes\n") : printf("No\n");
	printf("Is value 3 at 1?\n");
	index = Search(stack, 3);
	-1 != index ? printf("Yes\n") : printf("No\n");
	printf("Is value 2 at 1?\n");
	index = Search(stack, 2);
	-1 != index ? printf("Yes\n") : printf("No\n");
	printf("Is value 1 at 3?\n");
	index = Search(stack, 1);
	-1 != index ? printf("Yes\n") : printf("No\n");
	printf("Is value 0 at 4?\n");
	index = Search(stack, 0);
	-1 != index ? printf("Yes\n") : printf("No\n");
	printf("Is value 5 in stack?\n");
	index = Search(stack, 5);
	-1 != index ? printf("Yes\n") : printf("No\n");

	return EXIT_SUCCESS;
}

void print_stack(Stack* stack) {
	StackNode* node = stack->top;
	while(NULL != node) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}
