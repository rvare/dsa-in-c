#include "../include/singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define APPENDING_COUNT 3
#define PRENDING_COUNT 5

unsigned char success_count = 0;

void check_elements(SinglyLinkedList* sll, int start);

int main() {
	printf("Singly Linked List Tests\n");

	SinglyLinkedList sll;
	Singly_Initializer(&sll);

	// Insertion tests
	// Append
	printf("Append tests\n");
	printf("Appending 1\n");
	Singly_Append(&sll, 1);

	printf("Appending 2\n");
	Singly_Append(&sll, 2);

	printf("Appending 3\n");
	Singly_Append(&sll, 3);
	
	check_elements(&sll, 1);
	printf("%d out of %d appending successful\n", success_count, APPENDING_COUNT);

	// Prepend
	success_count = 0;
	printf("Prepend -1\n");
	Singly_Prepend(&sll, -1);

	printf("Prepend -2\n");
	Singly_Prepend(&sll, -2);

	check_elements(&sll, -2);
	printf("%d out of %d prepending successful\n", success_count,PRENDING_COUNT);

	// Insert After
	success_count = 0;
	printf("Inserting 0 after -1 (index 1)\n");
	Singly_InsertAfter(&sll, 1, 0);

	check_elements(&sll, -2);
	printf("%d out of %d, inserting successful\n", success_count, 6);

	return EXIT_SUCCESS;
}

// Functions
void check_elements(SinglyLinkedList* sll, int start) {
	assert(sll->head != NULL);
	SinglyNode *node = sll->head;
	int i = start;
	while (node != NULL) {
		if (node->value == i) ++success_count;
		node = node->next;
		++i;
	}
}
