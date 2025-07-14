#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_queue(Queue *que);

int main() {
	printf("Queue tests\n");


	printf("Create queue\n");
	Queue *queue = Queue_Constructor();
	printf("head: %d\n", queue->head);
	printf("tail: %d\n", queue->tail);
	printf("size: %d\n", queue->size);

	printf("Enqueue\n");
	for (int i = 0; i < 5; i++) {
		Enqueue(queue, i);
	}

	printf("Is it empty?\n");
	int boolean = Empty(queue);
	if (boolean == 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	print_queue(queue);


	printf("Get size\n");
	printf("Size: %d\n", Queue_Get_Size(queue));


	int index = -1;
	printf("Search\n");
	printf("Where is 0?\n");
	index = Search(queue, 0);
	printf("At index %d\n", index);
	printf("Where is 4?\n");
	index = Search(queue, 4);
	printf("At index %d\n", index);
	printf("Where is 1?\n");
	index = Search(queue, 1);
	printf("At index %d\n", index);
	printf("Where is 2?\n");
	index = Search(queue, 2);
	printf("At index %d\n", index);
	printf("Where is 3?\n");
	index = Search(queue, 3);
	printf("At index %d\n", index);


	printf("Peek\n");
	printf("Peek via node\n");
	QueueNode *curr = Peek(queue);
	printf("%d\n", QueueNode_Get_Value(curr));
	printf("Peek via value\n");
	int value = Peek_Value(queue);
	printf("%d\n", value);


	printf("Dequeue\n");
	curr = Dequeue(queue);
	while (curr) {
		printf("%d ", curr->value);
		free(curr);
		curr = Dequeue(queue);
	}
	printf("\n");


	printf("Is it empty?\n");
	boolean = Empty(queue);
	if (boolean == 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}

	return EXIT_SUCCESS;
}

void print_queue(Queue *que) {
	QueueNode *curr = que->head;
	for (int i = 0; i < que->size; i++) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}
