#include "../include/stack.h"
#include <stdlib.h>
#include <assert.h>

// Constructor and initializer
Stack* Stack_Construct() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
}

void Stack_Initializer(Stack* stack) {
	stack->top = NULL;
	stack->size = 0;
}

// Stack operations
void Push(Stack* stack, int value) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->next = NULL;
	node->value = value;

	if (NULL == stack->top) {
		stack->top = node;
		++stack->size;
	}
	else {
		node->next = stack->top;
		stack->top = node;
		++stack->size;
	}
}

StackNode* Pop(Stack* stack) {
	if (NULL == stack->top) return NULL;

	StackNode* node = stack->top;
	stack->top = stack->top->next;
	node->next = NULL;
	--stack->size;
	return node;
}

StackNode* Peek(Stack* stack) {
	return NULL != stack->top ? stack->top : NULL;
}

int Peek_Value(Stack* stack) {
	return NULL != stack->top ? stack->top->value : 0;
}

int Emtpy(Stack* stack) {
	return NULL == stack->top && 0 == stack->size ? 1 : 0;
}

int Search(Stack* stack, int value) {
	int count = 0;
	StackNode* curr = stack->top;
	while(NULL != curr) {
		if (curr->value == value) {
			return count;
		}
		else {
			++count;
		}
		curr = curr->next;
	}

	return -1;
}

int Get_Size(Stack* stack) {
	return stack->size;
}
