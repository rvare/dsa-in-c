#include "../include/queue.h"
#include <stdlib.h>
#include <assert.h>

// Constructor an initializers
Queue* Queue_Constructor() {
	Queue *que = (Queue*)malloc(sizeof(Queue));
	que->head = NULL;
	que->tail = NULL;
	que->size = 0;
	return que;
}

void Queue_Initializer(Queue *que) {
	que->head = NULL;
	que->tail = NULL;
	que->size = 0;
}

// Getters
int Queue_Get_Size(Queue *que) {
	return que->size;
}

int QueueNode_Get_Value(QueueNode *que_node) {
	return que_node->value;
}

// Operations
void Enqueue(Queue *que, int value) {
	assert(NULL != que);
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node->value = value;
	node->next = NULL;

	if (NULL == que->head && NULL == que->tail) {
		que->head = node;
		que->tail = node;
	}
	else {
		que->tail->next = node;
		que->tail = node;
	}

	++que->size;
}

QueueNode* Dequeue (Queue *que) {
	assert(NULL != que);
	assert(NULL != que->head);
	if (NULL == que) return NULL;

	QueueNode* node = que->head;
	que->head = que->head->next;
	node->next = NULL;
	return node;
}

QueueNode* Peek(Queue *que) {
	assert(NULL != que);
	assert(NULL != que->head);

	return que->head;
}

int Peek_Value(Queue *que) {
	assert(NULL != que);
	assert(NULL != que->head);

	return que->head->value;
}

int Empty(Queue *que) {
	return NULL == que ? 1 : 0;
}

int Search(Queue *que, int value) {
	assert(NULL != que);
	assert(NULL != que->head);

	QueueNode *curr = que->head;
	int count = 0;
	while (curr)  {
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

