#include "../include/singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {
	printf("Singly Linked List Tests\n");

	SinglyLinkedList sll;
	Singly_Initializer(sll);

	// Insertion tests
	// Append
	unsigned char success_count = 0;
	printf("Append tests\n");
	printf("Inserting 1\n");
	Singly_Append(&sll, 1);
	++success_count;

	printf("Inserting 2\n");
	Singly_Append(&sll, 2);
	++success_count;

	printf("Inserting 3\n");
	Singly_Append(&sll, 3);
	++success_count;

	SinglyNode *node = sll.head;
	int i = 1;
	while (node != NULL) {
		if (node->value == i) ++success_count;
		++i;
	}

	// Prepend

	// Insert After

	return EXIT_SUCCESS;
}
